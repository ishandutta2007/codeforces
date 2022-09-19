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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N], c[N];
ll pa[N], pc[N];

int Main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < m; i++){
		cin >> c[i];
	}
	int L = 0, R = min(n, m) + 1;
	int mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		int fl = 1;
		for(int i = n - 1, j = mid; j >= 1; j --, i--){
			if(a[i] < mid) fl = 0;
		}
		if(fl) L = mid;
		else R = mid;
	}
	pc[0] = 0;
	for(int i = 1; i <= m; i++) pc[i] = pc[i - 1] + c[i - 1];
	pa[0] = 0;
	for(int i = 1; i <= n; i++) pa[i] = pa[i - 1] + c[a[i - 1] - 1];

	// debug(pa[2]);
	ll ans = Inf;
	for(int i = 0; i <= L; i++){
		ans = min(ans, pc[i] + pa[n - i]);
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