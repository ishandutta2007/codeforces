#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int INF = 1e9;
int dist[3001][3001];
int vis[3001],n,m;
vector<int> adj[3001];

void bfs(int s,int *dist) {
    fill(vis,vis+n+1,0);

    queue<int> que;
    que.push(s);
    vis[s]=1;
    while(!que.empty()) {
        int cur=que.front();que.pop();
        for(auto &it:adj[cur]) if(!vis[it]) {
            vis[it]=1;
            dist[it]=dist[cur]+1;
            que.push(it);
        }
    }
    for(int i=1;i<=n;i++) if(i==s || !vis[i]) dist[i] = -INF;
}

pii dout[3001][3], din[3001][3];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++) bfs(i,dist[i]);

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++) dout[i][j] = din[i][j] = pii(-INF, 0);
        for(int j=1;j<=n;j++) if(j!=i) {
            for(int k=0;k<3;k++) if(dout[i][k].first < dist[i][j]) {
                for(int t=2;t>k;t--) dout[i][t] = dout[i][t-1];
                dout[i][k] = pii(dist[i][j],j);
                break;
            }
            for(int k=0;k<3;k++) if(din[i][k].first < dist[j][i]) {
                for(int t=2;t>k;t--) din[i][t] = din[i][t-1];
                din[i][k] = pii(dist[j][i],j);
                break;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(i!=j) {
        for(int a=0;a<3;a++)for(int b=0;b<3;b++) {
            if(i!=dout[j][b].second && j!=din[i][a].second && 
                    din[i][a].second != dout[j][b].second) {
                ans = max(ans, din[i][a].first + dout[j][b].first + dist[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(i!=j) {
        for(int a=0;a<3;a++)for(int b=0;b<3;b++) {
            if(i!=dout[j][b].second && j!=din[i][a].second && 
                    din[i][a].second != dout[j][b].second) {
                if(ans == din[i][a].first + dout[j][b].first + dist[i][j]) {
                    printf("%d %d %d %d\n",din[i][a].second,i,j,dout[j][b].second);
                    return 0;
                }
            }
        }
    }

    return 0;
}