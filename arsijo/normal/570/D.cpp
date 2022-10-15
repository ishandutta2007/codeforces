#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<ii>::iterator vit;
typedef double ld;
typedef int** matrix;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 101;
///#define DEBUG
#else
const ll MAX = 5e5 + 5;
#endif

vector<int> to[MAX];
vector<ii> vec[MAX];
int H[MAX], timer = 0, tin[MAX], tout[MAX];
string s;

void dfs(int pos = 0, int h = 1){
	H[pos] = h;
	tin[pos] = ++timer;
	vec[h].push_back(make_pair(timer, vec[h].back().second ^ (1 << (s[pos] - 'a'))));
	for(int i = 0; i < (int) to[pos].size(); i++)
		dfs(to[pos][i], h + 1);
	tout[pos] = ++timer;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < MAX; i++)
		vec[i].push_back(make_pair(0, 0));

	for(int i = 1; i < n; i++){
		int t;
		cin >> t;
		to[t - 1].push_back(i);
	}

	cin >> s;

	dfs();

	while(m--){

		int v, h;
		cin >> v >> h;
		v--;

		vit v1 = upper_bound(vec[h].begin(), vec[h].end(), make_pair(tin[v], -1));
		vit v2 = upper_bound(vec[h].begin(), vec[h].end(), make_pair(tout[v], -1));

		int a = (--v1)->second ^ (--v2)->second;

		cout << ( a & (a - 1) ? "No" : "Yes") << endl;

	}

}