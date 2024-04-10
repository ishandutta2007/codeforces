#include <bits/stdc++.h>
using namespace std;

const int dy[]={1,0},dx[]={0,1};
char str[510][510];
int arr[2][510][510],n,m;

int sum(int k,int y1,int x1,int y2,int x2) {
    return arr[k][y2][x2] - arr[k][y1-1][x2] - arr[k][y2][x1-1] + arr[k][y1-1][x1-1];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);

    for(int k=0;k<2;k++) for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) {
        int y=i+dy[k],x=j+dx[k];
        if(str[i][j]=='.' && str[y][x]=='.') arr[k][i][j]++;
    }
    for(int k=0;k<2;k++) for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) {
        arr[k][i][j] += arr[k][i-1][j] + arr[k][i][j-1] - arr[k][i-1][j-1];
    }

    int q;
    scanf("%d",&q);
    while(q--) {
        int y1,x1,y2,x2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        
        printf("%d\n",sum(0,y1,x1,y2-1,x2) + sum(1,y1,x1,y2,x2-1));
    }

    return 0;
}