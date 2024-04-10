#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 5;

int arr [MAX_N];
int lpos [MAX_N];
int cum [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    cum[i] = cum[i - 1] + !arr[i];
    lpos[cum[i]] = i;
  }

  pair<int, int> ans = make_pair(-1, -1);
  for (int i = 1; i <= n; i++) {
    if (cum[n] <= cum[i - 1] + K) {
      ans = max(ans, make_pair(n - i + 1, i));
    } else {
      ans = max(ans, make_pair(lpos[cum[i - 1] + K] - i + 1, i));
    }
  }

  cout << ans.first << endl;
  for (int i = ans.second; i <= n; i++) {
    if (arr[i] == 0 && K > 0) {
      arr[i] = 1;
      K--;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}