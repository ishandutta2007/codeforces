#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=209;
int c[27],f[3][3][N][N],g[3][3][N][N],h[N][N];
inline void upd(int&x,int y){if(x+=y,x>=P)x-=P;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,l,o,p,m,u;
	for(i=0,cin>>n;i<26;++i)cin>>c[i];
	for(i=0;i<3;++i)for(j=0;j<3;++j){
		int&k=f[i][j][(i==0)+(j==0)][(i==1)+(j==1)];
		if(i==2&&j==2)k=24*24;else if(i==2||j==2)k=24;else k=1;
	}
	for(i=2;i<n;++i){
		memcpy(g,f,sizeof g),memset(f,0,sizeof f),m=i/2+2;
		for(j=0;j<3;++j)for(k=0;k<3;++k)for(l=0;l<m;++l)for(o=0;o<m;++o)if(u=g[j][k][l][o])
		for(p=0;p<3;++p){
			if(j==p){
				if(p==2)upd(f[k][p][l][o],u*23ll%P);
			}else{
				if(p==2)upd(f[k][p][l][o],u*24ll%P);
				else if(p)upd(f[k][p][l][o+1],u);
				else upd(f[k][p][l+1][o],u);
			}
		}
	}
	for(n=n/2+2,i=0;i<26;++i)c[i]=min(c[i]+1,n);
	for(i=n;~i;--i)for(j=n;~j;--j){
		int&k=h[i][j];
		for(l=0;l<3;++l)for(o=0;o<3;++o)upd(k,f[l][o][i][j]);
		k=(k+0ll+h[i+1][j]+h[i][j+1]-h[i+1][j+1])%P;
	};
	for(i=0,k=h[0][0];i<26;++i){
		k=(k-h[c[i]][0])%P;
		for(j=0;j<i;++j)k=(k+h[c[i]][c[j]])%P;
	}
	cout<<(k+P)%P;
	return 0;
}