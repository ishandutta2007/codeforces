#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

#define ran(i, a, b) for (auto i = (a); i < (b); i++)

template <typename T>
void rsort(T *a, T *b, int size, int d = sizeof(T) - 1) {
  int b_s[256]{};
  ran(i, 0, size) { ++b_s[(a[i] >> (d * 8)) & 255]; }
  // ++b_s[*((uchar *)(a + i) + d)];
  T *mem[257];
  mem[0] = b;
  T **l_b = mem + 1;
  l_b[0] = b;
  ran(i, 0, 255) { l_b[i + 1] = l_b[i] + b_s[i]; }
  for (T *it = a; it != a + size; ++it) {
    T id = ((*it) >> (d * 8)) & 255;
    *(l_b[id]++) = *it;
  }
  l_b = mem;
  if (d) {
    T *l_a[256];
    l_a[0] = a;
    ran(i, 0, 255) l_a[i + 1] = l_a[i] + b_s[i];
    ran(i, 0, 256) {
      if (l_b[i + 1] - l_b[i] < 100) {
        sort(l_b[i], l_b[i + 1]);
        if (d & 1) copy(l_b[i], l_b[i + 1], l_a[i]);
      } else {
        rsort(l_b[i], l_a[i], b_s[i], d - 1);
      }
    }
  }
}

const int nmax = 1e7 + 3e6;

ll arr [nmax], tmp [nmax];

const int MOD = 1e9 + 7;
const int MAX_N = 5e3 + 5;

pair<int, int> root [MAX_N];
int rnk [MAX_N];

pair<int, int> find (int u) {
  if (root[u].first != u) {
    pair<int, int> pr = find(root[u].first);
    root[u].first = pr.first;
    root[u].second *= pr.second;
  }
  return root[u];
}

bool cycle (int u, int v) {
  pair<int, int> ur = find(u);
  pair<int, int> vr = find(v);

  return (ur == vr); // same root, same parity
}

int compc;
void merge (int u, int v) {
  pair<int, int> ur = find(u);
  pair<int, int> vr = find(v);

  if (ur.first != vr.first) {
    compc--;
    if (rnk[ur.first] < rnk[vr.first]) {
      root[ur.first].first = vr.first;
      root[ur.first].second = ur.second * vr.second * -1;
    } else {
      root[vr.first].first = ur.first;
      root[vr.first].second = ur.second * vr.second * -1;
    }

    if (rnk[ur.first] == rnk[vr.first]) {
      rnk[ur.first]++;
    }
  }
}

int x [MAX_N];
int y [MAX_N];

int dist (int p, int q) {
  return abs(x[p] - x[q]) + abs(y[p] - y[q]);
}

bool comp (pair<int, int> p, pair<int, int> q) {
  return dist(p.first, p.second) > dist(q.first, q.second);
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = make_pair(i, 1);
  }
  
  ios::sync_with_stdio(false);

  int pointc;
  cin >> pointc;

  for (int i = 1; i <= pointc; i++) {
    cin >> x[i] >> y[i];
  }

  int ordsz = 0;
  for (int i = 1; i <= pointc; i++) {
    for (int j = i + 1; j <= pointc; j++) {
      arr[ordsz] = 2e4 - dist(i, j);
      arr[ordsz] <<= 13;
      arr[ordsz] += i;
      arr[ordsz] <<= 13;
      arr[ordsz] += j;
      ordsz++;
    }
  }

  rsort(arr, tmp, ordsz);
  
  compc = pointc;
  vector<pair<int, int>> buf;
  for (int i = 0; i < ordsz; i++) {
    buf.push_back(make_pair((arr[i] % (1 << 26)) >> 13,
                            (arr[i] % (1 << 13))));
    
    if (i == ordsz - 1 || (arr[i] >> 26) < (arr[i + 1] >> 26)) {
      // clear the buffer
      int cur_compc = compc;
      while (!buf.empty()) {
        pair<int, int> pr = buf.back();
        buf.pop_back();
        
        if (cycle(pr.first, pr.second)) {
          cout << dist(pr.first, pr.second) << endl;
          ll ansc = 1;
          for (int i = 0; i < cur_compc; i++) {
            ansc *= 2;
            ansc %= MOD;
          }
          cout << ansc << endl;
          return 0;
        }
        merge(pr.first, pr.second);
      }
    }
  }

  cout << 0 << endl;
  ll ansc = 1;
  for (int i = 0; i < compc; i++) {
    ansc *= 2;
    ansc %= MOD;
  }
  cout << ansc << endl;
}