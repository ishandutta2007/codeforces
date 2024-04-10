#include<bits/stdc++.h>
using namespace std;
int n,a[2001000],p[2001000],t[2001000];
bool vis[2001000];
vector<int>u,v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=i;
	for(int i=n+1;i<=2*n;i++)scanf("%d",&a[i]),a[i]=-a[i],p[i]=i;
	sort(p+1,p+2*n+1,[](int x,int y){return a[x]<a[y];});
//	for(int i=1;i<=2*n;i++)printf("%d ",p[i]);puts("");
	for(int i=1;i<=2*n;i++)t[p[i]]=p[i-a[p[i]]];
	int i=1;
	for(;!vis[i];i=t[i])vis[i]=true;
	for(;vis[i];i=t[i]){
		if(i<=n)u.push_back(i);
		else v.push_back(i-n);
		vis[i]=false;
	}
	printf("%d\n",u.size());
	for(auto i:u)printf("%d ",i);puts("");
	printf("%d\n",v.size());
	for(auto i:v)printf("%d ",i);puts("");
	return 0;
}