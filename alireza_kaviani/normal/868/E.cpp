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

const ll MAXN = 60;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , s , m , cnt[MAXN] , W[MAXN * 2] , dp[MAXN * 2][MAXN][MAXN];
vector<int> adj[MAXN];
vector<pii> E;

void DFS(int v , int p = -1){
    for(int i : adj[v]){
        int u = E[i].Y;
        if(u == p)  continue;
        DFS(u , v);
        cnt[v] += cnt[u];
    }
}

int calc(int e , int cnt0 , int cnt1){
    if(cnt0 == 0){
        dp[e][cnt0][cnt1] = MOD;
    }
    if(cnt0 == 0 && cnt1 == 0){
        dp[e][cnt0][cnt1] = 0;
    }
    if(dp[e][cnt0][cnt1] != -1) return dp[e][cnt0][cnt1];
    int v = E[e].Y;
    if(SZ(adj[v]) == 1){
        return (dp[e][cnt0][cnt1] = calc(e ^ 1 , cnt1 , 0) + W[e]);
    }
    int l = 0 , r = MOD;
    while(r - l > 1){
        int mid = l + r >> 1 , res = 0;
        for(int i : adj[v]){
            if((i ^ e) == 1)    continue;
            int cur = 0;
            while(cur < cnt0 && calc(i , cur + 1 , cnt0 + cnt1 - cur - 1) + W[e] > mid){
                cur++;
            }
            res += cur;
        }
        if(res >= cnt0) l = mid;
        else    r = mid;
    }
    return (dp[e][cnt0][cnt1] = r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(dp , -1 , sizeof(dp));

    cin >> n;
    for(int i = 0 ; i + 1 < n ; i++){
        int v , u , w;
        cin >> v >> u >> w;
        adj[v].push_back(i * 2);
        adj[u].push_back(i * 2 + 1);
        E.push_back({v , u});
        E.push_back({u , v});
        W[i * 2] = W[i * 2 + 1] = w;
    }
    cin >> s >> m;
    for(int i = 0 ; i < m ; i++){
        int x; cin >> x;
        cnt[x]++;
    }

    DFS(s);
    int ans = MOD;
    for(int i : adj[s]){
        int v = E[i].Y;
        ans = min(ans , calc(i , cnt[v] , m - cnt[v]));
    }
    cout << ans << endl;

    return 0;
}
/*

*/