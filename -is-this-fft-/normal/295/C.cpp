#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; 

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_P = 55;
const int MAX_S = 6000;

struct State {
  int skinny_l, fat_l, boat_l;

  int to_idx () {
    int idx = skinny_l;
    idx *= MAX_P;
    idx += fat_l;
    idx *= 2;
    idx += boat_l;
    return idx;
  }
};

State parse_state (int idx) {
  State s;
  s.boat_l = idx % 2;
  idx /= 2;
  s.fat_l = idx % MAX_P;
  idx /= MAX_P;
  s.skinny_l = idx;
  return s;
}

Modint choose [MAX_P][MAX_P];

int dist [MAX_S];
Modint ways [MAX_S];

int main () {
  ios::sync_with_stdio(false);

  choose[0][0] = Modint(1);
  for (int i = 1; i < MAX_P; i++) {
    choose[i][0] = Modint(1);
    for (int j = 1; j < MAX_P; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  int n, capac;
  cin >> n >> capac;
  capac /= 50;

  int skinny_t = 0, fat_t = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 50) skinny_t++;
    else fat_t++;
  }

  for (int i = 0; i < MAX_S; i++) {
    dist[i] = MAX_S;
  }
  
  State src;
  src.skinny_l = skinny_t;
  src.fat_l = fat_t;
  src.boat_l = 1;
  dist[src.to_idx()] = 0;
  ways[src.to_idx()] = Modint(1);
  
  queue<State> Q;
  Q.push(src);

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    int cur_dist = dist[cur.to_idx()];
    Modint cur_ways = ways[cur.to_idx()];

    int skinny_c = cur.boat_l ? cur.skinny_l : skinny_t - cur.skinny_l;
    int fat_c = cur.boat_l ? cur.fat_l : fat_t - cur.fat_l;

    for (int i = 0; i <= skinny_c; i++) {
      for (int j = 0; j <= fat_c; j++) {
        if (i + j == 0) continue;
        if (i + 2 * j > capac) continue;

        State nxt;
        nxt.boat_l = !cur.boat_l;
        if (cur.boat_l) {
          nxt.skinny_l = cur.skinny_l - i;
          nxt.fat_l = cur.fat_l - j;
        } else {
          nxt.skinny_l = cur.skinny_l + i;
          nxt.fat_l = cur.fat_l + j;
        }

        int nxt_dist = dist[nxt.to_idx()];
        if (nxt_dist == MAX_S) {
          dist[nxt.to_idx()] = cur_dist + 1;
          Q.push(nxt);
        }

        if (dist[nxt.to_idx()] == cur_dist + 1) {
          ways[nxt.to_idx()] += cur_ways * choose[skinny_c][i] * choose[fat_c][j];
        }
      }
    }
  }

  if (dist[0] == MAX_S) {
    cout << -1 << endl << 0 << endl;
    return 0;
  }

  cout << dist[0] << endl << ways[0] << endl;
}