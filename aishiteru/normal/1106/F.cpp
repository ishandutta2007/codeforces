#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
#define P 998244353
#define PP 998244352
int n,m,d;
struct ky{
	int n,m,a[105][105];
	ky operator * (const ky&p)const{
		register ky c;c.n=n,c.m=p.m;
		for(it i=0,j,k;i<c.n;++i)
			for(j=0;j<c.m;++j)
				for(c.a[i][j]=0,k=0;k<p.m;++k)
					c.a[i][j]=(c.a[i][j]+(0ll+a[i][k])*p.a[k][j])%PP;
		return c;
	}
}o,ans;
il int ksm(it x,it L){it ans=1;while(L) L&1?ans=(0ll+ans)*x%P:0,x=(0ll+x)*x%P,L>>=1;return ans;}
il void gcd(ct a,ct b){return !b?d=a,void():gcd(b,a%b);}
map<int,int> mp;
il int bsgs(it a,it b,ct p){
	gcd(a,p);
	if(d^1) return -1;
	ct m=sqrt(p);mp.clear(),b%=p,mp[b]=0;it i;
	for(i=1;i<=m;++i) b=(0ll+b)*a%p,mp[b]=i;
	b=1,a%=p;it ans=ksm(a,m);
	for(i=1;i<=m;++i){
		b=(0ll+b)*ans%p;
		if(mp.find(b)!=mp.end()) return (((0ll+i)*m-mp[b])%p+p)%p;
	}
	return -1;
}
int main(){
	scanf("%d",&n);it i,L;
	for(i=0;i<n;++i) scanf("%d",&o.a[n-1-i][n-1]),o.a[i+1][i]=1;
	ans.a[0][n-1]=1,o.a[n][n-1]=0,o.n=o.m=n,ans.n=1,ans.m=n;
	scanf("%d%d",&L,&m),L-=n;while(L) L&1?ans=ans*o,0:0,o=o*o,L>>=1;
	i=bsgs(ksm(3,ans.a[0][n-1]),m,P),printf("%d",~i?ksm(3,i):-1);
	return 0;
}