#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int dist[10][10],n;
char s[2000100];

int main() {
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++) s[i]-='0';
    
    for(int x=0;x<10;x++) {
        for(int y=0;y<10;y++) {
            for(int i=0;i<10;i++) {
                for(int j=0;j<10;j++) dist[i][j] = -1;
                
                queue<pii> que;
                que.push({i,0});
                while(!que.empty()) {
                    pii cur=que.front();que.pop();
                    
                    int v=(cur.fi+x)%10;
                    if(dist[i][v]==-1) {
                        dist[i][v] = cur.se+1; que.push({v,cur.se+1});
                    }
                    v=(cur.fi+y)%10;
                    if(dist[i][v]==-1) {
                        dist[i][v] = cur.se+1; que.push({v,cur.se+1});
                    }
                }
            }
            int ans=0;
            for(int i=1;i<n;i++) {
                if(dist[s[i-1]][s[i]]==-1) {
                    ans=-1;
                    break;
                }
                ans += dist[s[i-1]][s[i]]-1;
            }
            printf("%d ",ans);
        }
        puts("");
    }
    
    return 0;
}