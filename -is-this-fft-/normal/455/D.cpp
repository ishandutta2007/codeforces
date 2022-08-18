#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;
int lastans;

struct Query {
  int type, l, r, k;
};

void report (int ans) {
  lastans = ans;
  cout << ans << '\n';
}

Query get_query () {
  Query ans;
  cin >> ans.type >> ans.l >> ans.r;
  if (ans.type == 2) {
    cin >> ans.k;
  }

  ans.l = ((ans.l + lastans - 1) % N);
  ans.r = ((ans.r + lastans - 1) % N);
  ans.k = ((ans.k + lastans - 1) % N) + 1;
  if (ans.l > ans.r) swap(ans.l, ans.r);
  return ans;
}

const int BLOCK = 320;
const int MAX_N = BLOCK * BLOCK;

deque<int> arr [BLOCK];
int cnt [BLOCK][MAX_N];

// counting queries
int solve (Query q) {
  if (q.l / BLOCK == q.r / BLOCK) {
    int ans = 0;
    int bl = q.l / BLOCK;
    for (int i = q.l % BLOCK; i <= q.r % BLOCK; i++) {
      ans += (arr[bl][i] == q.k);
    }
    return ans;
  }

  int ans = 0;
  int bl = q.l / BLOCK;
  int br = q.r / BLOCK;
  for (int i = q.l % BLOCK; i < BLOCK; i++) {
    ans += (arr[bl][i] == q.k);
  }
  for (int i = bl + 1; i <= br - 1; i++) {
    ans += cnt[i][q.k];
  }
  for (int i = 0; i <= q.r % BLOCK; i++) {
    ans += (arr[br][i] == q.k);
  }
  return ans;
}

// rotating queries
void rotate (Query q) {
  if (q.l / BLOCK == q.r / BLOCK) {
    int bl = q.l / BLOCK;
    int rot = arr[bl][q.r % BLOCK];
    for (int i = q.r % BLOCK; i > q.l % BLOCK; i--) {
      arr[bl][i] = arr[bl][i - 1];
    }
    arr[bl][q.l % BLOCK] = rot;
    return;
  }

  int bl = q.l / BLOCK;
  int br = q.r / BLOCK;
  int rot = arr[br][q.r % BLOCK];
  cnt[br][rot]--;
  for (int i = q.r % BLOCK; i >= 1; i--) {
    arr[br][i] = arr[br][i - 1];
  }
  arr[br][0] = arr[br - 1].back();
  cnt[br][arr[br].front()]++;

  for (int i = br - 1; i >= bl + 1; i--) {
    cnt[i][arr[i].back()]--;
    arr[i].pop_back();
    arr[i].push_front(arr[i - 1].back());
    cnt[i][arr[i].front()]++;
  }

  cnt[bl][arr[bl].back()]--;
  for (int i = BLOCK - 1; i > q.l % BLOCK; i--) {
    arr[bl][i] = arr[bl][i - 1];
  }
  arr[bl][q.l % BLOCK] = rot;
  cnt[bl][rot]++;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    arr[i / BLOCK].push_back(x);
    cnt[i / BLOCK][x]++;
  }

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    Query q = get_query();
    if (q.type == 1) {
      rotate(q);
    } else {
      report(solve(q));
    }
  }
}