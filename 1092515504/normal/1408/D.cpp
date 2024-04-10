#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[2010],b[2010],c[2010],d[2010],res=0x3f3f3f3f,g[1001000];
vector<pair<int,int> >v;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]); 
	for(int i=1;i<=m;i++)scanf("%d%d",&c[i],&d[i]); 
	for(int i=1;i<=m;i++){
		bool ok=true;
		for(int j=1;j<=m;j++)if(i>j&&c[i]<=c[j]&&d[i]<=d[j])ok=false;
		if(ok)v.push_back(make_pair(c[i],d[i]));
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		for(auto j:v){
			int k=j.first-a[i];
			if(k<0)continue;
			g[k]=max(g[k],max(0,j.second-b[i]+1));
		}
	}
	for(int i=v.back().first+1;i>=0;i--)g[i]=max(g[i],g[i+1]);
	for(int i=0;i<=v.back().first+1;i++)res=min(res,i+g[i]);
	printf("%d\n",res);
	return 0;
}