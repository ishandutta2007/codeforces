#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int MOD;
struct Modint {
  ll val;

  Modint ()
    : val(0) {}
  
  Modint (ll _val)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) {
    return val == other.val;
  }

  Modint exp (int k) {
    if (k == 0) {
      return Modint(1);
    } else if (k % 2 == 0) {
      Modint half = exp(k / 2);
      return half * half;
    } else {
      return (*this) * exp(k - 1);
    }
  }

  Modint inv () {
    return exp(MOD - 2);
  }

  bool nonzero () {
    return val != 0;
  }
};

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

Modint det (vector<vector<Modint>> mat) {
  int N = (int) mat.size();
  Modint ans (1);
  for (int i = 0; i < N; i++) {
    int pivot = -1;
    for (int j = i; j < N; j++) {
      if (mat[j][i].nonzero()) {
        pivot = j;
      }
    }

    if (pivot == -1) {
      return Modint(0);
    }

    if (i != pivot) {
      ans = -ans;
      swap(mat[i], mat[pivot]);
    }
      
    Modint mulby = mat[i][i].inv();
    ans *= mat[i][i];
    for (int j = 0; j < N; j++) {
      mat[i][j] *= mulby;
    }

    for (int j = i + 1; j < N; j++) {
      if (mat[j][i].nonzero()) {
        Modint c = mat[j][i];
        for (int k = 0; k < N; k++) {
          mat[j][k] -= c * mat[i][k];
        }
      }
    }
  }
  return ans;
}

const int MAX_N = 605;

int vertexc, sinkc;

vector<int> sources;
vector<int> sinks;
vector<int> outgoing [MAX_N];
vector<int> incoming [MAX_N];

Modint ways [MAX_N];
bool vis [MAX_N];

void dfs (int u) {
  vis[u] = 1;
  for (int nxt : incoming[u]) {
    if (!vis[nxt]) {
      dfs(nxt);
    }
    ways[u] += ways[nxt];
  }
}

void calc_ways (int src, vector<vector<Modint>> &magic) {
  for (int i = 1; i <= vertexc; i++) {
    ways[i] = Modint(0);
    vis[i] = 0;
  }

  ways[src] = Modint(1);
  vis[src] = 1;

  for (int i = 1; i <= vertexc; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  vector<Modint> row;
  for (int u : sinks) {
    row.push_back(ways[u]);
  }
  magic.push_back(row);
}

int main () {
  ios::sync_with_stdio(false);

  int edgec;
  cin >> vertexc >> edgec >> MOD;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    incoming[v].push_back(u);
    outgoing[u].push_back(v);
  }

  for (int i = 1; i <= vertexc; i++) {
    if (incoming[i].empty()) {
      sources.push_back(i);
    }
    
    if (outgoing[i].empty()) {
      sinks.push_back(i);
    }
  }

  vector<vector<Modint>> magic;
  for (int u : sources) {
    calc_ways(u, magic);
  }

  cout << det(magic) << endl;
}