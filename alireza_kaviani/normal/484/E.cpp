    #include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct node{
    int pref , suff , mx , sz;
    node(){
        pref = suff = mx = sz = 0;
    }
};

int n , q , nodeInd = 1 , H[MAXN] , root[MAXN] , L[MAXN * LOG] , R[MAXN * LOG];
vector<pii> vec;
node seg[MAXN * LOG];

node merge(const node &l , const node &r){
    node ans;
    ans.sz = l.sz + r.sz;
    ans.mx = max({l.mx , r.mx , l.suff + r.pref});
    ans.pref = l.pref + (l.pref == l.sz ? r.pref : 0);
    ans.suff = r.suff + (r.suff == r.sz ? l.suff : 0);
    return ans;
}

void build(int id = 0 , int l = 0 , int r = n){
    seg[id].sz = r - l;
    if(r - l == 1)  return;
    int mid = l + r >> 1;
    L[id] = nodeInd++;
    R[id] = nodeInd++;
    build(L[id] , l , mid);
    build(R[id] , mid , r);
    seg[id] = merge(seg[L[id]] , seg[R[id]]);
}

int update(int x , int id , int l = 0 , int r = n){
    int ID = nodeInd++; seg[ID] = seg[id]; L[ID] = L[id] ; R[ID] = R[id];
    if(r - l == 1){
        seg[ID].pref = seg[ID].suff = seg[ID].mx = 1;
        return ID;
    }
    int mid = l + r >> 1;
    if(x < mid) L[ID] = update(x , L[ID] , l , mid);
    else    R[ID] = update(x , R[ID] , mid , r);
    seg[ID] = merge(seg[L[ID]] , seg[R[ID]]);
    return ID;
}

node get(int ql , int qr , int id , int l = 0 , int r = n){
    if(qr <= l || r <= ql)  return seg[MAXN * LOG - 1];
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return merge(get(ql , qr , L[id] , l , mid) , get(ql , qr , R[id] , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> H[i];
        vec.push_back({H[i] , i});
    }
    sort(all(vec) , greater<pii>());
    build();
    for(int i = 0 ; i < n ; i++){
        root[i + 1] = update(vec[i].Y , root[i]);
    }
    cin >> q;
    while(q--){
        int l , r , w;
        cin >> l >> r >> w; l--;
        int L = 0 , R = n;
        while(R - L > 1){
            int mid = L + R >> 1;
            if(get(l , r , root[mid]).mx >= w) R = mid;
            else    L = mid;
        }
        cout << vec[L].X << endl;
        //cout << L * w << endl;
    }

    return 0;
}
/*

*/