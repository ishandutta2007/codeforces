#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+3;
int a[N],b[N],p[N],q[N];
basic_string<long long>bs;
#define ll long long
ll d;
void exgcd(ll a,ll b,ll&x,ll&y){b?(exgcd(b,a%b,y,x),y-=a/b*x):(d=a,x=1,y=0);}
signed main(){
	int n,m,i,j;
	long long k,lcm,o,r,ans;
	scanf("%lld%lld%lld",&n,&m,&k);
	ll u,v,aa,bb,cc,x,y;
	memset(p,-1,sizeof p),memset(q,-1,sizeof q);
	for(i=0;i<n;++i)scanf("%lld",a+i),p[a[i]]=i;
	for(j=0;j<m;++j)scanf("%lld",b+j),q[b[j]]=j;
	for(i=0;i<n;++i)if(q[a[i]]!=-1){
		u=n;v=i;
		
		aa=m;bb=q[a[i]];
		exgcd(u,aa,x,y),cc=(bb-v)%aa,aa/=d,x=x*(cc/d)%aa,v+=x*u,v%=(u*=aa);
		if(cc%d==0)bs+=(u+v)%u;
	}
	sort(bs.begin(),bs.end());
	lcm=n*1ll*m/__gcd(n,m);
	o=lcm-bs.size();
	--k;
	r=k/o;
	ans=r*lcm;
	k%=o;
	for(auto i:bs){
		if(k<i)break;
		++k;
	}
	printf("%lld",ans+k+1);
	return 0;
}