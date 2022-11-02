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

#define MAXN (int) (1e6 + 10)
using namespace std;
int n;
int a[MAXN];
int b[MAXN];
int sz;
map < int, int > m, tt;        
int t[5 * MAXN];
int get(int l, int r, int v = 1, int tl = 0, int tr = n ){
    if( l > r) return 0;
    if( tl == l && tr == r) return t[v];
    int mid = ( tl + tr) >> 1;
    return get(l, min(r, mid), v * 2, tl, mid) + get(max(l, mid+1), r, v * 2 + 1, mid+1, tr);
}
void upd(int l, int k, int v = 1, int tl = 0, int tr = n){
    if( tl == tr){
        t[v] += k;
        return;
    }

    int mid = ( tl + tr) >> 1;
    if( mid >= l) upd(l, k, v*2, tl, mid);
    else upd(l, k, v*2+1, mid+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        //cerr << i << endl;
        b[i] = m[a[i]]+1;
//        cout << b[i] << endl;
        upd(b[i], 1);
        //return 0;
        m[a[i]]++;
    }

    ll ans = 0;
    for(int i = n-1;i > 0;i--){
        upd(b[i], -1);
        tt[a[i]]++;
        ans += get(tt[a[i]]+1, n);
//        cerr << ans << endl;

    }
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}