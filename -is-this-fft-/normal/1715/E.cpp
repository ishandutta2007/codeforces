#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;

const int MAX_N = 1e5 + 5;
const ll INF = 1e18 + 2000;

vector<pair<int, ll>> adj [MAX_N];

vector<ll> dijkstra (vector<ll> dist) {
  int n = dist.size();
  ipq<pair<ll, int>> Q;
  for (int i = 0; i < n; i++) {
    Q.push({dist[i], i});
  }

  vector<int> vis (n, 0);
  while (!Q.empty()) {
    auto cur = Q.top().second;
    Q.pop();

    if (vis[cur]) continue;
    vis[cur] = 1;

    for (auto e : adj[cur]) {
      dist[e.first] = min(dist[e.first], e.second + dist[cur]);
      Q.push({dist[e.first], e.first});
    }
  }

  return dist;
}

ll sq (ll x) {
  return x * x;
}

ll meet (ll a, ll b, ll c, ll d) {
  return (d - b + a - c + 1) / (a - c);
}

vector<ll> smooth (vector<ll> arr) {
  int n = arr.size();

  vector<pair<ll, ll>> stk; // start, index
  for (ll i = 0; i < n; i++) {
    while (true) {
      if (stk.empty()) {
        stk.push_back({0, i});
        break;
      }

      ll id = stk.back().second;
      ll sta = meet(-2 * i, arr[i] + sq(i), -2 * id, arr[id] + sq(id));
      if (sta <= stk.back().first) {
        stk.pop_back();
      } else {
        stk.push_back({sta, i});
        break;
      }
    }
  }

  vector<ll> ans (n);
  for (int i = 0; i < (int) stk.size(); i++) {
    ll L = max(0LL, stk[i].first);
    ll R;
    if (i == (int) stk.size() - 1) {
      R = n - 1;
    } else {
      R = min((ll) n - 1, stk[i + 1].first - 1);
    }

    for (ll j = L; j <= R; j++) {
      ans[j] = arr[stk[i].second] + sq(stk[i].second - j);
    }
  }
  
  return ans;
}

ostream& operator<< (ostream &out, const vector<ll> &vec) {
  for (int i = 0; i < (int) vec.size(); i++) {
    out << vec[i] << " ";
  }
  out << '\n';
  return out;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, K;
  cin >> n >> m >> K;

  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<ll> dist (n, INF);
  dist[0] = 0;

  dist = dijkstra(dist);
  // cerr << " " << -1 << " " << dist;
  for (int i = 0; i < K; i++) {
    dist = smooth(dist);
    // cerr << " " << i << " " << dist;
    dist = dijkstra(dist);
    // cerr << " " << i << " " << dist;
  }

  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}