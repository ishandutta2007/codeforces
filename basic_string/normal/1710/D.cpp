#include<bits/stdc++.h>
using namespace std;
enum{N=2009};
char s[N][N];
struct D{
	int f[N];
	int gf(int x){while(x!=f[x])x=f[x]=f[f[x]];return x;}
}L,R;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int c[2],T,n,i,j,k,u,v,r,w,o;
	bool b;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>(s[i]+i),L.f[i]=R.f[i]=i;
		for(i=1;i<=n;++i)for(j=1,k=i;k<=n;++j,++k)if(s[j][k]=='1'){
			u=L.gf(j),v=L.gf(k);
			if(u==v)continue;
			r=R.gf(k),w=R.gf(j),L.f[v]=u,R.f[w]=r,cout<<j<<' '<<k<<'\n';
			b=0,c[0]=k,c[1]=j;
			for(++w;w!=v;w=o+1,b=!b){
				o=R.gf(w),L.f[w]=u,R.f[o]=r;
				cout<<w<<' '<<c[b]<<'\n',c[b]=w;
			}
		}
	}
}