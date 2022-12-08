#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
bool works(const vi &a,ll n,ll r,ll k,ll x){
	ll sum=0;
	vi delta(n,0);
	for(int i=0;i<=r;i++){
		sum+=a[i];
	}
	for(int i=0;i<n;i++){
		if(sum<x){
			delta[min(n-1,i+r)]+=x-sum;
			k-=x-sum;
			if(k<0){
				return 0;
			}
			sum=x;
		}
		if(i-r>=0){
			sum-=a[i-r];
			sum-=delta[i-r];
		}
		if(i+r+1<n){
			sum+=a[i+r+1];
		}
	}
	return k>=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,r,k;
	cin>>n>>r>>k;
	if(r==n) r=n-1;
	vi a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	ll lo=0,hi=2e18;
	while(lo<hi){
		ll mid=(lo+hi+1)/2;
		if(works(a,n,r,k,mid))lo=mid;
		else hi=mid-1;
	}
	cout<<lo<<endl;
}