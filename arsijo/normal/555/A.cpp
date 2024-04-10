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

	int ans = n - 1;

	while(m--){
		int a;
		cin >> a;
		int ar[a];
		ans += a - 1;
		for(int i = 0; i < a; i++)
			cin >> ar[i];
		if(ar[0] == 1){
			for(int i = 1; i < a && ar[i] == ar[i - 1] + 1; i++)
				ans -= 2;
		}
	}

	cout << ans;
}