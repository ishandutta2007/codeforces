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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vi> ds(n+1);
    rep(i, n) {
        int d;
        scanf("%d", &d);
        ds[d].pb(i);
    }
    if(ds[0].size() != 1) {
        puts("-1");
        return 0;
    }
    vpii edges;
    rer(d, 1, n) {
        int x = ds[d-1].size(), y = ds[d].size();
        int kk = d == 1 ? k : k-1;
        if((ll)x * kk < y) {
            puts("-1");
            return 0;
        }
        rep(i, ds[d].size())
            edges.push_back(mp(ds[d-1][i / kk], ds[d][i]));
    }
    printf("%d\n", (int)edges.size());
    each(i, edges)
        printf("%d %d\n", i->first+1, i->second+1);
    return 0;
}