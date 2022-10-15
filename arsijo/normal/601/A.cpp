#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define x first
#define y second
#define y1 blabla
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-7;
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

int ar[400][400], n;

int bfs(int a, int b, int t){
	queue<int> q;
	q.push(a);
	bool used[n];
	ms(used, 0);
	int dist[n];
	for(int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[a] = 0;
	used[a] = 1;
	while(!q.empty()){
		int v = q.front();
//		cout << v << endl;
		q.pop();
		if(v == b)
			return dist[b];
		for(int i = 0; i < n; i++){
	//		cout << ar[v][i] << " " << t << endl;
			if(i != v && ar[v][i] == t && !used[i]){
				q.push(i);
				used[i] = true;
				dist[i] = dist[v] + 1;
			}
		}
	}
	//cout << "D" << endl;
	return INT_MAX;
}

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int m;
	cin >> n >> m;

	ms(ar, 0);

	while(m--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ar[a][b] = ar[b][a] = 1;
	}

	int res = max(bfs(0, n - 1, 1), bfs(0, n - 1, 0));
	cout << (res == INT_MAX ? -1 : res);

}