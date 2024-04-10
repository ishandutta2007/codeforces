#include <bits/stdc++.h>

using namespace std;

void test() {
  int N;
  cin >> N;
  int a1;
  cin >> a1;
  bool ok = true;
  for (int i = 2; i <= N; ++i) {
    int a;
    cin >> a;
    if (a % a1 != 0) {
      ok = false;
    }
  }
  if (!ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    test();
  }
}