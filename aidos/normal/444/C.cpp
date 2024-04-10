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
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e5 + 10)
using namespace std;
int n, m, a[MAXN], k = 300;
ll b[MAXN];
ll d[400], sum[400];
int must[400];
bool check(int l, int r, int z){
    if( z * k == l && r == min(n, z * k + k)-1) return 1;
    return 0;
}
void update(int l, int r, int z, int x){
    if( must[z] == x) return;
    if( check( l, r, z )) {
        if( must[z] > 0 ){
            sum[z] += ( r - l + 1) * 1ll * (abs(must[z] - x));
            d[z] += abs(must[z] - x);
            must[z] = x;
        }
        else {
            for(int i = l; i <= r; i++){
                b[i] += abs(a[i] - x);
                sum[z] += abs(a[i] - x);
                a[i] = x;
            }
            must[z] = x;
        }
        return;
    }
    if(must[z] > 0){
        for(int i = z * k; i<l; i++){
            b[i] += d[z];
            a[i] = must[z];
        }
        for(int i = r + 1, e = min((z+1) * k, n); i<e; i++){
            b[i] += d[z];
            a[i] = must[z];
        }
    }
    for(int i = l; i<=r; i++){
        if(must[z] > 0) {
            a[i] = must[z];
        }
        b[i] += abs(a[i] - x) + d[z];
        sum[z] += abs(a[i] - x);
        a[i] = x;
    }
    d[z] = 0;
    must[z] = -1;
}
void upd(int l, int r, int x){
    int c_l = l/k;
    int c_r = r/k;
    if( c_l == c_r ){
        update(l, r, c_l, x);
    }
    else {
        update(l, (c_l + 1 ) * k-1, c_l, x);
        for(int i = c_l+1; i < c_r; i++){
            update(i * k, ( i + 1 ) * k-1, i, x);
        }
        update(c_r * k, r, c_r, x);
    }
}
ll go(int l, int r, int z){
    if( check( l, r, z )) return sum[z];
    ll ans= 0;
    for(int i = l; i <= r; i++){
        ans += b[i];
    }
    if(must[z] == -1) return ans;
    return ans + (r - l + 1) * 1ll * d[z];
}
ll get(int l, int r){
    int c_l = l/k;
    int c_r = r/k;
    if( c_l == c_r){
        return go(l, r, c_l);
    }
    else {
        ll ans  = 0;
        ans += go(l, (c_l+1) * k - 1, c_l);
        for(int i = c_l + 1; i<c_r; i++){
            ans += go(i * k, (i  + 1) * k - 1, i);
        }
        ans += go( c_r * k, r, c_r);
        return ans;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    k = min(n, k);
    int last = 0;
    for(int i = 0; i < n; i++){
        a[i] = i+1;
    }
    memset(must, -1, sizeof(must));

    for(int i = 0; i < m; i++){
        int t, l, r, x =-1;
        cin >> t >> l >> r;
        l--;
        r--;
        if( t == 1) {
            cin >> x;
            upd(l, r, x);
        }
        else cout << get(l, r) << endl;
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}