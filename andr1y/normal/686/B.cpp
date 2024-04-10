//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 228;
ll a[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i =0;i<n;i++) cin >> a[i];
	for(ll Q = 0;Q<n;Q++){
		for(ll i =n-1;i>0;i--){
			if(a[i] < a[i-1]){
				cout << i << ' ' << i+1 << '\n';
				swap(a[i], a[i-1]);
			}
		}
	}
}