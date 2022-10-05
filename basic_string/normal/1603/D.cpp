#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=100009,B=327};
int p[N/5],o,sq[N];
bool b[N];
ll s[N],f[19][N],s1[N][B],s2[N][B];
ll c(int l,int r){
	if(r/l<=sq[r])return s1[r][r/l]-s[r/l]*(l-1-r/(r/l+1));
	return s2[r][l];
}
void wk(int l,int r,int pl,int pr){
	if(l>r)return;
	int pm=pl,i,m=(l+r)/2;
	ll fm=8e18,w;
	for(i=pl;i<m&&i<=pr;++i)if((w=f[o-1][i]+c(i+1,m))<fm)fm=w,pm=i;
	f[o][m]=fm,wk(l,m-1,pl,pm),wk(m+1,r,pm,pr);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,k,t=0,T;
	for(s[1]=1,i=2;i<N;++i){
		if(!b[i])p[++t]=i,s[i]=i-1;
		for(j=1;j<=t&&(k=i*p[j])<N;++j){
			if(b[k]=1,i%p[j])s[k]=s[i]*s[p[j]];
			else{s[k]=s[i]*p[j];break;}
		}
	}
	for(i=2;i<N;++i)s[i]+=s[i-1];
	for(i=1;i<N;++i){
		for(j=1;j*j<=i;++j)s1[i][j]=s1[i][j-1]+s[j]*(i/j-i/(j+1));
		sq[i]=--j,s2[i][i/(j+1)+1]=s1[i][j];
		for(j=i/(j+1);j;--j)s2[i][j]=s2[i][j+1]+s[i/j];
	}
	for(i=1;i<N;++i)f[1][i]=c(1,i);
	for(o=2;o<17;++o)wk(1,N-1,1,N-1);
	for(cin>>T;T--;)if(cin>>i>>k,k>16)cout<<i<<'\n';
	else cout<<f[k][i]<<'\n';
}