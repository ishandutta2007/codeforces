#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int pos [MAX_N];
int fx [MAX_N];

void solve () {
  int length, tosend;
  cin >> length >> tosend;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
    fx[i] = 0;
  }
  fx[length] = 0;

  ll ans = 0;
  for (int i = 0; i < tosend; i++) {
    int a;
    cin >> a;

    if (fx[a]) {
      ans++;
    } else {
      // nothing originally below a has been queried
      ans += 2 * (pos[a] - i) + 1;
      for (int j = pos[a]; j >= 0; j--) {
        if (fx[arr[j]]) {
          break;
        }
        fx[arr[j]] = 1;
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}