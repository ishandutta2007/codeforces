#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
//#define x first
//#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 400010;
const ld E = 1e-11;

int *ar, n, m;

bool solve(ll x){
	int g[n];
	memcpy(g, ar, sizeof(g));
	int pos = n - 1;
	for(int i = 0; i < m; i++){
		while(pos >= 0 && g[pos] == 0)
			pos--;
		ll y = x - (pos + 1);
		if(y <= g[pos]){
			g[pos] -= y;
		}else{
			y -= g[pos];
			g[pos] = 0;
			pos--;
			while(pos >= 0){
				if(y <= g[pos]){
					g[pos] -= y;
					break;
				}
				y -= g[pos];
				g[pos--] = 0;
			}
		}
	}
	while(pos >= 0 && g[pos] == 0)
		pos--;
	return (pos < 0);
}

int main() {

	sync;

	cin >> n >> m;
	ar = new int[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	ll l = 1, r = LONG_LONG_MAX - 1;
	while(l + 1 < r){
		ll x = (l + r) >> 1;
		if(solve(x))
			r = x;
		else
			l = x;
	}
	cout << (solve(l) ? l : r);

}