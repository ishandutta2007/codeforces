#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e3+5;

int T;
int n,m,k;
int a[N],g[N],mn[N][N];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=m;++i)g[i]=max(a[i],a[i+n-m]);
		for(int i=1;i<=m;++i){
			mn[i][i]=g[i];
			for(int j=i+1;j<=m;++j)
			mn[i][j]=min(mn[i][j-1],g[j]);
		}
		k=min(k,m-1);
		int ans=0;
		for(int i=0;i<=k;++i)
		for(int j=0;i+j<=k;++j){
			int res=m-1-i-j;
			ans=max(ans,mn[i+1][i+res+1]);
		}
		cout<<ans<<endl;
	}
}