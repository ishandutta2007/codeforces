#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  ld ways = 0;

  vector<ll> t_cnt (26, 0);
  vector<ll> t_sum (26, 0);
  for (int i = n - 2; i >= 0; i--) {
    t_cnt[t[i + 1] - 'A']++;
    t_sum[t[i + 1] - 'A'] += i + 1;
    
    ll cnt = t_cnt[s[i] - 'A'];
    ll sum = t_sum[s[i] - 'A'];
    ways += (ll) i * (ll) n * cnt;
    ways -= (ll) i * sum;
    ways += (ll) n * cnt;
    ways -= sum;
  }

  vector<ll> s_cnt (26, 0);
  vector<ll> s_sum (26, 0);
  for (int i = n - 1; i >= 0; i--) {
    s_cnt[s[i] - 'A']++;
    s_sum[s[i] - 'A'] += i;

    ll cnt = s_cnt[t[i] - 'A'];
    ll sum = s_sum[t[i] - 'A'];
    ways += (ll) i * (ll) n * cnt;
    ways -= (ll) i * sum;
    ways += (ll) n * cnt;
    ways -= sum;
  }

  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    tot += (ll) i * (ll) i;
  }

  ld ans = (ld) ways / (ld) tot;
  cout << fixed << setprecision(12) << ans << endl;
}