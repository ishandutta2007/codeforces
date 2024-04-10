#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll diff [MAX_N];
ll manda [MAX_N];

void solve () {
  ll n;
  ll maxt, a, b;
  cin >> n >> maxt >> a >> b;

  ll easyc = 0, hardc = 0;
  for (ll i = 0; i < n; i++) {
    cin >> diff[i];
    if (diff[i] == 0) easyc++;
    if (diff[i] == 1) hardc++;
  }

  vector<pair<ll, ll>> events;
  for (ll i = 0; i < n; i++) {
    cin >> manda[i];
    events.push_back({manda[i] - 1, diff[i]});
  }

  sort(events.begin(), events.end());
  ll ceasyc = 0, chardc = 0, ans = 0;
  for (auto e : events) {
    ll et = e.first;

    if (0 <= et && et <= maxt) {
      ll leftover = (ll) et - (ll) ceasyc * a - (ll) chardc * b;
      ll probs = (leftover >= 0 ? ceasyc + chardc : 0);
      if (leftover >= 0) {
        if (leftover - (ll) (easyc - ceasyc) * a < 0) {
          probs += leftover / a;
        } else {
          probs += easyc - ceasyc;
          leftover -= (ll) (easyc - ceasyc) * a;

          if (leftover - (ll) (hardc - chardc) * b < 0) {
            probs += leftover / b;
          } else {
            probs += hardc - chardc;
          }
        }
      }
      ans = max(ans, probs);
    }

    // cout << e.first << " " << e.second << " " << ans << endl;
    
    ll ed = e.second;
    if (ed == 0) ceasyc++;
    else chardc++;
  }

  if ((ll) easyc * a + (ll) hardc * b <= maxt) {
    ans = easyc + hardc;
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  ll testc;
  cin >> testc;

  for (ll i = 0; i < testc; i++) {
    solve();
  }
}