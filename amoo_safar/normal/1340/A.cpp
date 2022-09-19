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

ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll v;
		for(int i = 0; i < n; i++){
			cin >> v;
			a[v] = i;
		}
		ll fl = 1;
		for(int i = 2; i <= n; i++){
			if(a[i] != (a[i-1]+1) && a[i] > a[i - 1]) fl = 0;
		}
		cout << (fl ? "Yes\n" : "No\n");
	}
	return 0;
}