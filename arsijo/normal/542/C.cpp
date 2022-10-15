#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
//#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 1e5;
const ld E = 1e-11;

ll nsd(ll a, ll b){
	while(a != 0 && b != 0)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

ll nsk(ll a, ll b){
	return a / nsd(a, b) * b;
}

int main() {

	sync;

	int n;
	cin >> n;

	int to[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> to[i];

	ll ans = 1, b = 0;

	for(int j = 1; j <= n; j++){
		int t[n + 1];
		memset(t, -1, sizeof(t));
		int x = j, l = 0;
		for(x = j, l = 0; t[x] == -1; x = to[x])
			t[x] = l++;
		ans = nsk(ans, l - t[x]);
		b = max(b, (ll) t[x]);
	}
	ll a = 1;
	while(a * ans < b)
		a++;
	cout << a * ans;

}