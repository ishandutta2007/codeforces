#include<bits/stdc++.h>
using namespace std;
map<int,int>mp; 
enum{N=100009};
int a[N],n,k,t1[N],t2[N],tot,ct[N];
void add(int x){++tot;++ct[x];
	int w=x;
	for(;x<=n;x+=x&-x)++t1[x],t2[x]+=w;
}
void del(int x){--tot;--ct[x];
		int w=x;
	for(;x<=n;x+=x&-x)--t1[x],t2[x]-=w;
}
int erf(){
	int i,x=0,w=0,o=0;
	for(i=1<<20;i;i/=2){
		if(x+i<=n&&w+t2[x+i]<=k)x+=i,w+=t2[x],o+=t1[x];
	}
	return o+min(ct[x+1],(k-w)/(x+1));
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,mx,ans=1e9,c;
	for(cin>>T;T--;){
		cin>>n>>k;ans=1e9;tot=0;
		mp={};memset(t1,0,n*4+4);memset(ct,0,n*4+4);
		memset(t2,0,n*4+4);
		for(i=1;i<=n;++i){
			cin>>a[i];
			++mp[a[i]];
		}
		for(auto o:mp)add(o.second);
		c=0;
		for(mx=0;mx<=n;++mx){
			if(c>k)break;
			ans=min(ans,tot-erf());
			if(mp[mx])del(mp[mx]);else ++c;
		}
		cout<<ans<<'\n'; 
	}
}/*
mex
<mex 
>=mex
k 
 */