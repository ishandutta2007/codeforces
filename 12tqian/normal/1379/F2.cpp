#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9, MAX = (1<<18);
struct node{
    int e, o; bool bad;
    node(){ e = INF; o = -1; bad = false; }
    node(int _e, int _o){ e = _e; o = _o; bad = false; }
} seg[2*MAX];
node comb(node x, node y){
    node res; res.e = min(x.e, y.e); res.o = max(x.o, y.o); res.bad = x.bad || y.bad || x.e <= y.o;
    return res;
}
void update(int p, pair<int, int> val){
    p += MAX; seg[p].e = val.first; seg[p].o = val.second; seg[p].bad = val.first <= val.second;
    for(; p > 1; p >>= 1) seg[p >> 1] = comb(seg[(p|1)^1], seg[p|1]);
}
bool query(int l, int r){
    node la, ra; r++;
    for(l += MAX, r += MAX; l < r; l >>= 1, r >>= 1){
        if(l&1) la = comb(la, seg[l++]);
        if(r&1) ra = comb(seg[--r], ra);
    }
    return comb(la, ra).bad;
}
set<int> even[MAX], odd[MAX];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    for(int i = 0; i < n; i++) even[i].insert(INF), odd[i].insert(-1);
    while(q--){
        int x, y; cin >> x >> y; x--; y--;
        if(x%2 == 0){
            if(even[x/2].count(y)) even[x/2].erase(y);
            else even[x/2].insert(y);
        }
        else{
            if(odd[x/2].count(y)) odd[x/2].erase(y);
            else odd[x/2].insert(y);
        }
        update(x/2, make_pair(*even[x/2].begin(), *odd[x/2].rbegin()));
        cout << (query(0, n-1) ? "NO" : "YES") << '\n';
    }
    return 0;
}