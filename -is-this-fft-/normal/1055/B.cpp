#include <iostream>

using namespace std;

typedef long long ll;

const int maxn = 100005;

ll ans, fav;
ll arr [maxn];

void grow (int pos, ll val) {
  if (arr[pos] <= fav && arr[pos] + val > fav) {
    ans++;
    if (arr[pos - 1] > fav) {
      ans--;
    }
    if (arr[pos + 1] > fav) {
      ans--;
    }
  }
  arr[pos] += val;
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;
  int queryc;
  cin >> queryc >> fav;

  ans = 0;
  for (int i = 1; i <= vertexc; i++) {
    int init;
    cin >> init;
    grow(i, init);
  }

  for (int i = 0; i < queryc; i++) {
    int type;
    cin >> type;

    if (type == 0) {
      cout << ans << '\n';
    } else {
      int p, d;
      cin >> p >> d;
      grow(p, d);
    }
  }
}