#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n;ll ans,a[N];vector<ll>V;
inline ll chk(ll p)
{
	ll s=0;
	for(int i=1;i<=n;i++)s+=a[i]>=p?min(a[i]%p,p-a[i]%p):p-a[i];
	return s;
}
inline ll gt(ll a)
{
	ll t=a;
	for(ll j=2;j*j<=t;j++)if(t%j==0)
	{
		V.push_back(j);while(t%j==0)t/=j;
	}
	if(t>1)V.push_back(t);
}
int main()
{
	scanf("%d",&n);ans=N;srand(time(0));
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=100;i++){gt(a[i]);gt(a[i]+1);gt(a[i]-1);}
	sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++)if(!i||V[i]!=V[i-1])ans=min(ans,chk(V[i]));
	printf("%lld\n",ans);return 0;
}