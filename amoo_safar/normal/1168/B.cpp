#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10939;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 1e17;
const ll LOG = 30;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//ll n, m;
	//cin >> n;
	str s;
	cin >> s;
	ll n=s.size();
	ll ans =( n*(n + 1ll) )/ 2ll;
	int fl;
	for(int l = 0; l < n; l++){
		for(int r = l; r < n; r++){
			fl = 0;
			for(int x = l; x + 2 <= r; x ++){
				int k = (x + r) >> 1;
				if((x + r) & 1) continue;
				
				if(s[x] == s[k] && s[x] == s[r]){
					fl = 1;
					break;
				}
				
				if(fl) break;
			}
			if(fl) break;
			ans --;
		}
	}
	cout << ans ;
	return 0;
}