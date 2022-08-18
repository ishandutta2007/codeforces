#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct segtree {
  vector<pair<int, int>> tree;
  vector<int> lfend;
  vector<int> rgend;
  int length;
 
  void update (int vertex) {
    if (vertex == 0) return;
    tree[vertex] = min(tree[2 * vertex], tree[2 * vertex + 1]);
    update(vertex / 2);
  }
  
public:
  segtree (int _length, pair<int, int> init) {
    length = 1;
    while (length < _length) {
      length *= 2;
    }
 
    tree = vector<pair<int, int>> (2 * length, init);
    lfend = vector<int> (2 * length);
    rgend = vector<int> (2 * length);
    for (int i = length; i < 2 * length; i++) {
      lfend[i] = i - length;
      rgend[i] = i - length;
    }
 
    for (int i = length - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }
 
  void set (int idx, pair<int, int> val) {
    tree[length + idx] = val;
    update((length + idx) / 2);
  }
 
  pair<int, int> get (int ql, int qr, int vertex = 1) {
    ql = max(ql, lfend[vertex]);
    qr = min(qr, rgend[vertex]);
 
    if (ql > qr) return make_pair(1, 1);
    if (ql == lfend[vertex] && qr == rgend[vertex]) return tree[vertex];
    return min(get(ql, qr, 2 * vertex), get(ql, qr, 2 * vertex + 1));
  }
};

const ll INF = 1e18 + 5;
const int MAX_N = 1e5 + 5;

int arr [MAX_N];
pair<int, int> sarr [MAX_N];
ll ans [MAX_N];
int least_g [MAX_N];
int least_st [MAX_N];

int length;
int dist (int p, int q) {
  return ((q - p) % length + length) % length;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    sarr[i] = make_pair(arr[i], i);
  }
  
  segtree stree (2 * length, make_pair(1, 1));
  sort(sarr, sarr + length);

  vector<pair<int, int>> buffer;
  for (int i = length - 1; i >= 0; i--) {
    buffer.push_back(sarr[i]);
    pair<int, int> x = stree.get(sarr[i].second, sarr[i].second + length);
    if (x.first == 1) {
      least_g[sarr[i].second] = -1;
    } else {
      least_g[sarr[i].second] = x.second;
    }
    
    if (i == 0 || sarr[i - 1].first != sarr[i].first) {
      for (pair<int, int> pr : buffer) {
        stree.set(pr.second, make_pair(0, pr.second));
        stree.set(pr.second + length, make_pair(0, pr.second + length));
      }
      buffer.clear();
    }
  }

  segtree wee (2 * length, make_pair(0, 0));
  for (int i = 0; i < length; i++) {
    wee.set(i, make_pair(0, i));
    wee.set(i + length, make_pair(0, i + length));
  }
  
  vector<pair<int, pair<int, int>>> events;
  for (int i = 0; i < length; i++) {
    events.push_back(make_pair(arr[i], make_pair(1, i)));
    events.push_back(make_pair((arr[i] + 1) / 2, make_pair(0, i)));
  }

  sort(events.rbegin(), events.rend());
  for (auto e : events) {
    if (e.second.first == 1) {
      wee.set(e.second.second, make_pair(1, 1));
      wee.set(e.second.second + length, make_pair(1, 1));
    } else {
      pair<int, int> bleh = wee.get(e.second.second, e.second.second + length);
      if (bleh.first == 1) {
        least_st[e.second.second] = -1;
      } else {
        least_st[e.second.second] = bleh.second;
      }
    }
  }
  
  for (int i = length - 1; i >= 0; i--) {
    ll mind = INF;
    /*
    for (int j = 0; j < length && sarr[j].first < (sarr[i].first + 1) / 2; j++) {
      mind = min(mind, (ll) dist(sarr[i].second, sarr[j].second));
    }
    */
    if (least_st[sarr[i].second] != -1) {
      mind = least_st[sarr[i].second] - sarr[i].second;
    }
    
    //cout << sarr[i].second << " " << mind << " " << least_g[sarr[i].second] << endl;

    if (least_g[sarr[i].second] != -1 && least_g[sarr[i].second] < sarr[i].second + mind) {
      ans[sarr[i].second] = least_g[sarr[i].second] - sarr[i].second + ans[least_g[sarr[i].second] % length];
    } else {
      ans[sarr[i].second] = mind;
    }

    /*
    if (mind == INF) {
      
      pair<int, int> top = stree.get(sarr[i].second, sarr[i].second + length);
      if (top.first > sarr[i].first) {
        ans[sarr[i].second] = dist(sarr[i].second, top.second) + ans[top.second];
      } else {
        ans[sarr[i].second] = mind;
      }
    } else {
      pair<int, int> top = stree.get(sarr[i].second, sarr[i].second + mind - 1);
      if (top.first > sarr[i].first) {
        ans[sarr[i].second] = dist(sarr[i].second, top.second) + ans[top.second];
      } else {
        ans[sarr[i].second] = mind;
      }
    }
    */
  }

  for (int i = 0; i < length; i++) {
    if (ans[i] >= INF) {
      cout << -1 << ' ';
    } else {
      cout << ans[i] << ' ';
    }
  }
  cout << '\n';
}