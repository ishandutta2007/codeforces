#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e5) + 10
using namespace std;

pair < int, pii> tt[4*MAXN];
int n;
int a[MAXN];
int t[20][MAXN];
pair < int, pii > get(pair < int, pii > a, pair < int, pii > b){
    if( a.f < b.f) return a;
    if( b.f < a.f) return b;
    if( a.f == inf) return a;
    return mp(a.f, mp(a.s.f + b.s.f, a.s.s));
}
void build(int v = 1, int l = 0, int r = n-1){
    if(l == r) {
        tt[v] = mp(a[l], mp(1, l));
    }
    else {
        build(2*v, l, (l + r) >> 1);
        build(2*v + 1, ((l+r) >> 1 )+ 1, r);
        tt[v] = get(tt[v << 1], tt[(v << 1) | 1]);
    }                                  
}

pair < int, pii> val(int tl, int tr, int v = 1, int l = 0, int r = n-1){
    if( tl > tr) return mp(inf, mp(0, -1) );
    if(l == tl && tr == r) return tt[v];
    int mid = (l + r) >> 1;
    return get(val(max(tl, mid+1), tr,(v << 1)|1, mid+1, r), val(tl,  min(mid, tr), v << 1, l, mid));
}

int c[MAXN], e[MAXN],p[MAXN];




int calc(int l, int r) {
    int d = p[r-l+1];
    return __gcd(t[d][l], t[d][r - (1 << d) + 1]);
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    p[1] = 0;
    for(int i = 2; i < n; i++){
        p[i] = p[i/2] + 1;
    }
    build();

    for(int i = 0; i < n; i++) t[0][i] = a[i];
    for(int d = 1; (1 << d) <= n; d++) {
        for(int i = 0; i + (1 << d) <= n; i++) {
            t[d][i] = __gcd(t[d - 1][i], t[d - 1][i + (1 << (d-1))]);
        }
    }

    for(int i = 0; i < n; i++){
        int r = i, l = 0;
        int ans = -1;
        while( l <= r){
            int mid = (l + r) >> 1;
            if( calc(mid, i) == a[i]){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        c[i] = ans;
        l = i,r = n-1;
        ans = -1;
        while( l <= r){
            int mid = (l + r) >> 1;
            if( calc(i, mid) == a[i]){
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        e[i] = ans;
    }
    int tests;
    cin >> tests;
    for(int i=0,l,r; i< tests; i++){
        cin >> l >> r;
        l--;
        r--;
        pair < int, pii > g = val(l, r);
        int ans = r-l+1;
        if(c[g.s.s] <= l && e[g.s.s] >= r){
            ans -= g.s.f;
        }
        printf("%d\n", ans);
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}