#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> state;

#define x first
#define y second

long long k;
state init;
int a[7][7];
int b[7][7];
map <state, long long> id;
long long scoreA[100005];
long long scoreB[100005];

state nxt (state cur) {
  return state(a[cur.x][cur.y], b[cur.x][cur.y]);
}

int result (int x, int y) {
  if (x == y) return 0;
  if (x == 3) return y == 1 ? 1 : -1;
  return y == x + 1 ? 1 : -1;
}

int main() {
  cin >> k >> init.x >> init.y;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cin >> b[i][j];
    }
  }
  int out = 0;
  int periodLen = -1;
  long long periodA = 0, periodB = 0;
  long long curA = 0, curB = 0;
  int at;
  int ress = result(init.x, init.y);
  if (ress == 1) ++scoreA[1];
  if (ress == -1) ++scoreB[1];
  id[init] = 1;
  for (long long i = 2; i <= k; ++i) {
    init = nxt(init);
    if (id.find(init) == id.end()) {
      id[init] = i;
      scoreA[i] = scoreA[i - 1];
      scoreB[i] = scoreB[i - 1];
      int res = result(init.x, init.y);
      if (res == 1) ++scoreA[i];
      if (res == -1) ++scoreB[i];
    } else {
      at = id[init];
      periodLen = i - at;
      periodA = scoreA[i - 1] - scoreA[at - 1];
      periodB = scoreB[i - 1] - scoreB[at - 1];
      // cout << at << " " << periodLen << " " << periodA << " " << periodB << endl;
      out = 1;
      curA = scoreA[at - 1], curB = scoreB[at - 1];
      break;
    }
  }
  if (!out) {
    printf("%lld %lld\n", scoreB[k], scoreA[k]);
    return 0;
  }
  // cout << "yo\n";
  // cout << curA << " " << curB << endl;
  k -= (at - 1LL);
  // cout << k << endl;
  long long q = k / periodLen, r = k % periodLen;
  curA += q * periodA, curB += q * periodB;
  curA += (scoreA[at - 1 + r] - scoreA[at - 1]);
  curB += (scoreB[at - 1 + r] - scoreB[at - 1]);
  printf("%lld %lld\n", curB, curA);
  return 0;
}