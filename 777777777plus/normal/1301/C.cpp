#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll n,m;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		ll wa=(n-m)/(m+1);
		ll wb=wa+1;
		ll b=(n-m)%(m+1);
		ll a=m+1-b;
		ll ans=n*(n+1)/2;
		ans-=wa*(wa+1)/2*a;
		ans-=wb*(wb+1)/2*b;
		cout<<ans<<endl;
	}
}