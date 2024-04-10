//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

#define pb push_back

ll n, m;

ll p(ll a, ll b){
	if(b == 0) return 1;
	ll c = p(a, b / 2);
	if(b % 2){
		return ((c * c) % mod * a) % mod;
	}
	return (c * c) % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    cout << p(p(2, m) - 1, n);
    
    return 0;
}