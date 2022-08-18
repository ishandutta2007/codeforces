#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 5e5 + 5;

int arr [MAX_N];
int cnt [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, I;
  cin >> n >> I;
  I *= 8;

  int k = I / n;
  int width;
  if (k > 20) {
    width = n;
  } else {
    width = min(n, 1 << k);
  }

  map<int, int> compr;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    compr[arr[i]] = 0;
  }

  int m = 0; // # of values
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = m;
    m++;
  }

  for (int i = 0; i < n; i++) {
    cnt[compr[arr[i]]]++;
  }

  width = min(width, m);

  int sum = 0, lptr = 0, rptr = width;
  for (int i = 0; i < width; i++) {
    sum += cnt[i];
  }

  int ans = sum;
  while (rptr < m) {
    sum += cnt[rptr];
    rptr++;
    sum -= cnt[lptr];
    lptr++;

    ans = max(ans, sum);
  }

  cout << n - ans << endl;
}