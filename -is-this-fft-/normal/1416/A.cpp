#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 5;

vector<int> occs [MAX_N];
int amz [MAX_N];
int ans [MAX_N];

void solve () {
  int n;
  cin >> n;

  ans[0] = MAX_N;
  for (int i = 1; i <= n; i++) {
    occs[i].clear();
    ans[i] = MAX_N;
  }

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    occs[a].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    if (!occs[i].empty()) {
      amz[i] = max(occs[i][0], n + 1 - occs[i].back());
      for (int j = 0; j < (int) occs[i].size() - 1; j++) {
        amz[i] = max(amz[i], occs[i][j + 1] - occs[i][j]);
      }
      ans[amz[i]] = min(ans[amz[i]], i);
    }
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = min(ans[i - 1], ans[i]);
    cout << (ans[i] == MAX_N ? -1 : ans[i]) << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}