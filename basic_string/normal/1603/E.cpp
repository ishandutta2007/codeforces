#include<bits/stdc++.h>
using namespace std;
enum{N=209};
int jc[N],ijc[N],p,a1,f[N][N][27],b[N][N][27],n;
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;return r;}
int dfs(int i,int s,int k){
	if(!k)return jc[n]*1ll*ijc[n-i]%p;
	if(b[i][s][k]==a1)return f[i][s][k];
	int&w=f[i][s][k],c=(a1-s)/k;
	for(w=0,b[i][s][k]=a1;c>=0&&(k<2||i+c>=n+2-a1-k);--c)w=(w+dfs(i+c,s+c*k,k-1)*1ll*ijc[c])%p;
	return w;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,w=0;
	for(cin>>n>>p,jc[0]=i=1;i<N;++i)jc[i]=jc[i-1]*1ll*i%p;
	for(ijc[i=N-1]=qp(jc[N-1],p-2);i;--i)ijc[i-1]=ijc[i]*1ll*i%p;
	for(a1=max(1,n-(int)sqrt(n/2)*2-2);a1<=n;++a1)w=(w+dfs(0,0,n+1-a1))%p;
	cout<<w;
	return 0;
}