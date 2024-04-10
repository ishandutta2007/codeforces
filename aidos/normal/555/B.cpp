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
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
int m;
pll a[200200];
pll b[400200];
ll l[400200], r[200200];
int ans[200200];
int t[1000000];

int lwr(ll x){
    int l = 0, r = m-1;
    int ans=m;
    while( l <= r){
        int mid = (l + r) >> 1;
        if( a[mid].f >= x) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
int upr(ll x){
    int l = 0, r = m-1;
    int ans=-1;
    while( l <= r){
        int mid = (l + r) >> 1;
        if( a[mid].f <= x) {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}
void build(int v, int l, int r){
    if( l == r){
        t[v] = l;
    }
    else {
        int mid=( l + r) >> 1;
        build(v * 2, l, mid);
        build(v  *2 + 1, mid+ 1, r);
        t[v] = l;
    }
}
int get(int v, int l, int r, int tl, int tr){
    if( tl > tr) return inf;
    if( tl == l && tr == r) return t[v];
    int mid = (l + r) >> 1;
    return min( get(v * 2, l, mid , tl, min(tr, mid)), get(v * 2 + 1, mid +1, r, max(tl, mid+1), tr));
}

void upd(int v, int l, int r, int pos){
    if( l == r) t[v] = inf;
    else{
        int mid = ( l + r) >> 1;
        if(pos <= mid) {
            upd(v * 2, l, mid, pos);
        }
        else {
            upd( v * 2 + 1, mid+1, r, pos);
        }
        t[v] = min(t[v*2], t[v * 2 + 1]);
    }
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0;  i< n; i++){
        scanf("%I64d %I64d", &l[i], &r[i]);
    }
    int en = 0;
    for(int i = 0; i < n-1; i++){
        b[en++] = mp(l[i+1] - r[i], -i-1);
        b[en++] = mp(r[i+1] - l[i], i+1);
    }
    sort(b, b + en);
    for(int i = 0; i < m; i++){
        scanf("%I64d", &a[i].f);
        a[i].s = i;
    }
    sort(a, a + m);
    build(1, 0, m-1);
    for(int i=0; i< en; i++){
        if(b[i].s < 0){
            l[-(b[i].s+1)] = lwr(b[i].f);
            if(l[-(b[i].s+1)] == m){
                cout << "No\n";
                return 0;
            }
        }
        else {
            int pos = b[i].s-1;
            int r_pos = upr(b[i].f);
            if(r_pos == -1){
                cout << "No\n";
                return 0;
            }
            int x = get(1, 0, m-1, l[pos], r_pos);
            if( x == inf){
                cout << "No\n";
                return 0;
            }
            ans[pos] = a[x].s;
            upd(1, 0, m-1, x);
        }
    }
    printf("Yes\n");
    for(int i = 0; i < n-1; i++){
        printf("%d ", ans[i] + 1);
    }
    printf("\n");




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}