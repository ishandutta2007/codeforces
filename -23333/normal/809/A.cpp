#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+777;
const ll mo=1e9+7;
ll a[N],q[N],h[N],t[N];
ll n,ans;
int main(){
	//freopen("p.in","r",stdin);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(int i=n;i>=1;i--)h[n-i+1]=h[n-i]+a[i];
	
	t[0]=1;
	for(int i=1;i<=n;i++)
	t[i]=t[i-1]*2%mo;
	for(int i=1;i<n;i++)
	ans=(ans+((h[i]-q[i])%mo)*t[n-i-1])%mo;
	cout<<ans;
	return 0;
}