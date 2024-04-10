#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];
ll add [MAX_N];

int L [MAX_N], R [MAX_N], D [MAX_N];
ll cnt [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m, K;
  cin >> n >> m >> K;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> L[i] >> R[i] >> D[i];
  }

  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;

    cnt[x]++;
    cnt[y + 1]--;
  }

  for (int i = 1; i <= m; i++) {
    cnt[i] += cnt[i - 1];
  }

  for (int i = 1; i <= m; i++) {
    add[L[i]] += cnt[i] * D[i];
    add[R[i] + 1] -= cnt[i] * D[i];
  }

  for (int i = 1; i <= n; i++) {
    add[i] += add[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    cout << arr[i] + add[i] << " ";
  }
  cout << endl;
}