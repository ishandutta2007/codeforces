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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
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

int main() {
    static int times[100001], l[100001], r[100001], d[100001];
    static ll cumsum[100001], a[100001];
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    rep(i, n) scanf("%I64d", &a[i]);
    rep(i, m) {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
        l[i] --;
    }
    rep(i, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        x --;
        times[x] ++, times[y] --;
    }
    reu(i, 1, m) times[i] += times[i-1];
    rep(i, m) {
        ll dd = (ll)d[i] * times[i];
        cumsum[l[i]] += dd;
        cumsum[r[i]] -= dd;
    }
    reu(i, 1, n) cumsum[i] += cumsum[i-1];
    rep(i, n) a[i] += cumsum[i];
    rep(i, n) printf("%I64d%c", a[i], i+1 == n ? '\n' : ' ');
    return 0;
}