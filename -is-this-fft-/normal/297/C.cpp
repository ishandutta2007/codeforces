#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int A [MAX_N];
int B [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int, int>> ord;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ord.push_back(make_pair(arr[i], i));
  }
  sort(ord.begin(), ord.end());

  int repc = (n + 2) / 3;
  int rem = n - 2 * repc;
  for (int i = 0; i < rem; i++) {
    int pos = ord[n - i - 1].second;
    B[pos] = i;
    A[pos] = arr[pos] - i;
  }

  for (int i = 0; i < 2 * repc; i++) {
    int pos = ord[i].second;
    if (i < repc) {
      A[pos] = arr[pos];
      B[pos] = 0;
    } else {
      A[pos] = 0;
      B[pos] = arr[pos];
    }
  }

  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << B[i] << " ";
  }
  cout << '\n';
}