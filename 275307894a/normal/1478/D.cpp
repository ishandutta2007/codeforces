#include<cstdio>
#define ll long long
using namespace std;
const int N=2e5+10;
int T,n;
ll k,x[N];
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		for(int i=0;i<n;i++)scanf("%lld",&x[i]);
		ll g=x[1]-x[0];
		for(int i=2;i<n;i++)g=gcd(g,x[i]-x[0]);
		if((k-x[0])%g==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}