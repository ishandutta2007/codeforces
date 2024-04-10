// In the name of God

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define int long long

const int inf = 1e18 + 1ll;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
const int eps = 1e-9;

int n;
int a[N], d[N], t[N];
int g[4*N];

void build(int v, int tl, int tr){
    if(tl == tr){
        g[v] = t[tl];
        return;
    }
    int mid = (tl + tr)/2;
    build(v+v, tl, mid);
    build(v+v+1, mid+1, tr);
    g[v] = max(g[v+v], g[v+v+1]);
}

int get(int v, int tl, int tr, int val){
    if(tl >= val) return 0;
    if(tr < val) return g[v];
    int mid = (tl+tr)/2;
    return max(get(v+v, tl, mid, val), get(v+v+1, mid+1, tr, val));
}

void upd(int v, int tl, int tr, int pos, int val){
    if(tl > pos  || tr < pos) return;
    if(tl == tr){
        g[v] = val;
        return;
    }
    int mid = (tl+tr)/2;
    if(pos <= mid){
        upd(v+v, tl, mid, pos, val);
    } else {
        upd(v+v+1, mid+1, tr, pos, val);
    }
    g[v] = max(g[v+v], g[v+v+1]);
}

void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        t[a[i]] = 0;
    }
    d[0] = 1;
    t[a[0]] = 1;
    build(1, 1, n);
    for(int i = 1; i < n; i++){
        d[i] = get(1, 1, n, a[i]);
        d[i] += 1;
        upd(1, 1, n, a[i], d[i]);
    }
    cout << g[1];
}

main(){
     ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;
//    cin >> test;
    for(int i = 1; i <= test; i++){
       //  cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}