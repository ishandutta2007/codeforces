#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
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
const int MAX = 1e5 + 1;
const ld E = 1e-11;


int main() {

	sync;

	int n;
	cin >> n;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	sort(ar, ar + n);

	ll ans = 0;
	for(int i = 1; i < n; i++)
		if(ar[i] <= ar[i - 1]){
			ans += ar[i - 1] - ar[i] + 1;
			ar[i] = ar[i - 1] + 1;
		}

	cout << ans;

}