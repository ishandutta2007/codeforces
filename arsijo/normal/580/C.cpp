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
#define x first
#define y second
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-5;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e5 + 1;
#else
const ll MAX = 1e5 + 1;
#endif

int ar[MAX];
vector<int> vec[MAX];
int m, ans = 0;

void dfs(int pos, int k = 0, int prev = -1){
	k = (ar[pos] ? k + 1 : 0);
	if(k > m)
		return;
	if(vec[pos].size() == 1 && prev != -1){
		ans++;
		return;
	}
	for(int i = 0; i < (int) vec[pos].size(); i++){
		if(vec[pos][i] != prev)
			dfs(vec[pos][i], k, pos);
	}
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> ar[i];

	for(int i = 1; i < n; i++){
		int l, r;
		cin >> l >> r;
		l--, r--;
		vec[l].push_back(r);
		vec[r].push_back(l);
	}

	dfs(0);
	cout << ans << endl;

}