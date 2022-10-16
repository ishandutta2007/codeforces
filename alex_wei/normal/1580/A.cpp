// orz 1849285087
#include <bits/stdc++.h>
using namespace std;

const int N=400+5;
char mp[N][N];
int n,m,ans,f[N],s[N][N];
void solve(){
	cin>>n>>m,ans=1e9;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		cin>>mp[i][j],s[i][j]=s[i-1][j]+mp[i][j]-'0';
	for(int i=1;i<=n;i++)
		for(int j=i+4;j<=n;j++){
			int pre=1e9,cur=0;
			for(int k=1;k<=m;k++){
				if(k>3)pre=min(pre,f[k-3]);
				int nd=s[j-1][k]-s[i][k];
				ans=min(ans,pre+cur+(f[k]=j-i-1-nd));
				cur+=nd+(mp[i][k]=='0')+(mp[j][k]=='0'),f[k]-=cur;
			}
		} cout<<ans<<endl;
}
int main(){
	int T; cin>>T;
	while(T--)solve();
	return 0;
}