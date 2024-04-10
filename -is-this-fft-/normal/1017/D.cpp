#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LEN = 12;
const int DISC = 1 << 12;
const int MAX_K = 105;
const int MAX_Q = 500005;

int ans [MAX_Q];

struct Query {
  int bm, k, id;
};

bool by_ord (Query p, Query q) {
  return make_pair(p.bm, make_pair(p.k, p.id)) < make_pair(q.bm, make_pair(q.k, q.id));
}

int cnt [DISC];
int w [LEN];

int eval (int p, int q) {
  int pq = p ^ q;

  int ans = 0;
  for (int i = 0; i < LEN; i++) {
    ans += w[i] * (1 - (pq % 2));
    pq /= 2;
  }

  return ans;
}

int cur_ans [MAX_K];

void build_ca (int cur_bm) {
  for (int i = 0; i < MAX_K; i++) {
    cur_ans[i] = 0;
  }
  
  for (int i = 0; i < DISC; i++) {
    cur_ans[min(MAX_K - 1, eval(i, cur_bm))] += cnt[i];
  }

  for (int i = 1; i < MAX_K; i++) {
    cur_ans[i] += cur_ans[i - 1];
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int length, setsz, queryc;
  cin >> length >> setsz >> queryc;

  for (int i = length - 1; i >= 0; i--) {
    cin >> w[i];
  }

  for (int i = 0; i < setsz; i++) {
    int cur = 0;

    for (int j = 0; j < length; j++) {
      char c;
      cin >> c;

      cur *= 2;
      cur += (c - '0');
    }

    cnt[cur]++;
  }
  
  vector<Query> queries (queryc);
  for (int i = 0; i < queryc; i++) {
    queries[i].bm = 0;

    for (int j = 0; j < length; j++) {
      char c;
      cin >> c;

      queries[i].bm *= 2;
      queries[i].bm += (c - '0');
    }

    cin >> queries[i].k;

    queries[i].id = i;
  }

  sort(queries.begin(), queries.end(), by_ord);

  for (int i = 0; i < queryc; i++) {
    if (i == 0 || queries[i].bm != queries[i - 1].bm) {
      build_ca(queries[i].bm);
    }

    ans[queries[i].id] = cur_ans[queries[i].k];
  }

  for (int i = 0; i < queryc; i++) {
    cout << ans[i] << '\n';
  }
}