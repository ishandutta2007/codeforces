//Lasha Bukhnikashvili
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define Pi 3.14159265358
#define mod9 %1000000009
#define INF 1000000000
#define mod7 %1000000007
#define LL  long long
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
char ch;
 int n,m,i,j,ans,a[5001][5001],num[5001][5001],dp[5001][5001];
 void make(int l,int r){
      num[r][l]+=1;
 };
int main(){
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
 #endif
ios::sync_with_stdio(0);
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++){
            cin>>ch;
            a[i][j]=ch-'0';
            };
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++){
            if (a[i][j]==1){
               if (a[i][j-1]==0) make(j,j),dp[i][j]=j;
                  else make(dp[i][j-1],j),dp[i][j]=dp[i][j-1];
            };
    };
    for (i=1;i<=m;i++)
        for (j=1;j<=i;j++)
            num[i][j]+=num[i][j-1];
    for (i=1;i<=m;i++)
        for (j=i;j<=m;j++)
            ans=max(ans,(j-i+1)*num[j][i]);
    cout<<ans;
 return 0;
}