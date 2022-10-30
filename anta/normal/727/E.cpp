#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct PolynomialHash {
	static const int NumMods = 5;
	static const unsigned Mods[NumMods];
	typedef unsigned long long ull;
	struct Hash {
		unsigned hs[NumMods];
		Hash() { for(int k = 0; k < NumMods; ++ k) hs[k] = 0; }
		explicit Hash(unsigned x) {
			if(x < Mods[NumMods - 1]) {
				for(int k = 0; k < NumMods; ++ k) hs[k] = x;
			} else {
				for(int k = 0; k < NumMods; ++ k) hs[k] = x % Mods[k];
			}
		}
		bool operator==(const Hash &that) const {
			bool res = true;
			for(int k = 0; k < NumMods; ++ k)
				res &= hs[k] == that.hs[k];
			return res;
		}
		bool operator<(const Hash &that) const {
			for(int k = 0; k < NumMods; ++ k)
				if(hs[k] != that.hs[k])
					return hs[k] < that.hs[k];
			return false;
		}
		Hash &operator+=(const Hash &that) {
			for(int k = 0; k < NumMods; ++ k)
				if((hs[k] += that.hs[k]) >= Mods[k])
					hs[k] -= Mods[k];
			return *this;
		}
		Hash operator+(const Hash &that) const { return Hash(*this) += that; }
		Hash &operator-=(const Hash &that) {
			for(int k = 0; k < NumMods; ++ k)
				if((hs[k] += Mods[k] - that.hs[k]) >= Mods[k])
					hs[k] -= Mods[k];
			return *this;
		}
		Hash operator-(const Hash &that) const { return Hash(*this) -= that; }
		Hash operator*(const Hash &that) const {
			Hash res;
			for(int k = 0; k < NumMods; ++ k)
				res.hs[k] = (ull)hs[k] * that.hs[k] % Mods[k];
			return res;
		}
	};

	Hash seed;
	std::vector<Hash> powh;

	PolynomialHash() {
		random_device rd;
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x;
			do x = rd(); while(x < 65536 || x >= Mods[k]);
			seed.hs[k] = x;
		}
	}

	void precomputePowerTable(int newSize) {
		int oldSize = (int)powh.size();
		if(oldSize >= newSize) return;
		powh.resize(newSize);
		if(oldSize == 0)
			powh[0] = Hash(1);
		for(int i = std::max(1, oldSize); i < newSize; i ++)
			powh[i] = powh[i - 1] * seed;
	}
};
const unsigned PolynomialHash::Mods[PolynomialHash::NumMods] = { 2147483647U, 2147483629U, 2147483587U, 2147483579U, 2147483563U };
namespace std {
template<> struct hash<PolynomialHash::Hash> {
	size_t operator()(const PolynomialHash::Hash &h) const {
		return h.hs[0];
	}
};
}

struct SubstringHash {
	using Hash = PolynomialHash::Hash;
	PolynomialHash &ph;
	std::vector<Hash> preh;

	SubstringHash(PolynomialHash &ph) : ph(ph) {}

	template<typename V>
	void init(const V &v, int n) {
		ph.precomputePowerTable(n + 1);
		preh.resize(n + 1);
		preh[0] = Hash();
		for(int i = 0; i < n; i ++)
			preh[i + 1] = preh[i] * ph.seed + Hash(v[i]);
	}
	Hash hash(int j) const {
		return preh[j];
	}
	Hash hash(int i, int j) const {
		if(i == 0) return hash(j);
		return preh[j] - preh[i] * ph.powh[j - i];
	}
};

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		unique_ptr<char[]> S(new char[n * k + k + 1]);
		scanf("%s", S.get());
		rep(i, k)
			S[n * k + i] = S[i];
		S[n * k + k] = 0;
		int g;
		scanf("%d", &g);
		PolynomialHash ph;
		using Hash = PolynomialHash::Hash;
		unordered_map<Hash, int> gameMap;
		gameMap.reserve(g);
		rep(i, g) {
			char buf[100001];
			scanf("%s", buf);
			Hash h;
			rep(j, k)
				h = h * ph.seed + Hash(buf[j]);
			gameMap[h] = i;
		}
		SubstringHash sh(ph);
		sh.init(S, n * k + k);
		vector<int> ans;
		ans.reserve(n);
		vector<bool> used(g);
		rep(j, k) {
			for(int i = j; i < n * k; i += k) {
				auto it = gameMap.find(sh.hash(i, i + k));
				if(it == gameMap.end() || used[it->second]) {
					for(int a : ans)
						used[a] = false;
					ans.clear();
					break;
				}
				ans.push_back(it->second);
				used[it->second] = true;
			}
			if(!ans.empty())
				break;
		}
		if(ans.empty()) {
			puts("NO");
		} else {
			puts("YES");
			for(int i = 0; i < (int)ans.size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%d", ans[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}