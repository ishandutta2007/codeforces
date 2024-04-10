#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

unsigned long long readTimeStampCounter() {
	unsigned a = 123456789, b = 987654321;
#ifdef __GNUC__
	asm (
		"rdtsc;\n\t"
		: "=d" (a), "=a" (b)
	);
#else
	__asm {
		rdtsc;
		mov a, edx;
		mov b, eax;
	};
#endif
	return (unsigned long long)a << 32 | b;
}
unsigned xor128() {
	static unsigned x = 123456789, y = 362436069,
		z = (unsigned)(readTimeStampCounter() >> 32), w = (unsigned)readTimeStampCounter();
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}
 
 
struct PolynomialHashKD {
	static const int D = 1;
	static const int NumMods = 3;
	static const unsigned Mods[NumMods];
	typedef unsigned long long ull;
	struct Hash {
		unsigned hs[NumMods];
		Hash() { for(int k = 0; k < NumMods; ++ k) hs[k] = 0; }
		Hash(unsigned x) {
			if(x < Mods[NumMods-1]) {
				for(int k = 0; k < NumMods; ++ k) hs[k] = x;
			}else {
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
		Hash operator*(const Hash &that) const {
			Hash res;
			for(int k = 0; k < NumMods; ++ k)
				res.hs[k] = (ull)hs[k] * that.hs[k] % Mods[k];
			return res;
		}
	};
	static Hash seeds[D];
	static std::vector<Hash> powh[D];

	static void initSeeds() {
		for(int d = 0; d < D; ++ d)
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x;
			do x = xor128(); while(x == 0 || x >= Mods[k]);
			seeds[d].hs[k] = x;
		}
	}
	static void precomputePowerTable(int newSize) {
		if((int)powh[0].size() >= newSize) return;
		if(seeds[0].hs[0] == 0) initSeeds();
		for(int d = 0; d < D; ++ d) {
			int oldSize = powh[d].size();
			powh[d].resize(newSize);
			if(oldSize == 0)
				for(int k = 0; k < NumMods; ++ k) powh[d][0].hs[k] = 1;
			for(int i = std::max(1, oldSize); i < newSize; i ++) for(int k = 0; k < NumMods; ++ k)
				powh[d][i].hs[k] = (ull)powh[d][i-1].hs[k] * seeds[d].hs[k] % Mods[k];
		}
	}
};
const unsigned PolynomialHashKD::Mods[PolynomialHashKD::NumMods] = { 2147483647U, 2147483629U, 2147483587U };
PolynomialHashKD::Hash PolynomialHashKD::seeds[PolynomialHashKD::D];
std::vector<PolynomialHashKD::Hash> PolynomialHashKD::powh[PolynomialHashKD::D];

typedef PolynomialHashKD PolyH;
PolyH polyh;

typedef char Val;
struct Sum {
	int len;
	PolyH::Hash h;
	Sum(): len(0), h() { }
	Sum(const Val &val, int pos): len(1), h(val) { }
	Sum &operator+=(const Sum &that) {
		h = h * PolyH::powh[0][that.len] + that.h;
		len += that.len;
		return *this;
	}
	Sum operator+(const Sum &that) const { return Sum(*this) += that; }
};

vector<vector<PolyH::Hash>> fillHs;
struct Add {
	bool fill;
	Val fillval;
	Add(): fill(false), fillval(0) { }
	Add &operator+=(const Add &that) {
		if(that.fill)
			*this = that;
		return *this;
	}
	void addToVal(Val &val, int pos) const {
		if(fill)
			val = fillval;
	}
	void addToSum(Sum &sum, int left, int right) const {
		if(fill)
			sum.h = fillHs[fillval - '0'][right - left];
	}
};

struct SegmentTree {
	vector<Val> leafs;
	vector<Sum> nodes;
	vector<Add> add;
	vector<int> leftpos, rightpos;
	int n, n2;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		n2 = (n - 1) / 2 + 1;
		leafs = u; leafs.resize(n, Val());
		nodes.resize(n);
		for(int i = n-1; i >= n2; -- i)
			nodes[i] = Sum(leafs[i*2-n], i*2-n) + Sum(leafs[i*2+1-n], i*2+1-n);
		for(int i = n2-1; i > 0; -- i)
			nodes[i] = nodes[i*2] + nodes[i*2+1];
		add.assign(n, Add());

