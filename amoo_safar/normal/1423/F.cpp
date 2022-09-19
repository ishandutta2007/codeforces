// I'll Crush you !
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
	ll md = 0;
	ll n, k;
	cin >> n >> k;
	ll a, b;
	ll sm = 0;

	for(int i = 0; i < k; i++){
		cin >> a >> b; a--;
		sm += b;
		md += (a * b);
		md %= n;
	}
	if(sm != n)
		return cout << (sm < n ? 1 : -1) << '\n', 0;
	ll md2 = (n % 2 == 0 ? n / 2 : 0);
	cout << (md == md2 ? 1 : -1) << '\n';
	return 0;
}