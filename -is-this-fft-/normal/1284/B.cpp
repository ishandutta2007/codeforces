#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MAX_N = 1e5 + 5;
const ll MAX_K = 1e6 + 5;

vector<ll> seq [MAX_N];
ll mn [MAX_N];
ll mx [MAX_N];
ll asc [MAX_N];
ll nmn [MAX_K];

int main () {
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    seq[i] = vector<ll> (k);
    for (ll j = 0; j < k; j++) {
      cin >> seq[i][j];
    }
  }

  ll ascc = 0;
  for (ll i = 0; i < n; i++) {
    for (int j = 1; j < (int) seq[i].size(); j++) {
      if (seq[i][j] > seq[i][j - 1]) {
        asc[i] = 1;
      }
    }

    if (asc[i]) {
      ascc++;
    } else {
      nmn[seq[i].back()]++;
    }
  }

  for (ll i = 1; i < MAX_K; i++) {
    nmn[i] += nmn[i - 1];
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (asc[i]) {
      ans += n;
    } else {
      if (seq[i][0] != 0) {
        ans += nmn[seq[i][0] - 1] + ascc;
      } else {
        ans += ascc;
      }
    }
    // cerr << i << " " << ans << " " << seq[i].size() << " " << seq[i][0] << endl;
  }

  cout << ans << endl;
}