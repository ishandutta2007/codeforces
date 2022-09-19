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

// int dif[N], a[N];

int sum = 0;


int a[N];
int Main(){
	int n;
	cin >> n;
	int u, v;
	cin >> u >> v;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int mx = 0;
	for(int i = 2; i <=n; i++)
		mx = max(mx, abs(a[i] - a[i - 1]));
	if(mx == 0) cout << min(u + v, v + v) << '\n';
	else if(mx == 1) cout << min(u, v) << '\n';
	else cout << 0 << '\n';

}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --) Main();
	return 0;
}