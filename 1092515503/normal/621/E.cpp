#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,p,q,cnt[10];
struct mat{
	int a[110][110];
	mat(){memset(a,0,sizeof(a));}
	friend mat operator *(const mat &x,const mat &y){
		mat z;
		for(int i=0;i<q;i++)for(int j=0;j<q;j++)for(int k=0;k<q;k++)(z.a[i][j]+=1ll*x.a[i][k]*y.a[k][j]%mod)%=mod;
		return z;
	}
}I,X;
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=0,x;i<n;i++)scanf("%d",&x),cnt[x]++;
	for(int i=0;i<q;i++)for(int j=0;j<10;j++)X.a[i][(i*10+j)%q]+=cnt[j];
	for(int i=0;i<q;i++)I.a[i][i]=1;
	for(;m;X=X*X,m>>=1)if(m&1)I=I*X;
	printf("%d\n",I.a[0][p]);
	return 0;
}