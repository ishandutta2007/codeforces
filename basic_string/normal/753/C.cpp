#include<bits/stdc++.h>
using namespace std;
struct P{
	int a[4];	
}a;
basic_string<P>u,v;
map<pair<int,int>,int>mp;
bool f[13];
int x,y;
void dfs(int x){
	if(x>3)return void(u+=a);
	for(int i=0;i<10;++i)if(!f[i])f[i]=1,a.a[x]=i,dfs(x+1),f[i]=0;
}
bool chk(P b){
	int i,u=0,v=0;
	for(i=0;i<4;++i)if(b.a[i]==a.a[i])++u;
	for(i=0;i<4;++i)if(f[b.a[i]])++v;
	return u==x&&v-u==y;
}
void get(P b){
	int i,u=0,v=0;
	for(i=0;i<4;++i)if(b.a[i]==a.a[i])++u;
	for(i=0;i<4;++i)if(f[b.a[i]])++v;
	++mp[{u,v}];
}
int main(){
	int i,j,k,l,w,n;
	dfs(0);
	while(1){
		l=1e9,n=u.size();
		for(i=0;i<n;++i){
			a=u[i],memset(f,0,sizeof f),w=0,mp.clear();
			for(j=0;j<4;++j)f[a.a[j]]=1;
			for(auto o:u)get(o);
			for(auto o:mp)w=max(w,o.second);
			if(w<l)l=w,k=i;
		}
		a=u[k],u.erase(k,1),memset(f,0,sizeof f);
		for(i=0;i<4;++i)cout<<a.a[i],f[a.a[i]]=1;
		cout<<endl,cin>>x>>y;
		if(x==4)return 0;
		for(auto o:u)if(chk(o))v+=o;
		u=v,v.clear();
	}
	return 0;
}