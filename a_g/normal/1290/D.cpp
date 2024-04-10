#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
int n, k;
bool good[N];

void query(int x) {
  cout << "? " << x << endl;
  char c;
  cin >> c;
  if (c == 'Y') good[x] = 0;
}

void clear() {
  cout << "R" << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  fill(good, good+n+1, 1);
  int block = (k == 1 ? 1 : k/2);
  for (int i = 1; i <= n; i += 1) {
    for (int j = 0; j < i && j+i < n/block; j++) {
      for (int l = j; l < n/block; l += i) {
        for (int k = 1; k <= block; k++) {
          query(l*block+k);
        }
      }
      clear();
    }
  }
  cout << "! " << accumulate(good+1, good+n+1, 0) << '\n';
}