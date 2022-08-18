#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1005;

pair<int, pair<int, int>> tree [MAX_N][MAX_N];

void add (int idx, int jdx, pair<int, pair<int, int>> val) {
  for (int i = idx; i < MAX_N; i += i & -i) {
    for (int j = jdx; j < MAX_N; j += j & -j) {
      tree[i][j] = max(tree[i][j], val);
    }
  }
}

pair<int, pair<int, int>> get (int idx, int jdx) {
  pair<int, pair<int, int>> ans = make_pair(0, make_pair(-1, -1));
  for (int i = idx; i > 0; i -= i & -i) {
    for (int j = jdx; j > 0; j-= j & -j) {
      ans = max(ans, tree[i][j]);
    }
  }
  return ans;
}

int A [MAX_N];
int B [MAX_N];
int dp [MAX_N][MAX_N];
pair<int, int> last [MAX_N][MAX_N];
int big [MAX_N];

int main () {
  int alen;
  cin >> alen;

  map<int, int> compr;
  for (int i = 1; i <= alen; i++) {
    cin >> A[i];
    compr[A[i]] = 0;
  }

  int blen;
  cin >> blen;

  for (int i = 1; i <= blen; i++) {
    cin >> B[i];
    compr[B[i]] = 0;
  }

  int cur = 1;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    big[cur] = it->first;
    cur++;
  }

  for (int i = 1; i <= alen; i++) {
    A[i] = compr[A[i]];
  }

  for (int i = 1; i <= blen; i++) {
    B[i] = compr[B[i]];
  }

  pair<int, pair<int, int>> best = make_pair(-1, make_pair(-1, -1));
  for (int i = 1; i <= alen; i++) {
    for (int j = 1; j <= blen; j++) {
      if (A[i] == B[j]) {
        pair<int, pair<int, int>> res = get(A[i] - 1, j - 1);
        dp[i][j] = res.first + 1;
        last[i][j] = res.second;
      }
    }

    for (int j = 1; j <= blen; j++) {
      if (A[i] == B[j]) {
        add(A[i], j, make_pair(dp[i][j], make_pair(i, j)));
        best = max(best, make_pair(dp[i][j], make_pair(i, j)));
      }
    }
  }

  if (best.first == -1) {
    cout << 0 << endl << endl;
    return 0;
  }
  cout << best.first << '\n';
  vector<int> ans;
  for (pair<int, int> curp = best.second; curp.first > 0; curp = last[curp.first][curp.second]) {
    // cerr << curp.first << " " << curp.second << endl;
    ans.push_back(big[A[curp.first]]);
  }

  reverse(ans.begin(), ans.end());
  for (int u : ans) {
    cout << u << " ";
  }  
  cout << '\n';
}