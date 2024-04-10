#include <iostream>

using namespace std;

const int MAX_N = 1e6 + 5;
const int MAX_LG = 21; // TODO

ostream& operator<< (ostream& out, pair<int, int> p) {
  out << "(" << p.first << " " << p.second << ")";
  return out;
}

pair<int, int> mrg (pair<int, int> p, pair<int, int> q) {
  if (q > p) {
    swap(p, q);
  }

  // WLOG p.first >= q.first >= q.second

  if (q.first > p.second) {
    p.second = q.first;
  }

  return p;
}

int arr [MAX_N];
int length;

pair<int, int> dp [1 << MAX_LG];
void build (int len) {
  int all = (1 << len) - 1;
  
  for (int i = 0; i < 1 << len; i++) {
    dp[i] = make_pair(-1, -1);
  }

  for (int i = 0; i < length; i++) {
    int xi = arr[i] >> (MAX_LG - len);
    dp[all - xi] = mrg(dp[all - xi], make_pair(i, -1));
  }

  for (int k = 0; k < len; k++) {
    int m = 1 << k;
    for (int i = 0; i < 1 << len; i++) {
      if (i & m) {
        dp[i] = mrg(dp[i], dp[i - m]);
      }
    }
  }
}

bool can (int prefix, int len) {
  build(len);
  int all = (1 << len) - 1;
  for (int i = 0; i < length; i++) {
    int ai = arr[i] >> (MAX_LG - len);
    int rem = prefix - (prefix & ai);
    if (dp[all - rem].second > i) {
      return true;
    }
  }
  return false;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int i = 1; i <= MAX_LG; i++) {
    ans *= 2;
    if (can(ans + 1, i)) {
      ans++;
    }
  }

  cout << ans << endl;
}