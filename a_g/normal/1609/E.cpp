#include <bits/stdc++.h>
using namespace std;

class segtree {
  public:
    int n;
    vector<vector<int>> dp;
    // a, b, c, ab, bc, abc
    segtree (int n, string& s): n(n) {
      dp.resize(4*n, vector<int>(6));
      init(0, 0, n-1, s);
    }
    int query() {
      return dp[0][5];
    }
    void update (int v, int tl, int tr, int i, char c) {
      if (tl == tr) {
        dp[v][0] = c == 'a';
        dp[v][1] = c == 'b';
        dp[v][2] = c == 'c';
      }
      else {
        int tm = (tl+tr)/2;
        if (tm >= i) update(2*v+1, tl, tm, i, c);
        else update(2*v+2, tm+1, tr, i, c);
        combine(v);
      }
    }
    void update(int i, char c) {
      update(0, 0, n-1, i, c);
    }
    void combine(int v) {
      dp[v][0] = dp[2*v+1][0] + dp[2*v+2][0];
      dp[v][1] = dp[2*v+1][1] + dp[2*v+2][1];
      dp[v][2] = dp[2*v+1][2] + dp[2*v+2][2];
      dp[v][3] = min(dp[2*v+1][0] + dp[2*v+2][3], dp[2*v+1][3]+dp[2*v+2][1]);
      dp[v][4] = min(dp[2*v+1][1] + dp[2*v+2][4], dp[2*v+1][4]+dp[2*v+2][2]);
      dp[v][5] = min({
          dp[2*v+1][0] + dp[2*v+2][5],
          dp[2*v+1][3]+dp[2*v+2][4],
          dp[2*v+1][5]+dp[2*v+2][2]
          });
    }

    void init(int v, int tl, int tr, string& s) {
      if (tl == tr) {
        char c = s[tl];
        dp[v][0] = c == 'a';
        dp[v][1] = c == 'b';
        dp[v][2] = c == 'c';
      }
      else {
        int tm = (tl+tr)/2;
        init(2*v+1, tl, tm, s);
        init(2*v+2, tm+1, tr, s);
        combine(v);
      }
    }

    void debug(int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << '\n';
      if (tl != tr) {
        int tm = (tl+tr)/2;
        debug(2*v+1, tl, tm);
        debug(2*v+2, tm+1, tr);
      }
    }
    void debug() {
      debug(0, 0, n-1);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;

  segtree st(n, s);

  while (q--) {
    int p;
    char c;
    cin >> p >> c;
    st.update(p-1, c);
    cout << st.query() << '\n';
  }
}