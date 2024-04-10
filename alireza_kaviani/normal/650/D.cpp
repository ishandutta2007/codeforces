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

const ll MAXN = 4e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , q , nodeInd[2] = {1 , 1} , A[MAXN] , st[MAXN] , fn[MAXN] , cnt[MAXN] , mark[MAXN] , LIS , root[2][MAXN];
int seg[2][MAXN * LOG] , lc[2][MAXN * LOG] , rc[2][MAXN * LOG];
vector<int> vec;
vector<pii> v1 , v2;

void build(int ind , int id = 0 , int l = 0 , int r = n){
    if(r - l == 1)  return;
    int mid = l + r >> 1;
    lc[ind][id] = nodeInd[ind]++;
    build(ind , lc[ind][id] , l , mid);
    rc[ind][id] = nodeInd[ind]++;
    build(ind , rc[ind][id] , mid , r);
}

int update(int ind , int x , int v , int ID , int l = 0 , int r = n){
    int id = nodeInd[ind]++;
    seg[ind][id] = seg[ind][ID]; lc[ind][id] = lc[ind][ID]; rc[ind][id] = rc[ind][ID];
    if(r - l == 1){
        seg[ind][id] = v;
        return id;
    }
    int mid = l + r >> 1;
    if(x < mid) lc[ind][id] = update(ind , x , v , lc[ind][id] , l , mid);
    else    rc[ind][id] = update(ind , x , v , rc[ind][id] , mid , r);
    seg[ind][id] = max(seg[ind][lc[ind][id]] , seg[ind][rc[ind][id]]);
    return id;
}

int get(int ind , int ql , int qr , int id , int l = 0 , int r = n){
    if(qr <= ql || qr <= l || r <= ql)  return 0;
    if(ql <= l && r <= qr)  return seg[ind][id];
    int mid = l + r >> 1;
    return max(get(ind , ql , qr , lc[ind][id] , l , mid) , get(ind , ql , qr , rc[ind][id] , mid , r));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        int ind = lower_bound(all(vec) , A[i]) - vec.begin();
        if(ind == SZ(vec))  vec.push_back(A[i]);
        vec[ind] = A[i];
        fn[i] = ind + 1;
    }
    LIS = SZ(vec);
    vec = {};
    for(int i = n - 1 ; i >= 0 ; i--){
        int ind = lower_bound(all(vec) , -A[i]) - vec.begin();
        if(ind == SZ(vec))  vec.push_back(-A[i]);
        vec[ind] = -A[i];
        st[i] = ind + 1;
        if(st[i] + fn[i] == LIS + 1)    cnt[st[i]]++;
    }
    for(int i = 0 ; i < n ; i++){
        if(st[i] + fn[i] == LIS + 1 && cnt[st[i]] == 1) mark[i] = 1;
        v1.push_back({A[i] , i});
    }
    sort(all(v1)); 
    build(0);
    for(int i = 0 ; i < n ; i++){
        root[0][i + 1] = update(0 , v1[i].Y , fn[v1[i].Y] , root[0][i]);
    }
    build(1);
    for(int i = n - 1 ; i >= 0 ; i--){
        root[1][i] = update(1 , v1[i].Y , st[v1[i].Y] , root[1][i + 1]);
    }
    while(q--){
        int x , v;
        cin >> x >> v; x--;
        int ans = LIS - mark[x];
        int lb = lower_bound(all(v1) , pii(v , -MOD)) - v1.begin();
        int ub = lower_bound(all(v1) , pii(v , +MOD)) - v1.begin();
        int cost = get(0 , 0 , x , root[0][lb]) + get(1 , x + 1 , n , root[1][ub]) + 1;
        ans = max(ans , cost);
        cout << ans << endl;
    }

    return 0;
}
/*

*/