#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],f[200100],g[200100],t[200100],res;
vector<int>v;
void add(int x,int y){
	while(x<=m)t[x]=max(t[x],y),x+=x&-x;
}
int sum(int x){
	int s=0;
	x=min(x,m);
	while(x)s=max(s,t[x]),x-=x&-x;
	return s;
}
int main(){
//	freopen("!dp!.in","r",stdin);
//	freopen("!dp_std_cpp.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i,v.push_back(a[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin()),m=v.size();
	for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)f[i]=sum(a[i])+1,add(a[i],f[i]),res=max(res,f[i]+1);
	memset(t,0,sizeof(t));
	for(int i=n;i>=1;i--)g[i]=sum(m-a[i]+1)+1,add(m-a[i]+1,g[i]),res=max(res,g[i]+1);
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",g[i]);puts("");
	memset(t,0,sizeof(t));
	for(int i=2;i<=n;i++){
		int tmp=upper_bound(v.begin(),v.end(),v[a[i]-1]+1)-v.begin();
//		printf("%d\n",tmp);
		res=max(res,sum(tmp)+g[i]+1);
		if(a[i-1]<=a[i])res=max(res,f[i-1]+g[i]);
		add(a[i-1],f[i-1]);
	}
	res=min(res,n);
	printf("%d\n",n-res);
	return 0;
}
/*
10
757147 167851000 301413356 336971124 659598368 160567225 391749387 4890851 35766290 26239572 
*/