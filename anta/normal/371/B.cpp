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
    ll a, b;
    cin >> a >> b;
    map<ll,int> can;
    rer(a2, 0, 29) rer(a3, 0, 18) rer(a5, 0, 12) {
        ll x = 1;
        rep(i, a2) {
            x *= 2;
            if(x > (ll)1e9) goto overflow;
        }
        rep(i, a3) {
            x *= 3;
            if(x > (ll)1e9) goto overflow;
        }
        rep(i, a5) {
            x *= 5;
            if(x > (ll)1e9) goto overflow;
        }
        can[x] = a2 + a3 + a5;
    overflow:;
    }
    int r = INF;
    map<ll,int> acan;
    each(i, can) if(a % i->first == 0) acan[a / i->first] = i->second;
    each(i, can) if(b % i->first == 0) {
        ll t = b / i->first;
        if(acan.count(t))
            r = min(r, i->second + acan[t]);
    }
    cout << (r == INF ? -1 : r) << endl;
    return 0;
}