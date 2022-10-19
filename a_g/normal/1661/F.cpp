#include <bits/stdc++.h>
using namespace std;

const long long INF = 5e18;

long long f(int x, int k) {
  // minimum energy for segment of length x with k portals
  if (k < 0) return INF;
  k++;
  if (k >= x) return x;
  int small = x/k;
  return 1LL * (k-x%k) * small * small + 1LL * (x%k) * (small+1) * (small+1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n-1; i >= 1; i--) {
    a[i] -= a[i-1];
  }
  long long m;
  cin >> m;
  long long low = 0;
  long long high = 1e18;
  int portals;
  long long energy;
  function<void(long long)> calc = [&] (long long mid) {
    portals = 0;
    energy = 0;
    for (int val: a) {
      int ilow = 0;
      int ihigh = val;
      while (ihigh-ilow > 1) {
        int imid = (ilow+ihigh)/2;
        if (f(val, imid-1) - f(val, imid) > mid) ilow = imid;
        else ihigh = imid;
      }
      portals += ilow;
      energy += f(val, ilow);
    }
  };
  while (high - low > 1) {
    // add teleporters with benefit > x
    // find smallest x for which this is insufficient
    long long mid = (low+high)/2;
    calc(mid);
    if (energy > m) high = mid;
    else low = mid;
  }
  calc(high);
  long long deficit = energy-m;
  portals += (deficit+high-1)/high;
  cout << portals << '\n';
}