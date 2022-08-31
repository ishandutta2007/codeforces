#include<bits/stdc++.h>

using namespace std;

mt19937 rng;

const int maxn = 300005;
const int block = 700;
const int iters = 500;

int cnt [maxn];
int arr [maxn];

void add (int x) {
  cnt[arr[x]]++;
}

void del (int x) {
  cnt[arr[x]]--;
}

struct Query {
  int l, r, k, ans, id;
};

bool by_mo (Query p, Query q) {
  if (p.l / block == q.l / block) {
    if ((p.l / block) % 2 == 0) {
      return p.r < q.r;
    } else {
      return p.r > q.r;
    }
  } else {
    return p.l < q.l;
  }
}

bool by_id (Query p, Query q) {
  return p.id < q.id;
}

int randrange (int l, int r) {
  return l + rng() % (r - l + 1);
}

const int inf = 1023456789;
int calc_query (int l, int r, int freq) {
  int ans = inf;
  for (int i = 0; i < iters; i++) {
    int cur = arr[randrange(l, r)];
    if (cnt[cur] * freq > r - l + 1) {
      ans = min(ans, cur);
    }
  }

  return (ans == inf ? -1 : ans);
}

int main() {
  rng = mt19937 (chrono::steady_clock::now().time_since_epoch().count());

  ios::sync_with_stdio(false);
  int length, queryc;
  cin >> length >> queryc;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  vector<Query> queries (queryc);
  for (int i = 0; i < queryc; i++) {
    cin >> queries[i].l >> queries[i].r >> queries[i].k;
    queries[i].id = i;
  }
  sort(queries.begin(), queries.end(), by_mo);

  int l = 1, r = 1;
  cnt[arr[1]] = 1;
  for (int i = 0; i < queryc; i++) {
    Query q = queries[i];
    while (r < q.r) {
      r++;
      add(r);
    }

    while (l > q.l) {
      l--;
      add(l);
    }

    while (r > q.r) {
      del(r);
      r--;
    }

    while (l < q.l) {
      del(l);
      l++;
    }

    queries[i].ans = calc_query(q.l, q.r, q.k);
  }
  sort(queries.begin(), queries.end(), by_id);

  for (int i = 0; i < queryc; i++) {
    cout << queries[i].ans << '\n';
  }
}