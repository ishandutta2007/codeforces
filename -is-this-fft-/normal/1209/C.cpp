#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int length;
  cin >> length;

  vector<int> arr (length);
  for (int i = 0; i < length; i++) {
    char c;
    cin >> c;

    arr[i] = c - '0';
  }

  vector<int> sortarr = arr;
  sort(sortarr.begin(), sortarr.end());

  vector<vector<int>> nxt (10, vector<int> (length, length + 5));
  for (int k = 0; k < 10; k++) {
    for (int i = length - 2; i >= 0; i--) {
      if (arr[i + 1] == k) {
        nxt[k][i] = i + 1;
      } else {
        nxt[k][i] = nxt[k][i + 1];
      }
    }
  }

  vector<int> firstOcc (10, length + 5);
  for (int i = 0; i < length; i++) {
    firstOcc[arr[i]] = min(i, firstOcc[arr[i]]);
  }

  vector<int> ans (length);
  int pos = firstOcc[sortarr[0]];
  int iter = 1;
  ans[pos] = 1;
  for (int i = 1; i < length; i++) {
    if (nxt[sortarr[i]][pos] >= length) {
      iter++;
      pos = firstOcc[sortarr[i]];
    } else {
      pos = nxt[sortarr[i]][pos];
    }

    if (iter > 2) {
      cout << "-" << '\n';
      return;
    }
    ans[pos] = iter;
  }

  for (int i = 0; i < length; i++) {
    cout << ans[i];
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