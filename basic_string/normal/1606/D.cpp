#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
vector<int>v[N],rmin[N],rmax[N];
int lmin[N],lmax[N],p[N],ll[N],rr[N];
bool b[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,m,k,i,j,l,rm;
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=1;i<=n;++i)v[i].resize(m+1),rmin[i].resize(m+1),rmax[i].resize(m+1);
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j)cin>>v[i][j];
			rmin[i][m-1]=rmax[i][m-1]=v[i][m];
			for(j=m-2;j;--j)rmin[i][j]=min(rmin[i][j+1],v[i][j+1]),
			rmax[i][j]=max(rmax[i][j+1],v[i][j+1]);
		}
		for(k=1;k<m;++k){
			if(k==1){
				for(i=1;i<=n;++i)lmin[i]=lmax[i]=v[i][1];
			}else{
				for(i=1;i<=n;++i)lmin[i]=min(lmin[i],v[i][k]),
				lmax[i]=max(lmax[i],v[i][k]);
			}
			for(i=1;i<=n;++i)p[i]=i;
			sort(p+1,p+n+1,[](int x,int y){return lmin[x]>lmin[y];});
			ll[n]=lmax[p[n]],rr[n]=rmin[p[n]][k];
			for(i=n-1;i;--i)ll[i]=max(ll[i+1],lmax[p[i]]),
			rr[i]=min(rr[i+1],rmin[p[i]][k]);
			rm=0;
			for(i=1;i<n;++i){
				rm=max(rm,rmax[p[i]][k]);
				if(lmin[p[i]]>ll[i+1]&&rm<rr[i+1]){
					cout<<"YES\n";
					for(j=1;j<=i;++j)b[p[j]]=0;
					for(;j<=n;++j)b[p[j]]=1;
					for(j=1;j<=n;++j)if(b[j])cout<<'B';else cout<<'R';
					cout<<' '<<k<<'\n';goto gg;
				}
			}
		}
		cout<<"NO\n";
		gg:;
	}
	return 0;
}