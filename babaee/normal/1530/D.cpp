// Um_nlk :)))))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, T[MAXN], A[MAXN], P[MAXN], deg[MAXN];
vector<int> C[MAXN];
bool vis[MAXN];

inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], deg[A[i]]++, T[i] = A[i];
	
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			q.push(i);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		deg[A[v]]--;
		if (!deg[A[v]]) q.push(A[v]);
	}

	for (int i = 1; i <= n; i++) {
		if (!deg[i]) C[A[i]].push_back(i);
		else P[A[i]] = i, q.push(i);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int e : C[v]) {
			A[e] = v;
			A[P[v]] = e;
			P[e] = P[v];
			P[v] = e;
			q.push(e);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) 
		ans += (A[i] == T[i]);
	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << A[i] << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 10; i++) {
			C[i].clear();
			P[i] = T[i] = A[i] = deg[i] = 0;
		}

		solve();
	}
	return 0;
}