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
	static const int NumMods = 3;
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
const unsigned PolynomialHash::Mods[PolynomialHash::NumMods] = { 2147483647U, 2147483629U, 2147483587U };
namespace std {
template<> struct hash<PolynomialHash::Hash> {
	size_t operator()(const PolynomialHash::Hash &h) const {
		return h.hs[0];
	}
};
}

int main() {
	typedef PolynomialHash::Hash Hash;
	int n;
	while(~scanf("%d", &n)) {
		char s[200001];
		scanf("%s", s);
		PolynomialHash ph;
		ph.precomputePowerTable(n + 1);
		vector<Hash> pre(n + 1);
		rep(i, n) pre[i + 1] = pre[i] * ph.seed + Hash(s[i]);
		auto hash = [&](int i, int j) {
			assert(i <= j);
			return pre[j] - pre[i] * ph.powh[j - i];
		};
		vector<unordered_map<Hash, vector<pair<int,int>>>> levels(n + 1);
		rep(i, n)
			levels[1][hash(i, i + 1)].emplace_back(i, i + 1);
		int ans = 0;
		rer(lv, 1, n) {
			for(auto &p : levels[lv]) {
				amax(ans, lv);
				const vpii &v = p.second;
				if((int)v.size() <= 1) continue;
				auto add = [&](int k, int run) {
					int i = v[k - run].first;
					int j = v[k].second;
					levels[lv + run][hash(i, j)].emplace_back(i, j);
				};
				Hash prevh = hash(v[0].second, v[1].first);
				int run = 1;
				reu(i, 1, v.size() - 1) {
					Hash h = hash(v[i].second, v[i + 1].first);
					if(prevh == h) {
						++ run;
					} else {
						add(i, run);
						run = 1;
					}
					prevh = h;
				}
				add((int)v.size() - 1, run);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}