#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

pii arr[101][101];
int ans[101][101],n,m,q;

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) arr[i][j] = pii(i,j);
    for(int i=0;i<q;i++) {
        int t,r,c,x;
        scanf("%d",&t);
        if(t==1) {
            scanf("%d",&r);
            r--;
            
            pii f=arr[r][0];
            for(int j=0;j<m-1;j++) arr[r][j] = arr[r][j+1];
            arr[r][m-1] = f;
        } else if(t==2) {
            scanf("%d",&c);
            c--;

            pii f=arr[0][c];
            for(int j=0;j<n-1;j++) arr[j][c] = arr[j+1][c];
            arr[n-1][c] = f;
        } else {
            scanf("%d%d%d",&r,&c,&x);
            r--;c--;
            ans[arr[r][c].first][arr[r][c].second] = x;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}