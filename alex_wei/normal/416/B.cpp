#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e4+5;
int t[N][6],m,n,ans[N];
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>t[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans[j]=max(ans[j],ans[j-1])+t[j][i];
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}