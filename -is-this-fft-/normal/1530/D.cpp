#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> in [MAX_N];
int wish [MAX_N];
int ans [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    in[i].clear();
    ans[i] = 0;
  }
  
  for (int i = 1; i <= n; i++) {
    cin >> wish[i];
    in[wish[i]].push_back(i);
  }

  int ss = -1;
  for (int i = 1; i <= n; i++) {
    if (ss == -1 && in[i].empty()) {
      ss = i;
    } else if (ss > 0 && in[i].empty()) {
      ss = 0;
    }
  }

  int mc = 0;
  vector<int> sources; // people who have not received a gift
  for (int i = 1; i <= n; i++) {
    if (!in[i].empty()) {
      mc++;
      if (ss > 0 && wish[ss] == i) {
        ans[ss] = i;
      } else {
        ans[in[i][0]] = i;
      }
    } else {
      sources.push_back(i);
    }
  }

  vector<int> sinks; // people who have not given a gift
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) {
      sinks.push_back(i);
    }
  }

  int k = sources.size();
  for (int i = 0; i < k; i++) {
    if (sources[i] == sinks[i]) {
      if (i == 0) {
        swap(sources[i], sources[i + 1]);
      } else {
        swap(sources[i], sources[i - 1]);
      }
    }
  }

  for (int i = 0; i < k; i++) {
    ans[sinks[i]] = sources[i];
  }

  cout << mc << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}