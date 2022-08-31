#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int cnt [MAX_N];
int cntle [MAX_N];

void add (int x) {
  cnt[x]++;
  cntle[cnt[x]]++;
}

int main () {
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  int target = 1;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;

    add(x);

    if (cntle[target] == n) {
      cout << 1;
      target++;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}