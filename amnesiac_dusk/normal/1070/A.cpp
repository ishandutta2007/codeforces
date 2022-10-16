#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
typedef long double f80;
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool vis[505][5005];
pair<pii,int> par[505][5005];
queue<pii> q;
string solve(pii u){
    string ans = "";
    while(par[u.fi][u.se].se != -1){
        ans += to_string(par[u.fi][u.se].se);
        u = par[u.fi][u.se].fi;
    }
    ans += to_string(u.se);
    reverse(all(ans));
    return ans;
}
signed main(){
    IO;
    //freopen("inp.txt", "r", stdin);
    int d, s;
    cin >> d >> s;
    for(int i = 1; i <= 9; i++){
        if(!vis[i % d][i]){
            q.push({i % d, i});
            vis[i % d][i] = 1;
            par[i % d][i] = {{-1, -1}, -1};
        }
    }
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        if(u.fi == 0 && u.se == s){
            cout << solve({0, s});
            return 0;
        }
        for(int i = 0; i < 10; i++){
            int u1 = (u.fi * 10 + i) % d, v1 = u.se + i;
            if(v1 > s || vis[u1][v1]) continue;
            q.push({u1, v1});
            vis[u1][v1] = 1;
            par[u1][v1] = {u, i};
        }
    }
    cout << -1;
    return 0;
}