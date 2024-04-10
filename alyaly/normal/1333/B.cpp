#include<bits/stdc++.h>
//#define int long long
using namespace std;
int T,n,m,K,a[100001],b[100001],ans,ffl,g[3];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		ffl=1;
		g[1]=g[2]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++){
			if(g[1]==1&&g[2]==1) break;
			else if((g[1]==1&&a[i]>b[i])||(g[2]==1&&a[i]<b[i])||(g[1]==0&&g[2]==0&&a[i]!=b[i])){
				ffl=0;
				break;
			}
			if(a[i]==-1) g[2]=1;
			if(a[i]==1) g[1]=1;
		}
		if(ffl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}