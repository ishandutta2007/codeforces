#include <bits/stdc++.h>
using namespace std;

const int N = 44;
int fib[N];

vector<int> zeckendorf(int x) {
  vector<int> ans;
  for (int i = N-1; i >= 0; i--) {
    if (x >= fib[i]) {
      ans.push_back(i);
      x -= fib[i];
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = fib[i-1]+fib[i-2];
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    if (n > N) {
      cout << "NO\n";
      continue;
    }
    vector<int> freq(N);
    vector<bool> flag(N);
    for (int x: a) {
      for (int i = N-1; i >= 0; i--) {
        if (x >= fib[i]) {
          freq[i]++;
          x -= fib[i];
          if (x == 0) flag[i] = 1;
        }
      }
    }
    if (*max_element(freq.begin(), freq.end()) > 2 || count(freq.begin(), freq.end(), 2) > 1) {
      cout << "NO\n";
      continue;
    }
    int start = 1;
    for (int i = 0; i+1 < N; i++) {
      if (!freq[i] && freq[i+1]) {
        start = i+1;
      }
    }
    if (!flag[start] || start%2 == 0) {
      cout << "NO\n";
      continue;
    }
    freq[start]--;
    for (int i = start-1; i >= 0; i -= 2) {
      freq[i]++;
    }
    while (freq.back() == 0) freq.pop_back();
    cout << (count(freq.begin(), freq.end(), 1) == (int)freq.size() ? "YES" : "NO") << '\n';
  }
}