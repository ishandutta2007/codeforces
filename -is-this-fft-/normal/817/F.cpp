#include <iostream>
#include <map>
#include <vector>
#include <assert.h>

using namespace std;

typedef long long llong;

const int BLOCK = 450;
const int MAX_N = 202500;

struct Query {
  llong type, l, r;
};

int present [MAX_N];
int overwr [BLOCK]; /* 1 - all ones; 2 - all zeros; 3 - inverted */
int cnt [BLOCK];

void propagate (int i) {
  if (overwr[i] == 1) {
    for (int j = BLOCK * i; j < BLOCK * (i + 1); j++) {
      present[j] = 1;
    }
  } else if (overwr[i] == 2) {
    for (int j = BLOCK * i; j < BLOCK * (i + 1); j++) {
      present[j] = 0;
    }
  } else if (overwr[i] == 3) {
    for (int j = BLOCK * i; j < BLOCK * (i + 1); j++) {
      present[j] = !present[j];
    }
  }
  overwr[i] = 0;
}

void process (Query q) {
  q.r--;
  propagate(q.l / BLOCK);
  propagate(q.r / BLOCK);

  for (int i = q.l; i <= q.r;) {
    if (i % BLOCK == 0 && i + BLOCK <= q.r) {
      if (q.type == 1) {
        overwr[i / BLOCK] = 1;
        cnt[i / BLOCK] = BLOCK;
      } else if (q.type == 2) {
        overwr[i / BLOCK] = 2;
        cnt[i / BLOCK] = 0;
      } else if (q.type == 3) {
        overwr[i / BLOCK] = 3 - overwr[i / BLOCK]; /* what the fuck */
        cnt[i / BLOCK] = BLOCK - cnt[i / BLOCK];
      }
      i += BLOCK;
    } else {
      if (q.type == 1) {
        cnt[i / BLOCK] += !present[i];
        present[i] = 1;
      } else if (q.type == 2) {
        cnt[i / BLOCK] -= present[i];
        present[i] = 0;
      } else if (q.type == 3) {
        if (present[i]) {
          cnt[i / BLOCK]--;
        } else {
          cnt[i / BLOCK]++;
        }
        present[i] = !present[i];
      }
      i++;
    }
  }
}

int mex () {
  for (int i = 0; i < BLOCK; i++) {
    if (cnt[i] != BLOCK) {
      propagate(i);
      for (int j = BLOCK * i; j < BLOCK * (i + 1); j++) {
        if (!present[j]) {
          return j;
        }
      }
    }
  }
  assert(false);
}

llong decomp [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int queryc;
  cin >> queryc;

  /* co-ordinate compression */
  vector<Query> queries (queryc);
  map<llong, int> compr;
  for (int i = 0; i < queryc; i++) {
    cin >> queries[i].type >> queries[i].l >> queries[i].r;
    queries[i].r++;

    compr[queries[i].l] = 0;
    compr[queries[i].r] = 0;
  }
  compr[1] = 0;

  int cur = 0;
  for (map<llong, int>::iterator it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }

  for (pair<llong, int> pr : compr) {
    decomp[pr.second] = pr.first;
  }

  for (int i = 0; i < queryc; i++) {
    queries[i].l = compr[queries[i].l];
    queries[i].r = compr[queries[i].r];
  }
  
  /* query processing */
  for (Query q : queries) {
    process(q);
    cout << decomp[mex()] << '\n';
  }
}