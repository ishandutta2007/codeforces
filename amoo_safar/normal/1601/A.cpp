// vaziat meshki-ghermeze !
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

ll cnt[40];

int Main(){
	memset(cnt, 0, sizeof cnt);
	int n;
	cin >> n;
	int v;
	for(int i = 0; i < n; i++){
		cin >> v;
		for(int j = 0; j < 32; j++) cnt[j] += (v >> j) & 1;
	}
	ll g = 0;
	for(int i = 0; i < 40; i++) g = __gcd(g, cnt[i]);
	for(int k = 1; k <= n; k++) if(g % k == 0) cout << k << ' ';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}