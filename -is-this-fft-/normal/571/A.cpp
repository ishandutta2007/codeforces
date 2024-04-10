#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_L = 3e5 + 5;

ll sumn (ll n) {
  return (n * (n + 1)) / 2;
}

ll sumn (ll l, ll r) {
  if (l > r) return 0LL;
  if (l == 0) return sumn(r);
  return sumn(r) - sumn(l - 1);
}

ll ways (ll lmx, ll rmx, ll mnadd, ll mxadd) {
  if (mnadd > mxadd) return 0;

  ll K = lmx + rmx;
  ll ans = (mxadd - mnadd + 1) * (K + 1);
  ans -= sumn(mnadd, mxadd);

  ans -= max(0LL, min(lmx - 1, mxadd) - mnadd + 1) * lmx;
  ans += sumn(mnadd, min(lmx - 1, mxadd));

  ans -= max(0LL, min(rmx - 1, mxadd) - mnadd + 1) * rmx;
  ans += sumn(mnadd, min(rmx - 1, mxadd));

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  vector<ll> sticks (3);
  for (int i = 0; i < 3; i++) {
    cin >> sticks[i];
  }

  ll l;
  cin >> l;

  ll ans = 0;
  for (int lng = 0; lng < 2 * MAX_L; lng++) {
    for (int i = 0; i < 3; i++) {
      if (sticks[i] <= lng && lng <= sticks[i] + l) {
        ll mxadd = l - (lng - sticks[i]);
        ll oths = 0;
        ll K = 0;
        bool ok = true;
        vector<ll> mxs;
        for (int j = 0; j < 3; j++) {
          if (j != i) {
            oths += sticks[j];
            ll mx = lng - sticks[j] - 1;
            if (j > i) mx++;
            if (mx < 0) ok = false;
            K += mx;
            mxs.push_back(mx);
          }
        }

        ll lmx = mxs[0];
        ll rmx = mxs[1];

        ll mnadd = max(0LL, lng + 1 - oths);
        mxadd = min(K, mxadd);
        if (ok) {
          /*
          cerr << lng << " " << i << " " << lmx << " " << rmx << " "
               << mnadd << " " << mxadd << " | "
               << ways(lmx, rmx, mnadd, mxadd) << endl;*/
          ans += ways(lmx, rmx, mnadd, mxadd);
        }
      }
    }
  }

  cout << ans << endl;
}