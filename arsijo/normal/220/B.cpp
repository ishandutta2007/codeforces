#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef double ld;
const int MAX = 1e6;
const int IM = 2e9;
const ld E = 1e-9;

#define DEBUG 0

struct g {
	int l, r, id;
};

bool operator<(g a, g b){
	return (a.r != b.r ? a.r < b.r : a.l < b.r);
}

int t[MAX];

void inc(int val, int i) {
	for (; i < MAX; i |= (i + 1))
		t[i] += val;
}

int sum(int i) {
	int ans = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		ans += t[i];
	return ans;
}

int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main() {

	sync;

	int n, m;
	cin >> n >> m;

	int ar[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];

	int ans[m];
	ms(ans);

	vector<g> v;

	map<int, vector<g> > vec;

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		g g;
		g.l = l - 1;
		g.r = r - 1;
		g.id = i;
		vec[r - 1].push_back(g);
	}

	ms(t);
	map<int, vector<int> > e;
	for (int i = 0; i < n; i++) {
		e[ar[i]].push_back(i);
		int a = (int) e[ar[i]].size();
		if (a >= ar[i])
			inc(1, e[ar[i]][a - ar[i]]);
		if (a > ar[i])
			inc(-2, e[ar[i]][a - ar[i] - 1]);
		if (a > ar[i] + 1)
			inc(1, e[ar[i]][a - ar[i] - 2]);
		for(int j = 0; j < (int) vec[i].size(); j++){
			ans[vec[i][j].id] = sum(vec[i][j].l, vec[i][j].r);
		}
	}

	for(int i = 0; i < m; i++)
		cout << ans[i] << endl;

}