		leftpos.resize(n); rightpos.resize(n);
		for(int i = n-1; i >= n2; -- i) {
			leftpos[i] = i*2-n;
			rightpos[i] = (i*2+1-n) + 1;
		}
		for(int i = n2-1; i > 0; -- i) {
			leftpos[i] = leftpos[i*2];
			rightpos[i] = rightpos[i*2+1];
		}
	}
	Val get(int i) {
		int indices[128];
		int k = getIndices(indices, i, i+1);
		propagateRange(indices, k);
		return leafs[i];
	}
	Sum getRangeCommutative(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for(int l = i + n, r = j + n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res += sum(l ++);
			if(r & 1) res += sum(-- r);
		}
		return res;
	}
	Sum getRange(int i, int j) {
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		Sum res = Sum();
		for(; i && i + (i&-i) <= j; i += i&-i)
			res += sum((n+i) / (i&-i));
		for(k = 0; i < j; j -= j&-j)
			indices[k ++] = (n+j) / (j&-j) - 1;
		while(-- k >= 0) res += sum(indices[k]);
		return res;
	}
	void set(int i, const Val &x) {
		int indices[128];
		int k = getIndices(indices, i, i+1);
		propagateRange(indices, k);
		leafs[i] = x;
		mergeRange(indices, k);
	}
	void addToRange(int i, int j, const Add &x) {
		if(i >= j) return;
		int indices[128];
		int k = getIndices(indices, i, j);
		propagateRange(indices, k);
		int l = i + n, r = j + n;
		if(l & 1) { int p = (l ++) - n; x.addToVal(leafs[p], p); }
		if(r & 1) { int p = (-- r) - n; x.addToVal(leafs[p], p); }
		for(l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) add[l ++] += x;
			if(r & 1) add[-- r] += x;
		}
		mergeRange(indices, k);
	}
private:
	int getIndices(int indices[], int i, int j) const {
		int k = 0, l, r;
		if(i >= j) return 0;
		for(l = (n + i) >> 1, r = (n + j - 1) >> 1; l != r; l >>= 1, r >>= 1) {
			indices[k ++] = l;
			indices[k ++] = r;
		}
		for(; l; l >>= 1) indices[k ++] = l;
		return k;
	}
	void propagateRange(int indices[], int k) {
		for(int i = k - 1; i >= 0; -- i)
			propagate(indices[i]);
	}
	void mergeRange(int indices[], int k) {
		for(int i = 0; i < k; ++ i)
			merge(indices[i]);
	}
	inline void propagate(int i) {
		if(i >= n) return;
		add[i].addToSum(nodes[i], leftpos[i], rightpos[i]);
		if(i * 2 < n) {
			add[i * 2] += add[i];
			add[i * 2 + 1] += add[i];
		}else {
			add[i].addToVal(leafs[i * 2 - n], i * 2 - n);
			add[i].addToVal(leafs[i * 2 + 1 - n], i * 2 + 1 - n);
		}
		add[i] = Add();
	}
	inline void merge(int i) {
		if(i >= n) return;
		nodes[i] = sum(i * 2) + sum(i * 2 + 1);
	}
	inline Sum sum(int i) {
		propagate(i);
		return i < n ? nodes[i] : Sum(leafs[i - n], i - n);
	}
};

int main() {
	int n, m, k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		char *s = new char[n+1];
		scanf("%s", s);
//		rep(i,n)s[i]=xor128()%10+'0';s[n]=0;
		polyh.precomputePowerTable(n + 1);
		fillHs.resize(10);
		rep(d, 10) {
			fillHs[d].resize(n + 1);
			fillHs[d][0] = PolyH::Hash();
			PolyH::Hash dh('0' + d);
			rep(i, n)
				fillHs[d][i+1] = fillHs[d][i] * PolyH::seeds[0] + dh;
		}
		SegmentTree segt;
		segt.init(vector<Val>(s, s + n));
		rep(ii, m + k) {
			int ty;
			scanf("%d", &ty);
//			ty = xor128() % (m + k) < m ? 1 : 2;
			if(ty == 1) {
				int l, r, c;
				scanf("%d%d%d", &l, &r, &c), -- l;
//				l = xor128() % n, r = xor128() % n, c = xor128() % 10; if(l > r) swap(l, r); ++ r;
				Add add;
				add.fill = true;
				add.fillval = '0' + c;
				segt.addToRange(l, r, add);
			}else if(ty == 2) {
				int l, r, d;
				scanf("%d%d%d", &l, &r, &d), -- l;
//				l = xor128() % n, r = xor128() % n, d = xor128() % 100; if(l > r) swap(l, r); ++ r;
				bool ans;
				if(r - l <= d) {
					ans = true;
				}else {
					Sum a = segt.getRange(l, r - d);
					Sum b = segt.getRange(l + d, r);
					ans = a.h == b.h;
				}
				puts(ans ? "YES" : "NO");
			}else abort();
		}
	}
	return 0;
}