#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

const int mxN = 200005;
vector<int> adj[mxN];
vector<int> nei[mxN];
int out[mxN];
int in[mxN];
int deg[mxN];
int dp[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        out[a] ++;
        in[b] ++;
    }
    for(int i = 1; i <= n; i ++) {
        for(int ne : adj[i]) {
            if(out[i] > 1 && in[ne] > 1) {
                nei[ne].push_back(i);
                deg[i] ++;
            }
        }
    }
    deque<int> bfs;
    for(int i = 1; i<= n; i ++) {
        if(deg[i] == 0) {
            bfs.push_back(i);
            dp[i] = 1;
        }
    }
    while(bfs.size()) {
        int cur = bfs.back();
        bfs.pop_back();

        for(int p : nei[cur]) {
            dp[p] = max(dp[p],dp[cur]+1);
            deg[p] --;
            if(deg[p] == 0) {
                bfs.push_front(p);
            }
        }
    }
    int res = 0;
    for(int i = 1; i<= n; i ++) {
        res = max(res,dp[i]);
    }
    cout << res;
    return 0;
}