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

int a[100000];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, m) scanf("%d", &a[i]);
    ll base = 0;
    rep(i, m-1) base += abs(a[i+1] - a[i]);
    vector<vi> pages(n+1);
    rep(i, m) {
        if(i > 0   && a[i] != a[i-1]) pages[a[i]].push_back(a[i-1]);
        if(i < m-1 && a[i] != a[i+1]) pages[a[i]].push_back(a[i+1]);
    }
    ll ans = base;
    rer(x, 1, n) {
        vi &v = pages[x];
        if(v.empty()) continue;
        sort(all(v));
        ll cost = base;
        each(i, v) cost -= abs(*i - x);
        int median = v[v.size() / 2];
        each(i, v) cost += abs(*i - median);
//      cerr << x << ": " << median << ", " << cost - base << endl;
        amin(ans, cost);
    }
    cout << ans << endl;
    return 0;
}