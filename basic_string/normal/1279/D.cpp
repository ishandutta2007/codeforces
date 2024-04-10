
//
#include<cstdio>
#include<vector>
using std::vector;
const int N=1000009;
const long long P=998244353;
vector<int>ve[N];
int s[N];
long long qp(long long x,long long y){
	register long long r=1;
	while(y){
		if(y&1)r=r*x%P;
		x=x*x%P,y>>=1;
	}
	return r;
}
int main(){
	register int n,i,j,k;
	register long long u,v,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&j);
		while(j--)scanf("%d",&k),++s[k],ve[i].push_back(k); 
	}
	for(i=1;i<=n;++i){
		u=v=0;
		for(j=ve[i].size()-1;j>=0;--j)u+=s[ve[i][j]],v+=n;
		ans+=u%P*qp(v%P,P-2)%P;
	}
	ans=ans%P*qp(n,P-2)%P;
	printf("%lld",ans);
	return 0;
}