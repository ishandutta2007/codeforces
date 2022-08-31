#include <iostream>

using namespace std;

const int MAX_N = 20;

int cnt [MAX_N];

int ndiv (int x) {
  int ans = 0;
  while (x % 2 == 0) {
    ans++;
    x /= 2;
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cnt[ndiv(i)]++;
  }

  for (int i = 0; i < MAX_N; i++) {
    if (i > 0 && cnt[i] == 1 && cnt[i + 1] == 0 && 3 * ((1 << i) / 2) <= n) {
      cout << 3 * ((1 << i) / 2) << " ";
    } else {
      for (int j = 0; j < cnt[i]; j++) {
        cout << (1 << i) << " ";
      }
    }
  }
  cout << endl;
}