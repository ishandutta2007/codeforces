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

struct SubstringHash {
	static const int NumMods = 3;
	static const unsigned Mods[NumMods];
	typedef unsigned long long ull;
	struct Hash {
		unsigned hs[NumMods];
		Hash() { for(int k = 0; k < NumMods; ++ k) hs[k] = 0; }
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
	};
	static unsigned seeds[NumMods];
	std::vector<Hash> powh, preh;
	SubstringHash() { if(seeds[0] == 0) initSeeds(); }
	static void initSeeds() {
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x;
			do x = xor128(); while(x == 0 || x >= Mods[k]);
			seeds[k] = x;
		}
	}
	template<typename V>
	void init(const V &v, int n) {
		powh.resize(n+1); preh.resize(n+1);
		for(int k = 0; k < NumMods; ++ k) powh[0].hs[k] = 1;
		for(int i = 0; i < n; i ++) for(int k = 0; k < NumMods; ++ k)
			powh[i+1].hs[k] = (ull)powh[i].hs[k] * seeds[k] % Mods[k];
		preh[0] = Hash();
		for(int i = 0; i < n; i ++) for(int k = 0; k < NumMods; ++ k)
			preh[i+1].hs[k] = ((ull)preh[i].hs[k] * seeds[k] % Mods[k] + v[i]) % Mods[k];
	}
	Hash hash(int i, int j) const {
		Hash res;
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x = preh[j].hs[k] + Mods[k] - (unsigned)((ull)preh[i].hs[k] * powh[j - i].hs[k] % Mods[k]);
			res.hs[k] = x >= Mods[k] ? x - Mods[k] : x;
		}
		return res;
	}
	Hash append(const Hash &h, const Hash &g, int glen) const {
		Hash res;
		for(int k = 0; k < NumMods; ++ k) {
			unsigned x = (unsigned)((ull)h.hs[k] * powh[glen].hs[k] % Mods[k]) + g.hs[k];
			res.hs[k] = x >= Mods[k] ? x - Mods[k] : x;
		}
		return res;
	}
};
const unsigned SubstringHash::Mods[SubstringHash::NumMods] = { 2147483647U, 2147483629U, 2147483587U };
unsigned SubstringHash::seeds[SubstringHash::NumMods];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	SubstringHash subh, abc;
	abc.init("abc", 3);
	char *buf = new char[600001];
	vector<SubstringHash::Hash> hashes;
	rep(i, n) {
		scanf("%s", buf);
		int len = strlen(buf);
		subh.init(buf, len);
		rep(j, len) rer(c, 'a', 'c') if(buf[j] != c) {
			SubstringHash::Hash h = subh.append(subh.append(subh.hash(0, j), abc.hash(c - 'a', c - 'a' + 1), 1), subh.hash(j+1, len), len - j - 1);
			hashes.push_back(h);
		}
	}
	sort(all(hashes));
	rep(ii, m) {
		scanf("%s", buf);
		int len = strlen(buf);
		subh.init(buf, len);
		SubstringHash::Hash h = subh.hash(0, len);
		bool ans = binary_search(all(hashes), h);
		puts(ans ? "YES" : "NO");
	}
	return 0;
}