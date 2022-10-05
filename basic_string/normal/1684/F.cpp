#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],rp[N];
map<int,int>mp;
basic_string<int>p[N],w[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,id,l,r,u1,v1,u2,v2,ans,mn,mx;
	for(cin>>T;T--;cout<<max(ans,0)<<'\n'){
		cin>>n>>m,mp={},id=0,ans=1e9;
		for(i=1;i<=n;++i){
			rp[i]=0;w[i]={};
			if(cin>>a[i],!mp[a[i]])mp[a[i]]=++id,p[id]={};
			a[i]=mp[a[i]],p[a[i]]+=i;
		}
		for(i=1;i<=m;++i){
			cin>>j>>k;
			rp[j]=max(rp[j],k);
		}
		for(i=1;i<=n;++i)rp[i]=max(rp[i],rp[i-1]);
		l=1e9,r=0,mn=1e9,mx=0;
		for(i=1;i<=id;++i){
			k=p[i].size();u1=v1=u2=v2=0;
			for(j=1;j<k;++j)if(rp[p[i][j-1]]>=p[i][j]){u1=p[i][j-1],v1=p[i][j];break;}
			if(u1){
				for(j=k-1;j;--j)if(rp[p[i][j-1]]>=p[i][j]){u2=p[i][j-1],v2=p[i][j];break;}
				if(u1==u2)w[u1]+=v1,mn=min(mn,v1),mx=max(mx,u1);
				else if(rp[u1]>=v2){
					l=min(l,v1),r=max(r,u2),w[u1]+=v2,mn=min(mn,v2),mx=max(mx,u1);
				}else l=min(l,v1),r=max(r,u2);
			}
		}
		for(i=1;i<=mn&&i<=n&&i<=l;++i){
			ans=min(ans,max(r,mx)-i+1);
			for(int o:w[i])mx=max(mx,o);
		}
	}
}