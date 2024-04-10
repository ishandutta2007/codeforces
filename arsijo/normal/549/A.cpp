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
const ll MAX = 1000;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

int main() {

	sync;

	int n, m;
	cin >> n >> m;

	char ar[n][m];
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	cin >> ar[i][j];

	string face = "face";
	sort(face.begin(), face.end());

	int ans = 0;

	for(int i = 1; i < n; i++)
	for(int j = 1; j < m; j++) {
		string a = "    ";
		a[0] = ar[i][j];
		a[1] = ar[i - 1][j];
		a[2] = ar[i][j - 1];
		a[3] = ar[i - 1][j - 1];
		sort(a.begin(), a.end());
		if(a == face)
		ans++;
	}

	cout << ans;

}