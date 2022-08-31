#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 5e5 + 5;

typedef long long ll;

ll tetra (ll x) {
  return (x * (x + 1) * (x + 2)) / 6;
}

int arr [MAX_N];
int prefc [MAX_N];
int suffc [MAX_N];

set<int> pos_prefc [MAX_N];
set<int> pos_suffc [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;

    arr[i] = c - '0';
  }

  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      prefc[i] = prefc[i - 1] + 1;
    } else {
      prefc[i] = 0;
    }
    pos_prefc[prefc[i]].insert(i);
  }

  for (int i = n; i >= 1; i--) {
    if (arr[i] == 1) {
      suffc[i] = suffc[i + 1] + 1;
    } else {
      suffc[i] = 0;
    }
    pos_suffc[suffc[i]].insert(i);
  }

  vector<pair<int, int>> blocks;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      if (arr[i - 1] == 0) {
        blocks.push_back(make_pair(i, i));
      } else {
        blocks.back().second = i;
      }
    }
  }

  ll ans = 0;
  for (auto block : blocks) {
    int L = block.first;
    int R = block.second;
    
    int len = R - L + 1;

    // internal segments
    ans += tetra(len - 2);

    // suffix with length i
    for (int i = 1; i < len; i++) {
      int stop;
      auto it = pos_prefc[i + 1].upper_bound(R);
      if (it == pos_prefc[i + 1].end()) {
        stop = n + 1;
      } else {
        stop = *it;
      }

      ans += (ll) i * (ll) (stop - R);
    }

    // prefix with length i
    for (int i = 1; i < len; i++) {
      int stop;
      auto it = pos_suffc[i].lower_bound(L);
      if (it == pos_suffc[i].begin()) {
        stop = 0;
      } else {
        stop = *prev(it);
      }

      ans += (ll) i * (ll) (L - stop);
    }

    int rstop;
    {
      auto it = pos_prefc[len + 1].upper_bound(R);
      if (it == pos_prefc[len + 1].end()) {
        rstop = n + 1;
      } else {
        rstop = *it;
      }
    }

    int lstop;
    {
      auto it = pos_suffc[len].lower_bound(L);
      if (it == pos_suffc[len].begin()) {
        lstop = 0;
      } else {
        lstop = *prev(it);
      }
    }

    ans += (ll) (len) * (ll) (rstop - R) * (ll) (L - lstop);
  }

  cout << ans << endl;
}