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

const int inf = (1ll << 30) - 1;

#define MAXN (int) (1e5) + 10
using namespace std;
int tt[4*MAXN];
int g[MAXN];

int n;


void add(int k, int l, int r, int v=1, int tl = 0, int tr = n-1){
    if(l > r) return;
    if(l == tl && r == tr){
        tt[v] |= k;
    }   
    else {
        int mid= (tl + tr) >> 1;
        add(k, l, min(mid, r), v << 1, tl, mid);
        add(k, max(l, mid+1), r, (v << 1) | 1, mid+1, tr);
    }
}

int val(int k, int v = 1, int l = 0, int r = n-1){
    if( l == r) return tt[v];
    int mid = (l + r) >> 1;
    if( k <= mid) return val(k, v << 1, l, mid) | tt[v];
    return tt[v] | val(k, (v << 1) | 1, mid+1, r); 
}

void build(int v=1, int l = 0, int r = n-1){
    if( l == r){
        tt[v] = g[l];
    }
    else {
        int mid = ( l + r ) >> 1;
        build( 2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tt[v] = tt[v * 2] & tt[v * 2 + 1];
    }
}
int get(int tl, int tr, int v = 1, int l = 0, int r = n-1){
    if( tl>tr) return inf;
    if( tl == l && tr == r) return tt[v];
    int mid = (l + r) >> 1;
    return get(tl, min(mid, tr), v << 1, l, mid) & get( max(tl, mid+1), tr, (v << 1) | 1, mid+1, r);
}






int a[MAXN], b[MAXN], d[MAXN];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> d[i];
        a[i]--;
        b[i]--;
        add(d[i], a[i], b[i]);
    }
    for(int i = 0; i < n; i++){
        g[i] = val(i);
    }
    build();
    for(int i = 0; i < m; i++){
        if( get(a[i], b[i]) != d[i] ){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << g[i] <<  " ";
    }
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}