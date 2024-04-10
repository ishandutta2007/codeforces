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
	ll T;
	cin >> T;
	str a, b, c;
	for(int i = 0; i < T; i++){
		cin >> a >> b >> c;
		ll fl = 1;
		for(int j = 0; j < a.size(); j++){
			if((a[j] != c[j]) && (c[j] != b[j])) fl = 0;
		}
		cout << (fl ? "YES\n" : "NO\n");
	}
	return 0;
}