#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;

bool check(ll x){
	for(ll i = 2; i * i <= x; i++)
		if(x % i == 0)
			return 0;
	return 1;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		if((a - b) == 1 && check(a + b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}