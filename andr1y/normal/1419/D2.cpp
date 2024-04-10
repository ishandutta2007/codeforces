// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], e[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
        cin >> a[i];
	}
	sort(a, a+n);
	ll p = 0, k=0;
	for(ll i = 1;i<n;i+=2){
        e[i]=a[p++];
	}
	for(ll i = 0;i<n;i+=2){
        e[i]=a[p++];
	}
	for(ll i = 1;i+1<n;i++) if(e[i]<e[i-1]&&e[i]<e[i+1]) ++k;
	cout<<k<<'\n';
	for(ll i = 0;i<n;i++) cout<<e[i]<<' ';
}