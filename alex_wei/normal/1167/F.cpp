/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb emplace_back

const int N=5e5+5;
const int mod=1e9+7;

ll n,a[N],c[N],d[N],e[N];
void add(int x,int v){while(x<=n)d[x]+=v,x+=x&-x;}
void add2(int x,int v){while(x<=n)e[x]+=v,x+=x&-x;}
ll query(int x){ll ans=0; while(x)ans+=d[x],x-=x&-x; return ans%mod;}
ll query2(int x){ll ans=0; while(x)ans+=e[x],x-=x&-x; return ans%mod;}
int get(int x){return n-(lower_bound(c+1,c+n+1,x)-c)+1;}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i];
	sort(c+1,c+n+1);
	ll ans=0,tmp=0;
	for(int i=1;i<=n;i++){
		int id=get(a[i]);
		tmp+=(1ll*i*(i+1)/2-query(id-1))%mod*a[i]%mod;
		tmp+=query2(id-1);
		add(id,i),add2(id,a[i]*i%mod);
		ans+=(tmp%=mod);
		ans%=mod;
	} cout<<ans<<endl;
	return 0;
}