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
#include <list>
#include <cassert>
#include <csetjmp>
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(x > y) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

bool g[1000][1000];
int main() {
    int K;
    scanf("%d", &K);
    mset(g, 0);
    const int B = 30;
    int N = 2;
    rep(i, B-1) {
        g[N-1][N] = true;
        N ++;
    }
    rep(i, B) if(K >> i & 1) {
        vi prevs; prevs.pb(0);
        rep(j, i) {
            each(k, prevs) g[*k][N] = g[*k][N+1] = true;
            prevs.clear(); prevs.pb(N); prevs.pb(N+1);
            N += 2;
        }
        each(k, prevs) g[*k][1+(B-1-i)] = true;
    }
    rep(i, N) rep(j, N) g[i][j] |= g[j][i];
//  rep(i, N) reu(j, i+1, N) if(g[i][j]) cerr << i << " " << j << endl;
    printf("%d\n", N);
    rep(i, N) {
        rep(j, N) putchar("NY"[g[i][j]]);
        puts("");
    }
    return 0;
}