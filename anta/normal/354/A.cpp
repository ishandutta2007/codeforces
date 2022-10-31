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

int main() {
    int n;
    ll l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;
    static int w[100001];
    rep(i, n) cin >> w[i];
    static ll p[100001];
    rep(i, n) p[i+1] = p[i] + w[i];
    ll res = INFL;
    rer(i, 0, n) {
        ll x = 0;
        x += (p[i] - p[0]) * l;
        x += (p[n] - p[i]) * r;
        if(i <= n - i)
            x += max(0, (n - i) - i - 1) * Qr;
        else
            x += max(0, i - (n - i) - 1) * Ql;
        res = min(res, x);
    }
    cout << res << endl;
    return 0;
}