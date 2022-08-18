#include <iostream>
#include <queue>

using namespace std;

const int MAX_S = 20; 
const int MAX_B = 1 << MAX_S;

pair<int, int> closest [MAX_B]; // <dist, idx>

void add (int pos, int idx) {
  queue<int> Q;
  
  closest[pos] = make_pair(0, idx);
  Q.push(pos);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    
    for (int k = 0; k < MAX_S; k++) {
      int nxt = cur ^ (1 << k);
      if (closest[nxt].first > closest[cur].first + 1) {
        closest[nxt] = make_pair(closest[cur].first + 1, idx);
        Q.push(nxt);
      }
    }
  }
}

int swap (int mask, int i, int j) {
  int ati = (mask >> i) & 1;
  int atj = (mask >> j) & 1;

  mask -= ati << i;
  mask -= atj << j;
  mask += ati << j;
  mask += atj << i;
  return mask;
}

const int MAX_N = 2e6 + 5;

int init [MAX_S];
int tar [MAX_S];
int tarpos [MAX_S];

void swaptar (int u, int v) {
  swap(tarpos[u], tarpos[v]);
}

int K;
int maketar () {
  int mask = 0;
  for (int i = 0; i < K; i++) {
    mask += tar[i] << tarpos[i];
  }
  return mask;
}

int makeinit () {
  int mask = 0;
  for (int i = 0; i < K; i++) {
    mask += init[i] << tarpos[i];
  }
  return mask;
}

bool is_add_at [MAX_N];
pair<int, int> add_at [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_B; i++) {
    closest[i] = make_pair(25, -1);
  }

  int n, m;
  cin >> n >> m >> K;

  for (int i = 0; i < K; i++) {
    char c;
    cin >> c;

    init[i] = c - '0';
  }

  for (int i = 0; i < K; i++) {
    char c;
    cin >> c;

    tar[i] = c - '0';
    tarpos[i] = i;
  }

  add_at[m] = make_pair(makeinit(), 1);
  is_add_at[m] = 1;
  int ans = 25;
  int ansl = -1, ansr = -1;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    swaptar(u, v);
    if (is_add_at[i]) {
      add(add_at[i].first, add_at[i].second);
    }
    add_at[i + m] = make_pair(makeinit(), i + 1);
    is_add_at[i + m] = 1;
    
    auto pr = closest[maketar()];

    if (pr.first < ans) {
      ans = pr.first;
      ansl = pr.second;
      ansr = i;
    }
  }

  cout << K - ans << endl;
  cout << ansl << " " << ansr << endl;
}