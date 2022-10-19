#include <bits/stdc++.h>
using namespace std;

// KACTL

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
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    // variable k*i+j: a[i] is at least j+1
    TwoSat solver(k*n);
    for (int i = 0; i < n; i++) {
      solver.setValue(k*i);
      for (int j = 0; j < k-1; j++) {
        solver.either(k*i+j, ~(k*i+j+1));
      }
    }
    for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < k; j++) {
        solver.either(~(k*i+j), (k*(i+1)+j));
      }
    }

    while (m--) {
      int type;
      cin >> type;
      if (type == 1) {
        int i, x;
        cin >> i >> x;
        i--;
        if (x == k) {
          solver.setValue(~(k*i+k-1));
        }
        else {
          solver.either(k*i+x, ~(k*i+(x-1)));
        }
      }
      else {
        int i, j, x;
        cin >> i >> j >> x;
        i--, j--;
        for (int u = 0; u < k; u++) {
          for (int v = 0; v < k; v++) {
            if (type == 2 && u+v+2 > x) {
              solver.either(~(k*i+u), ~(k*j+v));
            }
            else if (type == 3 && u+v < x) {
              solver.either(k*i+u, k*j+v);
              if (x > k) {
                int d = x-k-1;
                solver.setValue(k*i+d);
                solver.setValue(k*j+d);
              }
            }
          }
        }
      }

    }

    if (!solver.solve()) {
      cout << "-1\n";
      continue;
    }
    vector<int> a(n, k);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k-1; j++) {
        if (solver.values[k*i+j] && !solver.values[k*i+j+1]) {
          a[i] = j+1;
          break;
        }
      }
    }
    for (int x: a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}