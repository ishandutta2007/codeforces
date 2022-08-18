#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX_P = 59;
const int PRIMEC = 16;
const int MAX_N = 105;
const short INF = 1 << 14;

int sieve [MAX_P];
short dp [MAX_N][1 << PRIMEC];
short last [MAX_N][1 << PRIMEC];
int arr [MAX_N];
int mask [MAX_P];
int idx [MAX_P];

void make_mask (int x) {
  int cur = x;
  while (cur != 1) {
    mask[x] |= 1 << idx[sieve[cur]];
    cur /= sieve[cur];
  }
}

int main () {
  ios::sync_with_stdio(false);

  int cur_id = 0;
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      idx[i] = cur_id;
      cur_id++;
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = i;
      }
    }
  }

  for (int i = 1; i < MAX_P; i++) {
    make_mask(i);
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 1 << PRIMEC; j++) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << PRIMEC; j++) {
      if (dp[i][j] != INF) {
        for (int k = 1; k < MAX_P; k++) {
          if (!(j & mask[k])) {
            short nxt = dp[i][j] + abs(k - arr[i]);
            if (nxt < dp[i + 1][j | mask[k]]) {
              dp[i + 1][j | mask[k]] = nxt;
              last[i + 1][j | mask[k]] = k;
            }
          }
        }
      }
    }
  }

  pair<int, int> best = make_pair(INF, 0);
  for (int j = 0; j < 1 << PRIMEC; j++) {
    best = min(best, make_pair((int) dp[n][j], j));
  }

  int cur = best.second;
  deque<int> ans;
  for (int i = n; i > 0; i--) {
    int l = last[i][cur];
    ans.push_front(l);
    cur -= mask[l];
  }

  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}