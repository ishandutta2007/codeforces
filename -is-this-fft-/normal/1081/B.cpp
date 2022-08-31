#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000005;

int arr [maxn];
vector<int> grp [maxn];
int ans [maxn];

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] = n - arr[i];
    grp[arr[i]].push_back(i);
  }

  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if ((int) grp[i].size() % i != 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    
    for (int j = 0; j < (int) grp[i].size(); j += i) {
      cur++;
      for (int k = j; k < j + i; k++) {
        ans[grp[i][k]] = cur;
      }
    }
  }

  cout << "Possible" << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}