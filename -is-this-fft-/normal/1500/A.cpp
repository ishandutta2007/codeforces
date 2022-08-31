#include <iostream>
#include <algorithm>
#include <vector>
#define ignore ___ignore

using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_A = 5e6 + 5;

pair<int, int> arr [MAX_N]; // <value, index>
bool ignore [MAX_N];

pair<int, int> found [MAX_A];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }

  sort(arr, arr + n);

  vector<pair<int, int>> dups;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && arr[i].first == arr[i + 1].first) {
      ignore[arr[i + 1].second] = true;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i < n - 1 && arr[i].first == arr[i + 1].first) {
      dups.push_back(make_pair(arr[i].second, arr[i + 1].second));
      int val = arr[i].first + arr[i + 1].first;
      found[val] = make_pair(arr[i].second, arr[i + 1].second);
      i++;
    }
  }

  if ((int) dups.size() >= 2) {
    cout << "YES" << '\n';
    cout << dups[0].first << " " << dups[1].first << " "
         << dups[0].second << " " << dups[1].second << '\n';
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    if (ignore[arr[i].second]) {
      continue;
    }

    for (int j = i + 1; j < n; j++) {
      if (ignore[arr[j].second]) {
        continue;
      }

      int val = arr[i].first + arr[j].first;
      if (found[val].first != 0) {
        cout << "YES" << '\n';
        cout << found[val].first << " " << found[val].second << " "
             << arr[i].second << " " << arr[j].second << '\n';
        return 0;
      }

      found[val] = make_pair(arr[i].second, arr[j].second);
    }
  }

  cout << "NO" << '\n';
}