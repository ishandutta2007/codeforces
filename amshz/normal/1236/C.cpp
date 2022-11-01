//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

#define pb push_back

ll n, a[310][310];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    ll x = 1;
    
    for(ll i = 0; i < (n + 1) / 2; i++){
    	for(ll j = 0; j < n; j++){
    		a[j][i] = x++;
		}
	}
	
	for(ll i = (n + 1) / 2; i < n; i++){
		for(ll j = n - 1; j > -1; j--){
			a[j][i] = x++;
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
    
    return 0;
}