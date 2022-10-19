#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int K = 9;
const int L = 6;
const int magic[L] = {372, 29, 303, 462, 23, 107};
// 6 guesses for 9 questions
int n;
int baseline = 0;
bool guess[N];

int query() {
  for (int i = 0; i < n; i++) {
    cout << (guess[i] ? 'T' : 'F');
  }
  cout << endl;
  int ans;
  cin >> ans;
  if (ans == n) exit(0);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n;
  baseline = query();
  for (int i = 0; i+K-1 < n; i+=K) {
    vector<int> z(L);
    for (int j = 0; j < L; j++) {
      for (int k = 0; k < K; k++) {
        if ((magic[j]>>k)&1) {
          guess[i+k] = 1;
        }
        else {
          guess[i+k] = 0;
        }
      }
      z[j] = query()-baseline;
    }
    for (int mask = 0; mask < (1<<K); mask++) {
      bool good = 1;
      for (int j = 0; j < L; j++) {
        if (__builtin_popcount(mask&magic[j])-__builtin_popcount((~mask)&magic[j]) != z[j]) {
          good = 0;
          break;
        }
      }
      if (good) {
        for (int k = 0; k < K; k++) {
          if ((mask>>k)&1) {
            guess[i+k] = 1;
            baseline++;
          }
          else {
            guess[i+k] = 0;
          }
        }
        break;
      }
    }
  }

  for (int i = K*(n/K); i < n; i++) {
    guess[i] = 1;
    int t = query();
    if (t > baseline) {
      baseline = t;
    }
    else {
      guess[i] = 0;
    }
  }
  query(); // is this all that's missing from my WA submission?
}