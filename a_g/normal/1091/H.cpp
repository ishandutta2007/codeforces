#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/64196?#comment-480679
const int N = 2e5+5;
const int B = 100;
int lpf[N], nimval[N];
bool valid[N];
vector<int> nimlist[B];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(lpf, lpf+N, 0);
  for (int i = 2; i < N; i++) {
    if (lpf[i] == i) {
      for (int j = 2*i; j < N; j+=i) {
        lpf[j] = i;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    valid[i] = (lpf[i] == i || lpf[i/lpf[i]] == i/lpf[i]);
  }

  int n, f;
  cin >> n >> f;
  valid[f] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < B; j++) {
      bool here = 1;
      for (int x: nimlist[j]) {
        if (valid[i-x]) {
          here = 0;
          break;
        }
      }
      if (here) {
        nimval[i] = j;
        nimlist[j].push_back(i);
        break;
      }
    }
  }

  int val = 0;
  while (n--) {
    int b, w, r;
    cin >> b >> w >> r;
    val ^= nimval[w-b-1];
    val ^= nimval[r-w-1];
  }
  cout << (val ? "Alice\nBob\n" : "Bob\nAlice\n");
}