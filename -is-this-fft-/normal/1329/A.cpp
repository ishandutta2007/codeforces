#include <iostream>

using namespace std;

void failure  () {
  cout << -1 << endl;
  exit(0);
}

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll len [MAX_N];
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int on = n;
  int om = m;

  ll suml = 0;
  for (int i = 0; i < m; i++) {
    cin >> len[i];
    suml += len[i];
  }

  if (suml < n) failure();
  if (len[m - 1] + (m - 1) > n) failure();

  ans[m - 1] = n - len[m - 1] + 1;
  n -= len[m - 1];
  m--;

  while (m > 0 && len[m - 1] + (m - 1) <= n) {
    ans[m - 1] = n - len[m - 1] + 1;
    n -= len[m - 1];
    m--;
  }

  for (int i = 0; i < m; i++) {
    ans[i] = i + 1;
  }

  for (int i = 0; i < om; i++) {
    if (ans[i] > on - len[i] + 1) failure();
  }

  for (int i = 0; i < om; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}