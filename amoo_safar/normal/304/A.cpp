#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll ans = 0;
	for(int a = 1; a <= n; a++){
		int p = a;
		for(int b = a; b <= n; b++){
			while(a*a + b*b > p*p) p++;
			if(a*a + b*b == p*p && p <= n) ans ++;
		}
	}
	cout << ans << '\n';
	return 0;
}