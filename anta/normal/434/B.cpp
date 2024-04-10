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

int a[1000][1000], b[1000][1000];
int h[1000][1001];
int qop[1000], qy[1000], qx[1000];
int ans[1000];
int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
    rep(i, q)
        scanf("%d%d%d", &qop[i], &qy[i], &qx[i]), qy[i] --, qx[i] --;
    mset(ans, -1);
    rep(swapyx, 2) { rep(mirrory, 2) {
        rep(i, n) rep(j, m) b[i][j] = a[i][j];
        rep(j, m) rep(i, n)
            h[i][j] = b[i][j] == 0 ? 0 : (i == 0 ? 0 : h[i-1][j]) + 1;
        rep(ii, q) {
            int y = qy[ii], x = qx[ii];
            if(qop[ii] == 1) {
                b[y][x] ^= 1;
                rep(i, n)
                    h[i][x] = b[i][x] == 0 ? 0 : (i == 0 ? 0 : h[i-1][x]) + 1;
            }else {
                h[y][m] = 0;
                vpii stk; stk.push_back(mp(-1, -1));
                int a = 0;
                rep(j, m+1) {
                    int k = j;
                    while(stk.back().first > h[y][j]) {
                        pii p = stk.back(); stk.pop_back();
                        k = p.second;
                        if(k <= x && x < j) amax(a, p.first * (j - k));
                    }
                    stk.push_back(mp(h[y][j], k));
                }
                amax(ans[ii], a);
            }
        }
        rep(i, n) rep(j, m) b[i][j] = a[i][j];
        rep(i, n) rep(j, m) a[n-1-i][j] = b[i][j];
        rep(i, q) qy[i] = n - 1 - qy[i];
    }
    rep(i, n) rep(j, m) b[i][j] = a[i][j];
    rep(i, n) rep(j, m) a[j][i] = b[i][j];
    rep(i, q) swap(qy[i], qx[i]);
    swap(n, m);
    }
    rep(i, q) if(ans[i] != -1)
        printf("%d\n", ans[i]);
    return 0;
}