#include <bits/stdc++.h>
using namespace std;

int n,m,arr[501];
int dp[501][501];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    dp[0][0]=1;
    for(int i=0;i<n;i++) {
        for(int j=m;j>=0;j--)for(int k=m;k>=0;k--) if(dp[j][k]) {
            if(j+arr[i]<=m) {
                dp[j+arr[i]][k] = dp[j+arr[i]][k+arr[i]] = 1;
            }
        }
    }

    vector<int> ans;
    for(int i=0;i<=m;i++) if(dp[m][i]) ans.push_back(i);
    printf("%lu\n",ans.size());
    for(auto &it:ans)printf("%d ",it);
    
    return 0;
}