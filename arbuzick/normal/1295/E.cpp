#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int R = 1 << 20;
int t[R*2], fl[R*2];
void build(){
    for(int i = R-1; i > 0; --i)
        t[i] = min(t[i*2], t[i*2+1]);
}
void update(int ql, int qr, int add, int node = 1, int nl = 0, int nr = R){
    if(ql <= nl && nr <= qr){
        t[node] += add;
        fl[node] +=  add;
        return;
    }
    if(qr <= nl || nr <= ql)
        return;
    int nm = (nl+nr)/2;
    update(ql, qr, add, node*2, nl, nm);
    update(ql, qr, add, node*2+1, nm, nr);
    t[node] = min(t[node*2], t[node*2+1])+fl[node];
}
int inf = 1000000000000000;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = n+1; i < R; ++i)
        t[i+R] = inf;
    build();
    for(int i = 0; i < n; ++i)
        update(p[i], n+1, a[i]);
    int ans = inf;
    for(int i = 0; i < n-1; ++i){
        update(0, p[i], a[i]);
        update(p[i], n+1, -a[i]);
        ans = min(ans, t[1]);
    }
    cout << ans;
    return 0;
}