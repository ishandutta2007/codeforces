#include<bits/stdc++.h>
using namespace std;
int a,b,m,dg[2003],x[100003],y[100003],ans;
int col[2003][2003];
int main(){
	cin>>a>>b>>m;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		y[i]+=a;dg[x[i]]++;dg[y[i]]++;
	}
	for(int i=1;i<=a+b;i++)
		ans=max(ans,dg[i]);
	for(int i=1;i<=m;i++){
		int j,k;
		for(j=1;j<=ans;j++)if(!col[x[i]][j])break;
		for(k=1;k<=ans;k++)if(!col[y[i]][k])break;
		col[x[i]][j]=y[i];
		col[y[i]][k]=x[i];
		if(j==k)continue;
		for(int l=k,nw=y[i];nw;nw=col[nw][l],l^=j^k)
			swap(col[nw][j],col[nw][k]);
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=ans;j++)
			if(col[x[i]][j]==y[i]){
				printf("%d ",j);
				break;
			}
}