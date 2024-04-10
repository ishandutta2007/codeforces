#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
int n, k;
bool good[N];

bool query(int x) {
  cout << "? " << x << endl;
  char c;
  cin >> c;
  bool ans = c == 'Y';
  if (ans) good[x] = 0;
  return ans;
}

void clear() {
  cout << "R" << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  fill(good, good+n+1, 1);
  int block = (k == 1 ? 1 : k/2);
  for (int i = 1; i <= n; i += block) {
    for (int j = i+block; j <= n; j += block) {
      for (int x = i; x < i+block; x++) query(x);
      for (int x = j; x < j+block; x++) query(x);
      clear();
    }
  }
  cout << "! " << accumulate(good+1, good+n+1, 0) << '\n';
}