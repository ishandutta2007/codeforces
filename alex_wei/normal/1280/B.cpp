#include<bits/stdc++.h>
using namespace std ;
const int N=65;
int t,n,m,a[N][N];
bool L(int i){
	for(int j=1;j<=m;j++)
		if(a[i][j]!=1)
			return 0;
	return 1;
}
bool R(int j){
	for(int i=1;i<=n;i++)
		if(a[i][j]!=1)
			return 0;
	return 1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ans=5;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char p;
				cin>>p;
				a[i][j]=p=='A';
			}
		int check=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!a[i][j])
					check=0;
		if(check)ans=0; 
		if(L(1)||R(1)||L(n)||R(m))ans=min(ans,1);
		if(a[1][1]||a[n][m]||a[n][1]||a[1][m])ans=min(ans,2);
		for(int i=1;i<=n;i++)if(L(i))ans=min(ans,2);
		for(int i=1;i<=m;i++)if(R(i))ans=min(ans,2);
		for(int i=1;i<=n;i++)if(a[i][1]||a[i][m])ans=min(ans,3);
		for(int j=1;j<=m;j++)if(a[1][j]||a[n][j])ans=min(ans,3); 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j])ans=min(ans,4);
		if(ans<5)cout<<ans<<endl;
		else cout<<"MORTAL\n"; 
	}
	return 0 ;
}