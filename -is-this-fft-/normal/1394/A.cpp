#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int ceil (int p, int q) {
  return (p + q - 1) / q;
}

ll mutpref [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, d, m;
  cin >> n >> d >> m;

  vector<ll> mut;
  vector<ll> nonmut;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x > m) mut.push_back(x);
    else nonmut.push_back(x);
  }

  sort(mut.begin(), mut.end(), greater<ll>());
  sort(nonmut.begin(), nonmut.end(), greater<ll>());
  if (!mut.empty()) {
    mutpref[0] = mut[0];
  }
  for (int i = 1; i < MAX_N; i++) {
    mutpref[i] = mutpref[i - 1];
    if (i < (int) mut.size()) {
      mutpref[i] += mut[i];
    }
  }

  ll ans = 0;
  ll lft = 0;
  for (int i = 0; i <= (int) nonmut.size(); i++) {
    int rgt = ceil(n - i, d + 1);
    ans = max(ans, lft + mutpref[rgt - 1]);
    
    if (i != (int) nonmut.size()) {
      lft += nonmut[i];
    }
  }

  cout << ans << endl;
}