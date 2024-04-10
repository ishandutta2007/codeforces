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
const int nCr_MaxR = 1000001;
int factinv[nCr_MaxR+1];    //factinv[r] = r! mod MOD

ll inverse(ll a) {
    ll b = MOD, u = 1, v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    return (u % MOD + MOD) % MOD;
}

void nCr_computeFactinv() {
    ll x = 1;
    rep(i, nCr_MaxR+1) {
        factinv[i] = inverse(x);
        (x *= i+1) %= MOD;
    }
}

int nCr(int n, int r) { //n < MOD, r < MOD
    ll x = 1;
    rep(i, r)
        (x *= n-i) %= MOD;
    (x *= factinv[r]) %= MOD;
    return x;
}

int main() {
    nCr_computeFactinv();
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);

    int r = 0;
    rer(i, 0, n) {  //ai
        int x = a * i + b * (n-i);
        int as = 0, bs = 0, xs = 0;
        while(x) xs ++, as += x % 10 == a, bs += x % 10 == b, x /= 10;
        if(as+bs == xs)
            (r += nCr(n, i)) %= MOD;
    }
    printf("%d\n", r);
    return 0;
}