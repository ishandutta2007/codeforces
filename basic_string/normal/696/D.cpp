#include<bits/stdc++.h>
using namespace std;
const int N=209;
using ll=long long;
struct M{
	ll a[N][N];
}a,z;
int id;
M mul(M a,M b){
	M c=z;
	int i,j,k;
	for(i=0;i<=id;++i)for(j=0;j<=id;++j)for(k=0;k<=id;++k)
	c.a[i][k]=max(c.a[i][k],a.a[i][j]+b.a[j][k]);
	return c;
}
void qp(M a,ll b){
	M r=z;
	int i;
	for(r.a[0][0]=0;b;b>>=1,a=mul(a,a))if(b&1)r=mul(r,a);
	ll w=0;
	for(i=0;i<=id;++i)w=max(w,r.a[0][i]);
	printf("%lld",w);
}
int f[N],c[N][26],w[N],v[N];
char s[N];
queue<int>q;
int main(){
	int n,i,j,k,l,x;
	ll o;
	scanf("%d%lld",&n,&o);
	for(i=1;i<=n;++i)scanf("%d",v+i);
	for(i=1;i<=n;++i){
		scanf("%s",s+1),l=strlen(s+1);
		for(j=1,x=0;j<=l;x=c[x][k],++j)if(k=s[j]-'a',!c[x][k])c[x][k]=++id;
		w[x]+=v[i];
	}
	for(i=0;i<26;++i)if(c[0][i])q.push(c[0][i]);
	while(q.size()){
		i=q.front(),q.pop(),k=f[i],w[i]+=w[k];
		for(j=0;j<26;++j)if(c[i][j])q.push(c[i][j]),f[c[i][j]]=c[k][j];
		else c[i][j]=c[k][j];
	}
	memset(z.a,-63,sizeof z.a),a=z;
	for(i=0;i<=id;++i)for(j=0;j<26;++j)k=c[i][j],a.a[i][k]=w[k];
	qp(a,o);
	return 0;
}