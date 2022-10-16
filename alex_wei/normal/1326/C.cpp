#pragma GCC optimize(3)
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define pii pair <int,int>
#define all(v) v.begin(),v.end()
#define sor(v) sort(all(v))
#define rev(v) reverse(all(v))
#define mem(v,x) memset(v,x,sizeof(v))
 
ll n,k,p[200005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>p[i];
	cout<<(n+n-k+1)*k/2<<" ";
	ll pre=1,pos;
	for(int i=1;i<=n;i++){
		if(p[i]>n-k){
			pos=i;
			break;
		}
	}
	ll ans=1;
	for(int i=pos+1;i<=n;i++){
		if(p[i]>n-k){
			ans=ans*pre%998244353;
			pre=1;
		}
		else pre++;
	}
	cout<<ans<<endl;
	return 0;
}