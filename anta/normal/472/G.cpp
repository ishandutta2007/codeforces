#define _CRT_SECURE_NO_WARNINGS
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
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

typedef unsigned Val;
const int B = 32;

#ifdef __GNUC__
#define popcount __builtin_popcount
#else
inline int popcount(unsigned x) {
	x = x - ((x >> 1) & 0x55555555); 
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
inline int popcount(unsigned long long x) {
	return popcount((unsigned)x) + popcount((unsigned)(x >> 32));
}
inline int popcount(unsigned short x) {
	return popcount((unsigned)x);
}

#endif

struct Query {
	int p1, p2, len, i;
};

//#define TEST
//#define TESTTEST
int main() {
	char *a = new char[200001], *b = new char[200001];
#ifndef TEST
	scanf("%s", a);
	scanf("%s", b);
#else
	int NN = 31 * 32 + 100;
	rep(i, NN) a[i] = '0' + rand() % 2;
	rep(i, NN) b[i] = '0' + rand() % 2;
	a[NN] = b[NN] = 0;
#endif
	int an = strlen(a), bn = strlen(b);
	int q;
	scanf("%d", &q);
	vector<Query> queries[B][B];
	rep(i, q) {
		int p1, p2, len;
#ifndef TEST
		scanf("%d%d%d", &p1, &p2, &len);
#else
		p1=rand()%B,p2=rand()%B;
		len=an-B-rand()%(B*2);
#endif
		Query qq = { p1, p2, len, i };
		queries[p1%B][p2%B].push_back(qq);
	}
	vector<int> ans(q, -1);
	rep(ai, B) rep(bi, B) {
		vector<Val> aa(an / B + 3, 0);
		vector<Val> bb(bn / B + 3, 0);
		rep(i, an) {
			int j = i + B - ai;
			aa[j / B] |= (a[i] == '1' ? 1U : 0U) << j % B;
		}
		rep(i, bn) {
			int j = i + B - bi;
			bb[j / B] |= (b[i] == '1' ? 1U : 0U) << j % B;
		}
		each(qq, queries[ai][bi]) {
			int p1 = qq->p1, p2 = qq->p2, len = qq->len;
			int len2 = len / B;
			const Val *aL = &aa[0] + (p1 - ai) / B + 1;
			const Val *bL = &bb[0] + (p2 - bi) / B + 1;
			const int Unroll = 31;
			int cnt = 0;
			int i;
			int len2_truncated = len2 / Unroll * Unroll;
			for(i = 0; i < len2_truncated; ) {
				Val sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
#define ADD() \
			   do{\
			       Val cy = aL[i] ^ bL[i];\
				   { Val t = sum0 & cy; sum0 ^= cy; cy = t; }\
				   { Val t = sum1 & cy; sum1 ^= cy; cy = t; }\
				   { Val t = sum2 & cy; sum2 ^= cy; cy = t; }\
				   { Val t = sum3 & cy; sum3 ^= cy; cy = t; }\
				   { Val t = sum4 & cy; sum4 ^= cy; cy = t; }\
				   ++ i;\
			   }while(0)
				ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD();
				ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD();
				ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD();
				ADD(); ADD(); ADD(); ADD(); ADD(); ADD(); ADD();
				cnt += popcount(sum0);
				cnt += popcount(sum1) << 1;
				cnt += popcount(sum2) << 2;
				cnt += popcount(sum3) << 3;
				cnt += popcount(sum4) << 4;
			}
			for(; i < len2; ++ i)
				cnt += popcount((Val)(aL[i] ^ bL[i]));
			{	Val mask = ((Val)1 << len % B) - 1;
				Val x = aL[len2] & mask, y = bL[len2] & mask;
				cnt += popcount((Val)(x ^ y));
			}
			ans[qq->i] = cnt;
#ifdef TESTTEST
			int cnt2 = 0;
			rep(i, len)
				cnt2 += a[p1 + i] != b[p2 + i];
			if(cnt != cnt2) cerr << cnt << " != " << cnt2 << endl;
#endif
		}
	}
#ifndef TESTTEST
	rep(i, q)
		printf("%d\n", ans[i]);
#endif
	return 0;
}