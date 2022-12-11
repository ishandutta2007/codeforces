#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, K;
vector<int> adj[MAXN];
int cnt[MAXN];
bool uni[MAXN];
ll ans = 0;

void dfs2(int pos, int par, int len){
    if(uni[pos]){
        ans += len;
    }
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs2(i, pos, len + 1);
    }
}

pii best = pii(1e9, 0);
void dfs1(int pos, int par){
    int mx = 0;
    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs1(i, pos);

        mx = max(mx, cnt[i]);
        cnt[pos] += cnt[i];
    }

    best = min(best, pii(max(mx, 2 * K - cnt[pos]), pos));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= K * 2; a++){
        int x;
        cin >> x;
        cnt[x] = 1;
        uni[x] = true;
    }

    for(int a = 1; a <= N - 1; a++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs1(1, -1);
    dfs2(best.second, -1, 0);
    cout << ans;
}