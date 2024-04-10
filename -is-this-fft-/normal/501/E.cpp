#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int cnt [MAX_N];

int cntl [MAX_N];
int cntr [MAX_N];

typedef long long ll;

int main () {
  ll n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  int cntodd = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] % 2 == 1) {
      cntodd++;
    }
  }

  if (cntodd > 1) {
    cout << 0 << endl;
    return 0;
  }

  bool palin = true;
  for (int i = 0; i < n / 2; i++) {
    if (arr[i] != arr[n - i - 1]) {
      palin = false;
    }
  }

  if (palin) {
    cout << (ll) n * (ll) (n + 1) / 2 << endl;
    return 0;
  }
  
  ll lfa = n / 2;
  for (int i = 0; i < n / 2; i++) {
    cntl[arr[i]]++;
    if (cntl[arr[i]] > cnt[arr[i]] / 2) {
      lfa = i;
      break;
    }
  }

  ll rga = n - n / 2 - 1;
  for (int i = 0; i < n / 2; i++) {
    cntr[arr[n - i - 1]]++;
    if (cntr[arr[n - i - 1]] > cnt[arr[n - i - 1]] / 2) {
      rga = n - i - 1;
      break;
    }
  }

  ll lfb = n + 5;
  ll rgb = -5;
  for (int i = 0; i < n / 2; i++) {
    if (arr[i] != arr[n - i - 1]) {
      lfb = min(lfb, (ll) i);
      rgb = max(rgb, (ll) i);
    }
  }

  ll lfc = n - rgb - 1;
  ll rgc = n - lfb - 1;

  cerr << lfa << " " << rga << " " << lfb << " " << rgb << " " << lfc << " " << rgc << endl;
  
  if (rga - lfa <= 0) {
    ll ans = (1 + lfb) * (n - rgb) + (1 + lfc) * (n - rgc) - (1 + lfb) * (n - rgc);
    cout << ans << endl;
    return 0;
  } else {
    ll ans = min(1 + lfa, 1 + lfb) * (n - rga) + (1 + lfa) * (n - max(rgb, rgc))
      - min(1 + lfa, 1 + lfb) * (n - max(rgb, rgc));
    cout << ans << endl;
    return 0;
  }
}