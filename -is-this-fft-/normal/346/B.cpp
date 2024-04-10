#include <iostream>
#include <string>
#include <deque>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 105;

struct State {
  int i, j, k;
  State (int _i = -1, int _j = -1, int _k = -1) : i(_i), j(_j), k(_k) {}
};

bool operator< (State s, State t) {
  return false; // all equivalent
}

bool operator== (State s, State t) {
  return s.i == t.i && s.j == t.j && s.k == t.k;
}

bool operator!= (State s, State t) {
  return !(s == t);
}

pair<int, State> dp [MAX_N][MAX_N][MAX_N]; // max len with <pos at 1, pos at 2, pos at 3>

string s3;
int lps [MAX_N];

void calc_lps () {
  int p = s3.size();
  int len = 0;
  int i = 1;
  while (i < p) {
    if (s3[i] == s3[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

int get_next_k (int pos, char nxt) {
  pos--;
  while (pos >= 0 && s3[pos + 1] != nxt) {
    pos = lps[pos] - 1;
  }

  if (pos == -1 && s3[0] != nxt) {
    return 0;
  }
  
  return pos + 2;
}

int main () {
  string s1, s2;
  cin >> s1 >> s2 >> s3;

  int n = s1.size();
  int m = s2.size();
  int p = s3.size();

  calc_lps();

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= p; k++) {
        dp[i][j][k] = make_pair(-INF, State());
      }
    }
  }

  dp[0][0][0] = make_pair(0, State());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
        if (s1[i] == s2[j]) {
          int nk = get_next_k(k, s1[i]);
          dp[i + 1][j + 1][nk] = max(dp[i + 1][j + 1][nk],
                                     make_pair(dp[i][j][k].first + 1, State(i, j, k)));
        }
      }
    }
  }

  pair<int, State> curpr = make_pair(-INF, State());
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < p; k++) {
        curpr = max(curpr, dp[i][j][k]);
      }
    }
  }

  auto cur = curpr.second;
  
  deque<char> ans;
  while (cur != State()) {
    ans.push_front(s1[cur.i]);
    auto prv = dp[cur.i][cur.j][cur.k].second;
    cur = prv;
  }

  if (ans.empty()) {
    cout << 0 << endl;
  } else {
    for (char c : ans) {
    cout << c;
    }
    cout << endl;
  }
}