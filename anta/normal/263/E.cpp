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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define reps(i,n,s) for(int (i)=0;(i)<(int)(n);(i)+=(s))
#define reus(i,l,u,s) for(int (i)=(int)(l);(i)<(int)(u);(i)+=(s))
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

void show(vector<vl> v) {
    each(i, v) {
        each(j, *i) cout.width(2), cout << *j;
        cout << endl;
    }
    cout << endl;
}
vector<vl> cumdif(const vector<vl>& v, int dy, int dx) {
    int h = v.size(), w = v[0].size();
    vector<vl> r(h+1, vl(w+1, 0));
    rep(i, h+1) rep(j, w+1) {
        int yy = i - dy, xx = j - dx;
        r[i][j] = (0<=i&&i<h&&0<=j&&j<w ? v[i][j] : 0) - (0<=yy&&yy<h&&0<=xx&&xx<w ? v[yy][xx] : 0);
    }
    return r;
}

vector<vl> cumsum(const vector<vl>& v, int dy, int dx) {
    int h = v.size(), w = v[0].size();
    vector<vl> r(h+1, vl(w+1, 0));
    rep(i, h+1) rep(j, w+1) {
        int yy = i - dy, xx = j - dx;
        r[i][j] = (0<=yy&&yy<h&&0<=xx&&xx<w ? r[yy][xx] : 0) + (0<=yy&&yy<h&&0<=xx&&xx<w ? v[yy][xx] : 0);
    }
    return r;
}
int main() {
//  /*
    int n, m, k;
    cin >> n >> m >> k;
    vector<vl> a(n+4, vl(m+4));
    rep(i, n) rep(j, m) cin >> a[i+2][j+2];
    a = cumsum(a, 1, 0);
    a = cumsum(a, 0, 1);
    a = cumsum(a, 1, 1);
    a = cumsum(a, 1,-1);
    ll r = -1; int ra = -1, rb = -1;
    rer(x, k-1+2, m-k+2) rer(y, k-1+2, n-k+2) {
        ll t = 0;

//      rer(i, y-k+1, y+k-1) rer(j, x-k+1, x+k-1)
//          t += a[i][j] * max(0, k - (abs(j-x) + abs(i-y)));
//      rer(i, 0, k-1) rer(j, x-k+1+i, x+k-1-i)
//          t -= a[y-i][j];
//      rer(i, 0, k-1) rer(j, x-k+1+i, x+k-1-i)
//          t += a[y+1+i][j];
#if 1
        t += a[y - k + 1][x];
        t += a[y - k + 1 + 1][x];
        t -= a[y - k + 1][x + 1];
        t -= a[y - k + 1 + 1][x + 1];

        t += a[y + 1 + 1][x - k];
        t += a[y + 1 + 1][x - k + 1];
        t -= a[y + 1][x - k];
        t -= a[y + 1][x - k + 1];

        t += a[y + 1][x + k];
        t += a[y + 1][x + k + 1];
        t -= a[y + 1 + 1][x + k];
        t -= a[y + 1 + 1][x + k + 1];

        t += a[y + k + 1][x + 1];
        t += a[y + k + 1 + 1][x + 1];
        t -= a[y + k + 1][x];
        t -= a[y + k + 1 + 1][x];
#endif

//      cerr << x-2+1 << ", " << y-2+1 << ": " << t << endl;
        if(r < t) rb = x - 2 + 1, ra = y - 2 + 1, r = t;
    }
    cout << ra << " " << rb << endl;
    /*/
    int n = 40, m = 30, k = 14;
    int x = 15, y = 15;
    vector<vl> v(n, vl(m));
    rep(i, n) rep(j, m)
        v[i][j] = max(0, k-(abs(i-y)+abs(j-x)));
    show(v); v = cumdif(v, 1, 0);
//  show(v); v = cumdif(v, 0, 1);
//  show(v); v = cumdif(v, 1, 1);
//  show(v); v = cumdif(v, 1,-1);
    show(v); v = cumsum(v, 1, 0);
//  show(v); v = cumsum(v, 0, 1);
//  show(v); v = cumsum(v, 1, 1);
//  show(v); v = cumsum(v, 1,-1);
    show(v);
//  */
    return 0;
}