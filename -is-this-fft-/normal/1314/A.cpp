#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

pair<ll, ll> arr [MAX_N]; // <#, cost>

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
  }

  for (int i = 0; i < n; i++) {
    cin >> arr[i].second;
  }

  sort(arr, arr + n);

  vector<pair<ll, vector<ll>>> blocks; // <#, <costs>>
  for (int i = 0; i < n; i++) {
    if (blocks.empty() || arr[i].first != arr[i - 1].first) {
      blocks.push_back(make_pair(arr[i].first, vector<ll> (0)));
    }
    blocks.back().second.push_back(arr[i].second);
  }
  
  priority_queue<pair<ll, int>> floats;
  ll floatsum = 0;
  ll ans = 0;

  int id = 1;
  for (int i = 0; i < (int) blocks.size(); i++) {
    pair<ll, vector<ll>> &block = blocks[i];
    if (i != 0) {
      for (ll j = blocks[i - 1].first; j < blocks[i].first && !floats.empty(); j++) {
        pair<ll, int> ftop = floats.top();
        floats.pop();
        floatsum -= ftop.first;
        ans += floatsum;
      }
    }

    for (ll v : block.second) {
      id++;
      floats.push(make_pair(v, id));
      floatsum += v;
    }
  }

  for (ll j = blocks.back().first; !floats.empty(); j++) {
    pair<ll, int> ftop = floats.top();
    floats.pop();
    floatsum -= ftop.first;
    ans += floatsum;    
  }

  cout << ans << endl;
}