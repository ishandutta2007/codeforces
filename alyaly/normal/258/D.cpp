#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],p,q;
double dp[1001],s1[1001][1001],s2[1001][1001],s3[1001][1001],s4[1001][1001],g[1001][1001],ans;
int main(){
//	freopen("inversion.in","r",stdin);
//	freopen("inversion.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<a[i]) g[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		if(p==q) continue;
		for(int i=1;i<=n;i++){
			if(i!=p&&i!=q){
			double ss1=g[i][p],ss2=g[i][q],ss3=g[p][i],ss4=g[q][i];
			g[i][p]=g[i][q]=0.5*ss1+0.5*ss2;
			g[p][i]=g[q][i]=0.5*ss3+0.5*ss4;	
			}else if(i==p){
				g[i][q]=g[q][i]=0.5;
			}else if(i==q){
				g[p][i]=g[i][p]=0.5;
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=g[i][j];
		}
	}
	printf("%.8f\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4 5
1 2 1 1
2 3 1 2
3 2 2 2
2 3 4 2
1 4 5 1
10 1 2 1

*/