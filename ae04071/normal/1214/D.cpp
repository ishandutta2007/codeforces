#include <bits/stdc++.h>
using namespace std;

char str[1000100];
int n,m,dn;
vector<vector<int>> arr,vis;

const int dy[]={1,0},dx[]={0,1};
bool go(int y,int x) {
    return y>=0 && x>=0 && y<n && x<m && !vis[y][x] && !arr[y][x];
}

int df;
bool dfs_path(int y,int x) {
    if(y==n-1 && x==m-1) return true;
    vis[y][x] = 1;
    for(int k=0;k<2;k++) {
        int yy=y+dy[k^df],xx=x+dx[k^df];
        if(go(yy,xx)) {
            if(dfs_path(yy,xx)) {
                vis[y][x] = 2;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%s",str);
        arr.push_back(vector<int>(m, 0));
        for(int j=0;j<m;j++) arr[i][j] = str[j]=='#';
        vis.push_back(vector<int>(m, 0));
    }

    if(!dfs_path(0,0)) {
        puts("0");
    } else {
        if(n==1 || m==1) puts("1");
        else {
            for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(vis[i][j]) vis[i][j]--;
            vis[0][0] = vis[n-1][m-1] = 0;
            df = 1;
            if(dfs_path(0,0)) puts("2");
            else puts("1");
        }
    }
    
    return 0;
}