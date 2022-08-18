#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

int ans [MAX_N];

int cover (int x) {
  return (1 << (__lg(x) + 1)) - 1;
}

int main () {
  int n;
  cin >> n;

  int cur_mx = n; // max unassigned
  while (cur_mx > 0) {
    int mask = cover(cur_mx);
    int sta = mask ^ cur_mx;
    for (int i = sta; i <= cur_mx; i++) {
      ans[i] = i ^ mask;
    }
    cur_mx = sta - 1;
  }

  ll tot = 0;
  for (int i = 0; i <= n; i++) {
    tot += i ^ ans[i];
  }

  cout << tot << '\n';
  for (int i = 0; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}