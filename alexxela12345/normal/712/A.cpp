#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  arr.push_back(0);
  for (int i = 0; i < n; i++) {
    cout << arr[i] + arr[i + 1] << " ";
  }
  cout << endl;
}