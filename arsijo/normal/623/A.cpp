#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-9;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

const int MAX = 1000;

int col[MAX], n;

bool ar[MAX][MAX], used[MAX];

void dfs(int pos, int c){
	if(used[pos]){
		if(col[pos] != c){
			cout << "No" << endl;
			exit(0);
		}
		return;
	}
	//cout << pos << " " << c << endl;
	used[pos] = true;
	col[pos] = c;
	for(int i = 1; i <= n; i++)
		if(i != pos && ar[pos][i])
			dfs(i, 3 - c);
}

bool check(char a, char b){
	return (abs((int) a - (int) b) <= 1);
}

int main() {

	cout.precision(11);

	cout << fixed;
	sync;
	srand(time(NULL));
#ifdef LOCAL
	input;
#else

#endif

	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			ar[i][j] = true;

	ms(col, 0);

	int m;
	cin >> n >> m;
	if(n == 1){
		cout << "Yes" << endl;
		cout << "a" << endl;
		return 0;
	}
	while(m--){
		int a, b;
		cin >> a >> b;
		ar[a][b] = ar[b][a] = false;
	}

	ms(used, 0);
	for(int i = 1; i <= n; i++){
		bool ok = true;
		for(int j = 1; j <= n; j++)
			if(i != j && ar[i][j])
				ok = false;
		if(!used[i] && !ok)
			dfs(i, 1);
	}

	string res = "";
	for(int i = 1; i <= n; i++)
		res += (col[i] == 0 ? 'b' : col[i] == 1 ? 'a' : 'c');

	for(int i = 0; i < (int) res.size(); i++){
		for(int j = i + 1; j < (int) res.size(); j++){
			if(ar[i + 1][j + 1] == check(res[i], res[j])){
				cout << "No";
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
	for(int i = 1; i <= n; i++)
		cout << (col[i] == 0 ? 'b' : col[i] == 1 ? 'a' : 'c');
	cout << endl;

}