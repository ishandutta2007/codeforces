#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;
const int K = 26;
vector<int> G[N];
int tin[N], tout[N], par[N];
bool valid[N][K];
vector<int> paths[N];
string words[N];
int use[N][2];

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int timer = 1;
  function<void(int, int)> dfs = [&] (int v, int p) {
    par[v] = p;
    tin[v] = timer++;
    for (int u: G[v]) {
      if (u != p) {
        dfs(u, v);
      }
    }
    tout[v] = timer++;
  };
  dfs(1, 1);

  function<bool(int, int)> anc = [&] (int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
  };

  function<vector<int>(int, int)> path = [&] (int u, int v) {
    vector<int> ans(1, u);
    while (!anc(ans.back(), v)) {
      ans.push_back(par[ans.back()]);
    }
    vector<int> other(1, v);
    while (other.back() != ans.back()) {
      other.push_back(par[other.back()]);
    }
    other.pop_back();
    reverse(other.begin(), other.end());
    ans.insert(ans.end(), other.begin(), other.end());
    return ans;
  };

  for (int v = 1; v <= n; v++) {
    for (int c = 0; c < K; c++) {
      valid[v][c] = 1;
    }
  }

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y >> words[i];
    paths[i] = path(x, y);
    int k = words[i].size();
    for (int j = 0; j < k; j++) {
      int v = paths[i][j];
      char a = words[i][j];
      char b = words[i][k-j-1];
      for (char c = 'a'; c <= 'z'; c++) {
        if (c != a && c != b) {
          valid[v][c-'a'] = 0;
        }
      }
    }
  }

  // variable i (0 <= i <= q-1): word i is in forward direction
  // variable i+q-1 (1 <= i <= n): use the first character of vertex i
  TwoSat solver(n+q);
  for (int v = 1; v <= n; v++) {
    int index = 0;
    use[v][0] = -1;
    use[v][1] = -1;
    for (int c = 0; c < K; c++) {
      if (valid[v][c]) {
        use[v][index++] = c;
      }
      if (index == 2) break;
    }
    if (use[v][1] == -1) {
      solver.setValue(v+q-1);
    }
    if (use[v][0] == -1) {
      solver.setValue(~(v+q-1));
    }
  }

  for (int i = 0; i < q; i++) {
    int k = words[i].size();
    for (int j = 0; j < k; j++) {
      bool b = (words[i][j] != words[i][k-1-j]);
      if (words[i][j]-'a' == use[paths[i][j]][0]) {
        solver.either(~i, paths[i][j]+q-1);
        if (b) solver.either(~(paths[i][j]+q-1), i);
      }
      else if (words[i][j]-'a' == use[paths[i][j]][1]) {
        solver.either(~i, ~(paths[i][j]+q-1));
        if (b) solver.either(paths[i][j]+q-1, i);
      }
      else {
        solver.setValue(~i);
      }

      if (words[i][k-1-j]-'a' == use[paths[i][j]][0]) {
        solver.either(i, paths[i][j]+q-1);
        if (b) solver.either(~(paths[i][j]+q-1), ~i);
      }
      else if (words[i][k-1-j]-'a' == use[paths[i][j]][1]) {
        solver.either(i, ~(paths[i][j]+q-1));
        if (b) solver.either(paths[i][j]+q-1, ~i);
      }
      else {
        solver.setValue(i);
      }
    }
  }

  if (!solver.solve()) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  for (int v = 1; v <= n; v++) {
    int c = (solver.values[v+q-1] ? use[v][0] : use[v][1]);
    cout << (char)(c+'a');
  }
  cout << '\n';
}