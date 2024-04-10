#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii=pair<int,int>;

int n,m,q;
char str[1010][1010];
int vis[1010][1010],ans[1000010];

const int dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};
inline bool go(int y,int x) {return y>=0 && x>=0 && y<n && x<m;}

int bfs(int y,int x,int t) {
    queue<pii> que;
    que.push(pii(y,x));
    vis[y][x]=t;
    
    int cnt=0;
    while(!que.empty()) {
        int y=que.front().fi,x=que.front().se;
        que.pop();
        for(int k=0;k<4;k++) {
            int yy=y+dy[k],xx=x+dx[k];
            if(go(yy,xx)) {
                if(str[yy][xx]=='*') cnt++;
                else if(!vis[yy][xx]) {
                    vis[yy][xx]=t;
                    que.push(pii(yy,xx));
                }
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    
    int t=1;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(str[i][j]=='.' && !vis[i][j]) {
        ans[t] = bfs(i,j,t);
        t++;
    }
    while(q--) {
        int y,x;
        scanf("%d%d",&y,&x);
        y--;x--;
        printf("%d\n",ans[vis[y][x]]);
    }
    return 0;
}