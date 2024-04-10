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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll cnt[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		for(int dx = 0; dx < 3; dx ++)
		for(int dy = 0; dy < 3; dy ++){
			cnt[x + dx][y + dy] ++;
			if(cnt[x + dx][y + dy] == 9) return cout << i + 1 << '\n', 0;
		}
	}
	cout << "-1\n";
	return 0;
}