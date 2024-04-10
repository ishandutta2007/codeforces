#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100005;
vector<pair<int, int>> links [maxn];

void find_links (int n, int idx) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int pmq = i;
      int ppq = n / i;

      if ((pmq + ppq) % 2 == 0) {
        int p = (pmq + ppq) / 2;
        int q = ppq - p;

        assert((p - q) * (p + q) == n);
        links[idx].push_back(make_pair(q, p));
      }
    }
  }
}

int arr [maxn];

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;

  for (int i = 2; i <= length; i += 2) {
    cin >> arr[i];
  }

  for (int i = 2; i <= length; i += 2) {
    find_links(arr[i], i);
    sort(links[i].begin(), links[i].end());
  }

  vector<ll> ans;
  ans.push_back(0);
  for (int i = 2; i <= length; i += 2) {
    pair<int, int> link = make_pair(-1, -1);
    for (pair<int, int> pr : links[i]) {
      if (pr.first > ans.back()) {
        link = pr;
        break;
      }
    }
    
    if (link == make_pair(-1, -1)) {
      cout << "No" << endl;
      return 0;
    }

    ans.push_back(link.first);
    ans.push_back(link.second);
  }

  for (int i = 0; i < (int) ans.size(); i++) {
    ans[i] = ans[i] * ans[i];
  }

  cout << "Yes" << endl;
  for (int i = 1; i < (int) ans.size(); i++) {
    cout << ans[i] - ans[i - 1] << " ";
  }
  cout << endl;
}