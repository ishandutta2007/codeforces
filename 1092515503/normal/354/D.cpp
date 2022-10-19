#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[100100];
int f[100100];
int bino(int x){return x*(x+1)>>1;}
int main(){
//	freopen("tower.in","r",stdin);
//	freopen("tower.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[y].push_back(n-x+y);
	memset(f,0x3f,sizeof(f)),f[0]=0;
	for(int i=1;i<=n;i++){
		int mn=f[i-1];
		for(int j=i;j<=min(n,i+800);j++)mn=min(mn,f[j]);
		for(int j=i;j<=min(n,i+800);j++)f[j]=min(f[j],mn+bino(j-i+1)+2);
		sort(v[i].rbegin(),v[i].rend());
		for(int j=0,k=min(n,i+800);k>=i-1;k--){
			while(j<v[i].size()&&v[i][j]>k)j++;
			f[k]+=j*3;
		}
		f[i]=min(f[i],f[i-1]);
//		for(int j=i;j<=n;j++)printf("%d ",f[j]-bino(j-i+1));puts("");
	}
	printf("%d\n",f[n]);
	return 0;
}