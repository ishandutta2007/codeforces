#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int f[maxn];

int par[maxn], dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	
	int ptr = 0;
	for (int i = 1; i < t.size(); i++){
		while (ptr > 0 and t[ptr] != t[i]){
			ptr = f[ptr];
		}
		ptr += (t[ptr] == t[i]);
		f[i + 1] = ptr;
	}

	ptr = 0;
	int last = -1;
	for (int i = 1; i <= s.size(); i++){
		while (ptr > 0 and t[ptr] != s[i - 1]){
			ptr = f[ptr];
		}
		ptr += (t[ptr] == s[i - 1]);
		if (ptr == t.size()){
			ptr = f[ptr];
			last = i;
		}
		
		if (last != -1)
			dp[i] = (1ll * dp[i - 1] + par[last - t.size()] + (last - t.size() + 1)) % mod;	
		par[i] = (1ll * par[i - 1] + dp[i]) % mod;
	}
	cout << dp[s.size()] << endl;
}