#include<bits/stdc++.h>
using namespace std;
int n,q,x,y;
int fa[1003],sz[1003];
int fnd(int X){
	if(fa[X]!=X)
		fa[X]=fnd(fa[X]);
	return fa[X];
}
bool cmp(int a,int b){return a>b;}
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++)
		fa[i]=i,sz[i]=1;
	vector<int>v;
	int cnt=1;
	while(q--){
		scanf("%d%d",&x,&y);
		x--;y--;
		if(fnd(x)!=fnd(y)){
			sz[fnd(y)]+=sz[fnd(x)];
			sz[fnd(x)]=0;
			fa[fnd(x)]=fnd(y);
		}else
			cnt++;
		v.clear(); 
		for(int i=0;i<n;i++)
			v.push_back(sz[i]);
		sort(v.begin(),v.end(),cmp);
		int ans=0;
		for(int i=0;i<cnt;i++)
			ans+=v[i];
		printf("%d\n",ans-1);
	}
}