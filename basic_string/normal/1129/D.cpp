#include<bits/stdc++.h>
using namespace std;
enum{B=333,N=100009,P=998244353};
int bl[N],li[B],ri[B],c[N],f[N],sum[B],tg[B],s[B][N],p[N],la[N],n,m;
void sk(int l,int r,int v){
	int i,o=bl[l];
	for(i=li[o];i<=ri[o];++i)s[o][c[i]]=0;
	for(i=li[o],sum[o]=0;i<=ri[o];++i)if(c[i]+=tg[o]+v*(l<=i&&i<=r),(s[o][c[i]]+=f[i])%=P,c[i]<=m)(sum[o]+=f[i])%=P;
	tg[o]=0;
}
void add(int l,int r,int v){
	if(l>r)return;
	if(bl[l]==bl[r])return sk(l,r,v);
	sk(l,ri[bl[l]],v),sk(li[bl[r]],r,v);
	for(int i=bl[l]+1;i<bl[r];++i)if(v==1)(sum[i]-=s[i][m-(tg[i]++)])%=P;else (sum[i]+=s[i][m-(--tg[i])])%=P;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j,x;
	for(cin>>n>>m,i=0;i<n;++i)ri[bl[i]=i/B]=i;
	for(i=n-1;~i;--i)li[bl[i]]=i;
	for(i=f[0]=1;i<=n;++i){
		cin>>x,p[i]=la[x],la[x]=i;
		add(p[p[i]],p[i]-1,-1),add(p[i],i-1,1);
		for(j=bl[i-1];~j;--j)(f[i]+=sum[j])%=P;
	}
	cout<<(f[n]+P)%P;
	return 0;
}