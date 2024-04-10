#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
//#ifdef LOCAL
  //assert(freopen("d.in", "r", stdin));
//#endif

  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  map<int, int> cnt;
  
  n = k + 1;
  for (int i = 0; i < n; ++i) {
    cout << "? ";
    for (int j = 0; j < n; ++j)
      if (j != i)
        cout << j + 1 << " ";
    cout << endl;

    int pos, val;
    cin >> pos >> val;

    cnt[val]++;
  }

  assert(cnt.size() == 2);
  cout << "! " << cnt.rbegin()->second << endl;
}