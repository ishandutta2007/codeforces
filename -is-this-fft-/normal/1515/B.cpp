#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e9 + 5;

set<int> sqs;

void solve () {
  int x;
  cin >> x;

  if (x % 2 == 0 && sqs.count(x / 2)) {
    cout << "YES" << '\n';
    return;
  }

  if (x % 4 == 0 && sqs.count(x / 4)) {
    cout << "YES" << '\n';
    return;
  }

  cout << "NO" << '\n';
}

int main () {
  for (int i = 0; i * i < MAX_N; i++) {
    sqs.insert(i * i);
  }

  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}