// har ki ro didi goft mikhad beshe meslemon !
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

int x[N], y[N];

int Main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	int ans = -1;
	for(int i = 1; i <= n; i++){
		int mx = 0;
		for(int j = 1; j <= n; j++){
			mx = max(mx, abs(x[i] - x[j]) + abs(y[i] - y[j]));
		}
		if(mx <= k) ans = 1;
	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}