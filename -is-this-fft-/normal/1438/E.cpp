#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

typedef long long ll;

ll arr [MAX_N];
ll pref [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + arr[i];
  }

  ll glob_add = 0;
  set<pair<ll, int>> prefs;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    for (auto it = prefs.begin(); it != prefs.end(); it++) {
      if (it->first + glob_add > arr[i]) {
        break;
      }

      int l = it->second;
      if ((arr[l] ^ arr[i]) == pref[i - 1] - pref[l]) {
        ans++;
      }
    }
    
    prefs.insert(make_pair(-arr[i - 1] - glob_add, i - 1));
    glob_add += arr[i];
  }

  cout << ans << '\n';
}