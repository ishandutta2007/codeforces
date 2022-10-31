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

const int MOD = 1000000007;

ll inverse(ll a) {
    ll b = MOD, u = 1, v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    return (u % MOD + MOD) % MOD;
}

ll powmod(ll a, ll k) {
    ll r = 1 % MOD;
    while(k) {
        if(k & 1)
            (r *= a) %= MOD;
        (a *= a) %= MOD;
        k >>= 1;
    }
    return r;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    static bool b[1001];
    mset(b, 0);
    rep(i, m) {
        int x;
        scanf("%d", &x); x --;
        b[x] = 1;
    }
    vi spaces;
    int prev = 0;
    bool first = true;
    rep(i, n) {
        if(b[i] == 1) {
            if(prev) spaces.pb(first ? -prev : prev);
            prev = 0;
            first = false;
        }else {
            prev ++;
        }
    }
    if(prev) spaces.pb(- prev);
    int sum = 0;
    ll r = 1;
    rep(i, spaces.size()) {
        int x = abs(spaces[i]);
        sum += x;
        ll fact = 1;
        rer(j, 1, x) (fact *= j) %= MOD;
        (r *= inverse(fact)) %= MOD;
        if(spaces[i] > 0) {
            (r *= powmod(2, x-1)) %= MOD;
        }
    }
    ll fact = 1;
    rer(j, 1, sum) (fact *= j) %= MOD;
    (r *= fact) %= MOD;
    cout << r << endl;
    return 0;
}