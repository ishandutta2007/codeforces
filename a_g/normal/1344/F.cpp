#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
bitset<N> masks[N/2][2];

// masks[i][0] = bottom bit
// masks[i][1] = top bit

// R = 01
// Y = 10
// B = 11

bitset<N> solve(vector<pair<bitset<N>, int>>& equations) {
  int m = equations.size();
  for (int i = 0; i < m; i++) {
    int lowest = N;
    int ind = -1;
    for (int j = i; j < m; j++) {
      if (equations[j].first._Find_first() < lowest) {
        lowest = equations[j].first._Find_first();
        ind = j;
      }
    }

    if (lowest == N) break;
    swap(equations[ind], equations[i]);
    for (int j = 0; j < m; j++) {
      if (j == i) continue;
      if (equations[j].first[lowest]) {
        equations[j].first ^= equations[i].first;
        equations[j].second ^= equations[i].second;
      }
    }
  }

  bitset<N> ans;
  for (int i = 0; i < m; i++) {
    if (equations[i].first == 0) {
      if (equations[i].second != 0) {
        cout << "NO\n";
        exit(0);
      }
    }
    else {
      ans[equations[i].first._Find_first()] = equations[i].second;
    }
  }
  return ans;
}

int color_to_int(char c) {
  if (c == 'W') return 0;
  if (c == 'R') return 1;
  if (c == 'Y') return 2;
  if (c == 'B') return 3;
  assert(0);
}

char int_to_color(int k){
  return ".RYB"[k];
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    masks[i][0][2*i] = 1;
    masks[i][1][2*i+1] = 1;
  }

  vector<pair<bitset<N>, int>> equations;

  for (int i = 0; i < k; i++) {
    string s;
    int m;
    cin >> s >> m;
    vector<int> indices(m);
    for (int& x: indices) {
      cin >> x;
      x--;
    }
    if (s == "RY") {
      for (int x: indices) {
        swap(masks[x][0], masks[x][1]);
      }
    }
    else if (s == "RB") {
      for (int x: indices) {
        masks[x][1] ^= masks[x][0];
      }
    }
    else if (s == "YB") {
      for (int x: indices) {
        masks[x][0] ^= masks[x][1];
      }
    }
    else {
      assert(s == "mix");
      char c;
      cin >> c;
      for (int j = 0; j < 2; j++) {
        bitset<N> sum;
        for (int x: indices) {
          sum ^= masks[x][j];
        }
        equations.emplace_back(sum, (((color_to_int(c)>>j)&1) > 0));
      }
    }
  }

  bitset<N> ans = solve(equations);
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << int_to_color(ans[2*i]+(ans[2*i+1]<<1));
  }
  cout << '\n';
}