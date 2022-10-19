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

const ll MAXN = 2e5 + 10;
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

int n , x , ans , trieInd = 2 , pw2[MAXN] , A[MAXN] , nxt[MAXN * LOG][2] , sz[MAXN * LOG];

void Insert(int x){
    int cur = 1; sz[cur]++;
    for(int i = LOG - 1 ; i >= 0 ; i--){
        int c = 0;
        if(x & (1 << i))    c = 1;
        if(nxt[cur][c] == 0)    nxt[cur][c] = trieInd++;
        cur = nxt[cur][c];
        sz[cur]++;
    }
}

ll solve(int v , int u , int b){
    if(v == 0)  return pw2[sz[u]] - 1;
    if(u == 0)  return pw2[sz[v]] - 1;
    if(b == -1){
        return pw2[sz[v] + sz[u]] - 1;
    }
    if(x & (1 << b)){
        ll A = solve(nxt[v][0] , nxt[u][1] , b - 1);
        ll B = solve(nxt[v][1] , nxt[u][0] , b - 1);
        return (A * B + A + B) % MOD;
    }
    ll A = solve(nxt[v][0] , nxt[u][0] , b - 1) + MOD - pw2[sz[nxt[v][0]]] + MOD - pw2[sz[nxt[u][0]]] + 2;
    ll B = solve(nxt[v][1] , nxt[u][1] , b - 1) + MOD - pw2[sz[nxt[v][1]]] + MOD - pw2[sz[nxt[u][1]]] + 2;
    return (A + B + pw2[sz[v]] + pw2[sz[u]] + MOD - 2) % MOD;
}

void DFS(int v , int b){
    if((1 << (b + 1)) - 1 <= x){
        ans = (ans + pw2[sz[v]] - 1) % MOD;
        return;
    }
    if(x & (1 << b)){
        ans = (ans + solve(nxt[v][0] , nxt[v][1] , b - 1)) % MOD;
        return;
    }
    for(int i = 0 ; i < 2 ; i++){
        if(nxt[v][i] != 0){
            DFS(nxt[v][i] , b - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    pw2[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }

    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        Insert(A[i]);
    }
    DFS(1 , LOG - 1);
    cout << ans << endl;

    return 0;
}
/*

*/