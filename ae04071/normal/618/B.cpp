#include <bits/stdc++.h>
using namespace std;

int n,arr[50][50],vis[50];
int ans[50];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);

    for(int k=1;k<=n;k++) {
        for(int i=0;i<n;i++) if(!vis[i]){
            int f=1;
            for(int j=0;j<n;j++) if(arr[i][j] > k) {
                f=0;
                break;
            }
            if(f) {
                vis[i]=1;
                ans[i]=k;
                break;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);

    return 0;
}