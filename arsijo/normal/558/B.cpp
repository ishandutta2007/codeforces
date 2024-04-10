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
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 10000;
//#define DEBUG
#else
const ll MAX = 1e6 + 3;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[n];
	for(int i = 0; i < n; i++)
	cin >> ar[i];

	int res = 0;
	int g[MAX];
	ms(g);

	for(int i = 0; i < n; i++)
	res = max(res, ++g[ar[i]]);

	ms(g);

	int l = 0, r = 0, la, ra;
	g[ar[0]] = 1;

	int ans = INT_MAX, maxVal = 1, index = ar[0];
	while(max(l, r) < n) {
		if(maxVal < res) {
			if(r == n - 1) {
				break;
			}
			g[ar[++r]]++;
			if(g[ar[r]] > maxVal) {
				maxVal = g[ar[r]];
				index = ar[r];
			}
		} else {
			while(ar[l] != index) {
				g[ar[l++]]--;
			}
			if(r - l + 1 < ans) {
				ans = r - l + 1;
				la = l + 1;
				ra = r + 1;
			}
			g[ar[l++]]--;
			maxVal = 0;
			r = max(r, l);
		}
	}

	cout << la << " " << ra;

}