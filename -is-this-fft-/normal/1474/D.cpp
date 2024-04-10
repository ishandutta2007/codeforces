#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];
ll altpr [MAX_N];

bool can_stay [MAX_N];
bool can_add [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  altpr[0] = arr[0];
  for (int i = 1; i < n; i++) {
    altpr[i] = altpr[i - 1];
    if (i % 2 == 1) {
      altpr[i] -= arr[i];
    } else {
      altpr[i] += arr[i];
    }
  }

  ll to_add = -altpr[n - 1];
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      can_stay[i] = altpr[i] <= 0;
      can_add[i] = altpr[i] + to_add <= 0;
    } else {
      can_stay[i] = altpr[i] >= 0;
      can_add[i] = altpr[i] + to_add >= 0;
    }
  }

  for (int i = 1; i < n; i++) {
    can_stay[i] &= can_stay[i - 1];
  }

  for (int i = n - 2; i >= 0; i--) {
    can_add[i] &= can_add[i + 1];
  }

  if (to_add == 0 && can_stay[n - 1]) {
    cout << "YES" << '\n';
    return;
  }

  for (int i = 0; i < n - 1; i++) {
    // try swapping i and i + 1;
    ll diff;
    if (i % 2 == 0) {
      diff = -2 * arr[i] + 2 * arr[i + 1]; 
    } else {
      diff = 2 * arr[i] - 2 * arr[i + 1];
    }

    if (to_add != diff) {
      continue;
    }

    if (i != 0 && !can_stay[i - 1]) {
      continue;
    }

    if (!can_add[i + 1]) {
      continue;
    }

    ll cur = altpr[i];
    if (i % 2 == 0) {
      cur -= arr[i];
      cur += arr[i + 1];
      if (cur < 0) {
        continue;
      }
    } else {
      cur += arr[i];
      cur -= arr[i + 1];
      if (cur > 0) {
        continue;
      }
    }

    cout << "YES" << '\n';
    return;
  }
  cout << "NO" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}