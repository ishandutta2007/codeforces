#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , timer , st[MAXN] , fn[MAXN] , ans[MAXN] , lz[MAXN << 2];
pii seg[MAXN << 2];
vector<int> adj[MAXN] , Q[MAXN];

pii merge(pii A , pii B){
    pii ans = {min(A.X , B.X) , 0};
    if(A.X == ans.X)    ans.Y += A.Y;
    if(B.X == ans.X)    ans.Y += B.Y;
    return ans;
}

void build(int id = 1 , int l = 0 , int r = n){
    seg[id] = {0 , r - l};
    if(r - l == 1)	return;
    int mid = l + r >> 1;
    build(lc , l , mid);
    build(rc , mid , r);
    seg[id] = merge(seg[lc] , seg[rc]);
}

void shift(int id){
    lz[lc] += lz[id]; seg[lc].X += lz[id];
    lz[rc] += lz[id]; seg[rc].X += lz[id];
    lz[id] = 0;
}

void update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = n){
    if(qr <= l || r <= ql)  return;
    if(ql <= l && r <= qr){
        lz[id] += x;
        seg[id].X += x;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql , qr , x , lc , l , mid);
    update(ql , qr , x , rc , mid , r);
    seg[id] = merge(seg[lc] , seg[rc]);
}

void Print(int id = 1 , int l = 0 , int r = n){
    if(r - l == 1){
        cout << seg[id].X << sep;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    Print(lc , l , mid);
    Print(rc , mid , r);
}

void PreDFS(int v , int p = -1){
    st[v] = timer++;
    for(int u : adj[v]){
        if(u == p)	continue;
        PreDFS(u , v);
    }
    fn[v] = timer;
}

void SolveDFS(int v , int p = -1){
    for(int u : Q[v]){
        //cout << v << sep << u << sep << st[u] << sep << fn[u] << endl;
        update(st[u] , fn[u] , 1);
    }
    //cout << v << sep; Print(); cout << endl;
    ans[v] = n - (seg[1].X == 0) * seg[1].Y - 1;
    for(int u : adj[v]){
        if(u == p)  continue;
        SolveDFS(u , v);
    }
    for(int u : Q[v]){
        update(st[u] , fn[u] , -1);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i < n ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        Q[v].push_back(v);
        Q[v].push_back(u);
        Q[u].push_back(v);
        Q[u].push_back(u);
    }
    build();
    PreDFS(1);
    SolveDFS(1);
    for(int i = 1 ; i <= n ; i++){
        cout << max(0 , ans[i]) << sep;
    }

    return 0;
}
/*

*/