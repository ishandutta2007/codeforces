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
typedef long double ld;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

vector<int> vec[MAX], ans;
int a[MAX], b[MAX];

void dfs(int pos, int prev = -1, int x = 0, int y = 0, int d = 0){
	a[pos] = (a[pos] + (d % 2 == 0 ? x : y)) % 2;
	if(a[pos] != b[pos]){
		ans.push_back(pos + 1);
		if(d % 2 == 0){
			x++;
		}else{
			y++;
		}
	}
	for(int i = 0; i < (int) vec[pos].size(); i++)
		if(vec[pos][i] != prev)
			dfs(vec[pos][i], pos, x, y, d + 1);
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	dfs(0);
	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << endl;

}