#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=309;
int m;
basic_string<int>g[N];
map<int,int>id;
int a[N],b[N],c[M][M];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,o,o2,i,j,k,l,l2,u,vv,ans,nown,nowm,ct;
	cin>>T;
	while(T--){
		cin>>n>>m,o=n*m,ans=0,nown=1,nowm=0,ct=0,id={};
		for(i=1;i<=o;++i)cin>>a[i],b[i]=a[i];
		sort(b+1,b+o+1),o2=unique(b+1,b+o+1)-b-1;
		for(i=1;i<=o2;++i)id[b[i]]=++ct;
		for(i=1;i<=ct;++i)g[i]={};
		for(i=1;i<=o;++i)g[id[a[i]]]+=i;
		for(i=1;i<=ct;++i){
			l=g[i].size(),l2=l;
			for(j=nowm+1,k=0;j<=min(nowm+l,m);++j){
				vv=g[i][k];c[nown][j]=vv;
				for(u=1;u<=nowm;++u)if(c[nown][u]<vv)++ans;
				++k;
			}
			if(nowm+l<m){nowm+=l;continue;}
			l-=(m-nowm);
			while(l>=m)l-=m,++nown;
			++nown,nowm=l;
			for(j=1,k=l2-1;j<=l;++j){
				c[nown][j]=g[i][k];--k;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}