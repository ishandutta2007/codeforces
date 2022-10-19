#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 2017;
const int N = M * 800 * 9;
const int F = 10;
const int inf = 1e9;

typedef array<int, 9> target;

vector<target> ts;
map<target, int> id;
int w[M];

int rem[F][M];
int add[F][M];

//vector<int> g[N];
int n;
int a[M], b[M];
int d[N];
int q[N], qs = 0, qf = 0;
bool u[N];

int enc(int floor, int state, int last) {
  assert(floor < 9);
  assert(state < (int) ts.size());
  assert(last <= n);
  return (floor + 9 * (state + ts.size() * last));
}

void dec(int num, int &floor, int &state, int &last) {
  floor = num % 9;
  num /= 9;
  state = num % ts.size();
  num /= ts.size();
  last = num;
}

void rec(int k, int rem, target cur) {
  if (k == 9) {
    id[cur] = ts.size();
    w[id[cur]] = 4 - rem;

    ts.push_back(cur);
    return;
  }
  for (int i = 0; i <= rem; ++i) {
    cur[k] = i;
    rec(k + 1, rem - i, cur);
  }
}

void calc_trans() {
  for (int i = 0; i < (int) ts.size(); ++i) {
    for (int j = 0; j < 9; ++j) {

      if (ts[i][j] > 0) {
        target cur = ts[i];
        cur[j]--;
        rem[j][i] = id[cur];
      } else {
        rem[j][i] = -1;
      }

      if (w[i] < 4) {
        target cur = ts[i];
        cur[j]++;
        add[j][i] = id[cur];
      } else {
        add[j][i] = -1;
      }
    }
  }
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }
}

//void build() {
  //for (int floor = 0; floor < 9; ++floor)
    //for (int state = 0; state < (int) ts.size(); ++state)
      //for (int i = 0; i <= n; ++i) {
        //int num = enc(floor, state, i);

        //if (i < n && a[i] == floor && w[state] < 4) {
          //g[num].push_back(enc(floor, add[b[i]][state], i + 1));
        //}

        //if (rem[floor][state] != -1) {
          //g[num].push_back(enc(floor, rem[floor][state], i));
        //}

        //if (floor + 1 < 9) {
          //g[num].push_back(enc(floor + 1, state, i));
        //}
        
        //if (floor > 0) {
          //g[num].push_back(enc(floor - 1, state, i));
        //}
      //}
//}

void bfs() {
  q[qf++] = enc(0, 0, 0);
  fill(d, d + N, inf);
  d[0] = 0;
  u[0] = true;

  auto relax = [&](int v, int to) {
    if (!u[to]) {
      u[to] = true;
      d[to] = d[v] + 1;
      q[qf++] = to;
    }
  };

  while (qs < qf) {
    int v = q[qs++];
    int floor, state, i;
    dec(v, floor, state, i);

    if (i < n && a[i] == floor && w[state] < 4) {
      relax(v, enc(floor, add[b[i]][state], i + 1));
    }

    if (rem[floor][state] != -1) {
      relax(v, enc(floor, rem[floor][state], i));
    }

    if (floor + 1 < 9) {
      relax(v, enc(floor + 1, state, i));
    }
    
    if (floor > 0) {
      relax(v, enc(floor - 1, state, i));
    }
  }

  int ans = inf;
  for (int floor = 0; floor < 9; ++floor)
    ans = min(ans, d[enc(floor, 0, n)]);
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  rec(0, 4, target());
  calc_trans();
  cerr << "|ts| = " << ts.size() << endl;
  read();
  //build();
  bfs();
}