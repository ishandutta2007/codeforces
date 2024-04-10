#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
int val[200005];
int vis[200005];
int dp1[200005], dp2[200005];
bool canret[200005];
bool pos;

void dfs(int n, int p, int t){
    vis[n] = t;
    dp1[n] = dp2[n] = 0;
    canret[n] = 1;
    int mx1 = 0, mx2 = 0, tot = 0, cnt = 0, idx = 0;
    for(int e : graph[n]){
        if(e != p){
            if(val[e] < t){
                canret[n] = 0;
                cnt = 2;
                continue;
            }
            dfs(e, n, t);
            if(canret[e]){
                tot += dp1[e];
            }
            else {
                cnt++;
                canret[n] = 0;
                if(mx1 <= dp1[e]){
                    mx2 = mx1;
                    mx1 = dp1[e];
                }
                else if(mx2 < dp1[e]){
                    mx2 = dp1[e];
                }
            }
        }
    }
    if(cnt == 0){
        dp2[n] = tot+1;
    }
    else if(cnt == 1){
        for(int e : graph[n]){
            if(!canret[e] && e != p){
                dp2[n] = dp2[e] + tot + 1;
            }
        }
    }
    dp1[n] = mx1 + tot + 1;
    dp2[n] = max(mx2+mx1+tot+1, dp2[n]);
    if(mx2+mx1+tot+1 >= K){
        pos = 1;
    }
}

bool solve(int t){
    pos = 0;
    for(int n = 1; n<=N; n++){
        if(vis[n] != t && val[n] >= t){
            dfs(n, 0, t);
            int cnt = 0;
            for(int e : graph[n]){
                if(val[e] < t){
                    cnt = 2;
                }
                else if(!canret[e]){
                    cnt++;
                }
            }
            if(cnt == 1){
                if(dp2[n] >= K){
                    return 1;
                }
            }
        }
    }
    return pos;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int l = 1, r = 1000000, ans = 0;
    while(l <= r){
        int mid = l+r>>1;
        if(solve(mid)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}