#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> solve (const vector<int> &arr, int colorc) {
  vector<pair<int, int>> ans (colorc);
  vector<int> used (colorc, 0);
  vector<int> last (colorc, -1);

  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (used[arr[i]]) {
      continue;
    }

    if (last[arr[i]] != -1) {
      ans[arr[i]] = make_pair(last[arr[i]], i);
      used[arr[i]] = 1;
      last = vector<int> (colorc, -1);
    } else {
      last[arr[i]] = i;
    }
  }

  return ans;
}

const int MAX_N = 1e2 + 5;

int arr [MAX_N * MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n * K; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i += K - 1) {
    vector<int> tmp;
    vector<int> orig;

    for (int j = 0; j < n * K; j++) {
      if (i <= arr[j] && arr[j] < i + K - 1) {
        tmp.push_back(arr[j] - i);
        orig.push_back(j);
      }
    }
    
    vector<pair<int, int>> cur = solve(tmp, min(n + 1, i + K - 1) - i);
    for (auto pr : cur) {
      cout << 1 + orig[pr.first] << " " << 1 + orig[pr.second] << '\n';
    }
  }
}