#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int t;
ll x;
map<ll, bool> is_cube;

int main(){
	cin >> t;
	for(ll i = 1; i <= 10000; i++) is_cube[i * i * i] = 1;
	while(t--){
		cin >> x;
		bool ok = 0;
		for(ll i = 1; i <= 10000; i++){
			if(is_cube[x - i * i * i]){
				ok = 1;
				break;
			}
		}
		if(!ok) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}