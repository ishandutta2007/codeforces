#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 300005;

typedef long long ll;

ll x [maxn], y [maxn], ans [maxn];

vector<pair<ll, ll>> people;

ll suffys [maxn];
ll prefxs [maxn];

int main () {
  ios::sync_with_stdio(false);
  
  ll peoplec, hatec;
  cin >> peoplec >> hatec;

  for (ll i = 0; i < peoplec; i++) {
    cin >> x[i] >> y[i];
    people.push_back(make_pair(x[i] - y[i], i));
  }

  sort(people.begin(), people.end());

  for (ll i = 0; i < peoplec; i++) {
    if (i != 0) {
      prefxs[i] = prefxs[i - 1];
    }
    prefxs[i] += x[people[i].second];
  }

  for (ll i = peoplec - 1; i >= 0; i--) {
    suffys[i] = suffys[i + 1] + y[people[i].second];
  }
  
  for (ll i = 0; i < peoplec; i++) {
    ll cur = people[i].second;
    ans[cur] += (ll) i * y[cur];
    if (i != 0) {
      ans[cur] += prefxs[i - 1];
    }
    ans[cur] += (ll) (peoplec - i - 1) * x[cur];
    ans[cur] += suffys[i + 1];
  }
 
  for (ll i = 0; i < hatec; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;

    ll score = min(x[u] + y[v], x[v] + y[u]);
    ans[u] -= score;
    ans[v] -= score;
  }

  for (ll i = 0; i < peoplec; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}