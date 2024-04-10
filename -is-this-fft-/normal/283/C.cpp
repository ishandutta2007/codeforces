#include <iostream>

typedef long long ll;

using namespace std;


const int MOD = 1e9 + 7;
const int MAX_N = 305;
const int MAX_T = 100005;

int prec [MAX_N];
int succ [MAX_N];
int lvl [MAX_N];

int arr [MAX_N];
int reg_arr [MAX_N];

ll dp [MAX_T];

void dfs (int vertex) {
  lvl[vertex] = lvl[prec[vertex]] + 1;
  if (succ[vertex] != 0) {
    dfs(succ[vertex]);
    reg_arr[vertex] = arr[vertex] + reg_arr[succ[vertex]];
  } else {
    reg_arr[vertex] = arr[vertex];
  }
}

int main () {
  int length, edgec;
  ll coinc;
  cin >> length >> edgec >> coinc;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < edgec; i++) {
    int b, c;
    cin >> b >> c;

    prec[b] = c;
    succ[c] = b;
  }

  for (int i = 1; i <= length; i++) {
    if (prec[i] == 0) {
      dfs(i);
    }
  }

  for (int i = 1; i <= length; i++) {
    if (lvl[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  for (int i = 1; i <= length; i++) {
    coinc -= (ll) arr[i] * ((ll) lvl[i] - 1);
  }

  if (coinc < 0) {
    cout << 0 << endl;
    return 0;
  }

  dp[0] = 1;
  for (int i = 1; i <= length; i++) {
    for (int j = 0; j + reg_arr[i] < MAX_T; j++) {
      dp[j + reg_arr[i]] += dp[j];
      dp[j + reg_arr[i]] %= MOD;
    }
  }
  cout << dp[coinc] << endl;
}