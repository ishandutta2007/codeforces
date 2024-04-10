#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int orders[N];
int small[N], big[N];

void add(int* arr, int i, int x) {
  for (; i < N; i += i&-i) arr[i] += x;
}

int query(int* arr, int i) {
  int ans = 0;
  for (; i > 0; i -= i&-i) ans += arr[i];
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int day, num;
      cin >> day >> num;
      add(small, day, -min(b, orders[day]));
      add(big, day, -min(a, orders[day]));
      orders[day] += num;
      add(small, day, min(b, orders[day]));
      add(big, day, min(a, orders[day]));
    }
    else {
      assert(type == 2);
      int p;
      cin >> p;
      cout << query(small, p-1) + query(big, n)-query(big, p+k-1) << '\n';
    }
  }
}