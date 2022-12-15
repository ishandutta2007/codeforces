#include <bits/stdc++.h>
using namespace std;

int n,m;
char str[510][510];
int dy[]={-1,1,0,0},dx[]={0,0,-1,1};

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);

    int f=1;
    for(int i=1;i<n-1 && f;i++)for(int j=1;j<m-1;j++) if(str[i][j]=='*') {
        int cnt=0;
        for(int k=0;k<4;k++) {
            int y=i+dy[k],x=j+dx[k];
            if(str[y][x]=='*') cnt++;
        }
        if(cnt==4) {
            for(int k=0;k<4;k++) {
                int y=i+dy[k],x=j+dx[k];
                while(y>=0 && x>=0 && y<n && x<m && str[y][x]=='*') {
                    str[y][x] = '.';
                    y+=dy[k];x+=dx[k];
                }
            }
            str[i][j] = '.';
            for(int i=0;i<n && f;i++)for(int j=0;j<m;j++) if(str[i][j]=='*') {
                f=0;
                break;
            }
            if(f) {
                puts("YES");
                return 0;
            }

            break;
        }
    }
    puts("NO");

    return 0;
}