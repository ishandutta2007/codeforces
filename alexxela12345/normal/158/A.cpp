#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.rbegin(), arr.rend());
  while (!arr.empty() && arr.back() == 0) {
    arr.pop_back();
  }
  n = arr.size();
  k = min(n, k);
  while (k < n && arr[k] == arr[k - 1])
    k++;
  cout << k << endl;
}