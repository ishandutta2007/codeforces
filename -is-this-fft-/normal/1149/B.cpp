#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 100005;
const int MAXL = 255;

vector<int> cur_vecs [3];
int dp [MAXL][MAXL][MAXL];
int first_after [MAXN][26];
string uniword;

void add (int rel, int c) {
  cur_vecs[rel].push_back(c);
  if (rel == 0) {
    int i = cur_vecs[rel].size();
    for (int j = 0; j <= (int) cur_vecs[1].size(); j++) {
      for (int k = 0; k <= (int) cur_vecs[2].size(); k++) {
        dp[i][j][k] = MAXN;
        if (i > 0) {
          dp[i][j][k] = min(first_after[dp[i - 1][j][k]][cur_vecs[0][i - 1]] + 1, dp[i][j][k]);
        }
        if (j > 0) {
          dp[i][j][k] = min(first_after[dp[i][j - 1][k]][cur_vecs[1][j - 1]] + 1, dp[i][j][k]);
        }
        if (k > 0) {
          dp[i][j][k] = min(first_after[dp[i][j][k - 1]][cur_vecs[2][k - 1]] + 1, dp[i][j][k]);
        }
      }
    }
  } else if (rel == 1) {
    int j = cur_vecs[rel].size();
    for (int i = 0; i <= (int) cur_vecs[0].size(); i++) {
      for (int k = 0; k <= (int) cur_vecs[2].size(); k++) {
        dp[i][j][k] = MAXN;
        if (i > 0) {
          dp[i][j][k] = min(first_after[dp[i - 1][j][k]][cur_vecs[0][i - 1]] + 1, dp[i][j][k]);
        }
        if (j > 0) {
          dp[i][j][k] = min(first_after[dp[i][j - 1][k]][cur_vecs[1][j - 1]] + 1, dp[i][j][k]);
        }
        if (k > 0) {
          dp[i][j][k] = min(first_after[dp[i][j][k - 1]][cur_vecs[2][k - 1]] + 1, dp[i][j][k]);
        }
      }
    }
  } else if (rel == 2) {
    int k = cur_vecs[rel].size();
    for (int i = 0; i <= (int) cur_vecs[0].size(); i++) {
      for (int j = 0; j <= (int) cur_vecs[1].size(); j++) {
        dp[i][j][k] = MAXN;
        if (i > 0) {
          dp[i][j][k] = min(first_after[dp[i - 1][j][k]][cur_vecs[0][i - 1]] + 1, dp[i][j][k]);
        }
        if (j > 0) {
          dp[i][j][k] = min(first_after[dp[i][j - 1][k]][cur_vecs[1][j - 1]] + 1, dp[i][j][k]);
        }
        if (k > 0) {
          dp[i][j][k] = min(first_after[dp[i][j][k - 1]][cur_vecs[2][k - 1]] + 1, dp[i][j][k]);
        }
      }
    }
  }
}

void pop (int rel) {
  cur_vecs[rel].pop_back();
}        

int main () {
  ios::sync_with_stdio(false);
  int wordl, queryc;
  cin >> wordl >> queryc;
  cin >> uniword;

  for (int i = 0; i < 26; i++) {
    first_after[wordl + 2][i] = wordl + 1;
    first_after[wordl + 1][i] = wordl + 1;
    first_after[wordl][i] = wordl + 1;
  }

  for (int i = wordl - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (uniword[i] == 'a' + j) {
        first_after[i][j] = i;
      } else {
        first_after[i][j] = first_after[i + 1][j];
      }
    }
  }

  for (int i = 0; i < queryc; i++) {
    char type;
    cin >> type;

    if (type == '+') {
      int rel;
      char c;
      cin >> rel >> c;

      add(rel - 1, c - 'a');
    } else if (type == '-') {
      int rel;
      cin >> rel;

      pop(rel - 1);
    }
    
    cout << (dp[cur_vecs[0].size()][cur_vecs[1].size()][cur_vecs[2].size()] <= wordl ? "YES" : "NO") << '\n';
  }
}