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

long long memo[65][65][2];
long long N;
long long rec(int i, int k, int lt) {
    if(k < 0) return 0;
    long long &r = memo[i+1][k][lt];
    if(r != -1) return r;
    if(i == -1) return r = k == 0;
    r = 0;
    int c = (int)(N >> i & 1);
    rep(b, 2) if(lt || b <= c)
        r += rec(i-1, k-b, lt || b < c);
    return r;
}

int main() {
    long long m; int k;
    scanf("%I64d%d", &m, &k);
    long long l = 1, u = (long long)1e18;
    while(u - l > 0) {
        long long mid = (l + u) / 2;
        long long cnt = 0;
        N = mid * 2;
        mset(memo, -1);
        cnt += rec(63, k, 0);
        N = mid;
        mset(memo, -1);
        cnt -= rec(63, k, 0);
        if(m <= cnt)
            u = mid;
        else
            l = mid + 1;
    }
    printf("%I64d\n", l);
    return 0;
}