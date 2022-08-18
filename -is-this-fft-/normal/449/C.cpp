#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int factor [MAX_N];
int cnt [MAX_N];
vector<int> groups [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  for (int i = 2; i <= n; i++) {
    if (factor[i] == 0) {
      for (int j = i; j <= n; j += i) {
        if (factor[j] == 0) {
          factor[j] = i;
          cnt[i]++;
        }
      }
    }
  }

  for (int i = 3; i <= n; i++) {
    if (factor[i] == i) {
      if (cnt[i] % 2 == 1) {
        if (2 * i <= n) {
          factor[2 * i] = i;
        }
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    groups[factor[i]].push_back(i);
  }

  vector<pair<int, int>> ans;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < (int) groups[i].size() - 1; j += 2) {
      ans.push_back(make_pair(groups[i][j], groups[i][j + 1]));
    }
  }

  cout << (int) ans.size() << '\n';
  for (pair<int, int> pr : ans) {
    cout << pr.first << " " << pr.second << '\n';
  }
}