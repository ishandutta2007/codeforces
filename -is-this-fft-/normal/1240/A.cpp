#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

typedef long long ll;

int length;
int arr [MAX_N];
int abonus [MAX_N];
int bbonus [MAX_N];
int ax, bx;
ll target;

bool can (int ticketc) {
  if (ticketc > length) {
    return true;
  }

  int ac = 0, bc = 0, abc = 0;
  for (int i = 1; i <= ticketc; i++) {
    if (abonus[i] && bbonus[i]) {
      abc++;
    } else if (abonus[i]) {
      ac++;
    } else if (bbonus[i]) {
      bc++;
    }
  }

  ll contrib = 0;
  for (int i = 1; i <= abc; i++) {
    contrib += (arr[i] / 100) * (ax + bx);
  }

  for (int i = abc + 1; i <= abc + ac; i++) {
    contrib += (arr[i] / 100) * ax;
  }

  for (int i = abc + ac + 1; i <= abc + ac + bc; i++) {
    contrib += (arr[i] / 100) * bx;
  }

  return contrib >= target;
}

void solve () {
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + length + 1, greater<int>());
  
  int ap;
  cin >> ax >> ap;

  int bp;
  cin >> bx >> bp;
  cin >> target;

  if (ax < bx) {
    swap(ax, bx);
    swap(ap, bp);
  }

  for (int i = 1; i <= length; i++) {
    abonus[i] = (i % ap == 0);
  }

  for (int i = 1; i <= length; i++) {
    bbonus[i] = (i % bp == 0);
  }

  if (can(length) == 0) {
    cout << -1 << '\n';
    return;
  }
  
  int ans = 0;
  for (int k = 1 << 18; k != 0; k >>= 1) {
    if (!can(ans + k)) {
      ans += k;
    }
  }

  cout << ans + 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}