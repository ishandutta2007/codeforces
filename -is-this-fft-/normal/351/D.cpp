#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

template <typename T>
T preback (const deque<T> &deq) {
  return *next(deq.rbegin());
}

template <typename T>
T prefront (const deque<T> &deq) {
  return *next(deq.begin());
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

// the current state
int cntdiff; // # of different values in the current range
int cnt [MAX_N]; // cnt[i] is the # of occurrences of thing i

void add (int idx) {
  cnt[idx]++;
  if (cnt[idx] == 1) cntdiff++;
}

void del (int idx) {
  cnt[idx]--;
  if (cnt[idx] == 0) cntdiff--;
}

int cntper; // # of things that are periodic
deque<int> occs [MAX_N]; // occurrences of a value
deque<pair<int, int>> perseg [MAX_N]; // periodicity segments

// add idx to the right
void addr (int idx) {
  int c = arr[idx];
  add(c);
  occs[c].push_back(idx);
  if (occs[c].size() == 1) {
    cntper++;
  } if (occs[c].size() == 2) {
    perseg[c].push_back(make_pair(occs[c].back() - preback(occs[c]), 1));
  } else if (occs[c].size() > 2) {
    if (occs[c].back() - preback(occs[c]) == perseg[c].back().first) {
      perseg[c].back().second++;
    } else {
      perseg[c].push_back(make_pair(occs[c].back() - preback(occs[c]), 1));
      if ((int) perseg[c].size() == 2) {
        cntper--;
      }
    }
  }
}

void delr (int idx) {
  int c = arr[idx];
  del(c);
  occs[c].pop_back();
  if (!perseg[c].empty()) {
    perseg[c].back().second--;
    if (perseg[c].back().second == 0) {
      perseg[c].pop_back();
      if ((int) perseg[c].size() == 1) {
        cntper++;
      }
    }
  }
  if (cnt[c] == 0) cntper--;
}

// add idx to the left
void addl (int idx) {
  int c = arr[idx];
  add(c);
  occs[c].push_front(idx);
  if (occs[c].size() == 1) {
    cntper++;
  } if (occs[c].size() == 2) {
    perseg[c].push_front(make_pair(prefront(occs[c]) - occs[c].front(), 1));
  } else if (occs[c].size() > 2) {
    if (prefront(occs[c]) - occs[c].front() == perseg[c].front().first) {
      perseg[c].front().second++;
    } else {
      perseg[c].push_front(make_pair(prefront(occs[c]) - occs[c].front(), 1));
      if ((int) perseg[c].size() == 2) {
        cntper--;
      }
    }
  }
}

void dell (int idx) {
  int c = arr[idx];
  del(c);
  occs[c].pop_front();
  if (!perseg[c].empty()) {
    perseg[c].front().second--;
    if (perseg[c].front().second == 0) {
      perseg[c].pop_front();
      if ((int) perseg[c].size() == 1) {
        cntper++;
      }
    }
  }
  if (cnt[c] == 0) cntper--;
}

const int BLOCK = 316;

struct Query {
  int l, r, id;
};

bool bymo (Query p, Query q) {
  if (p.l / BLOCK != q.l / BLOCK) {
    return p.l < q.l;
  } else {
    return p.r < q.r;
  }
}

int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int qc;
  cin >> qc;

  vector<Query> queries (qc);
  for (int i = 0; i < qc; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].id = i;
  }

  sort(queries.begin(), queries.end(), bymo);

  int L = 1, R = 1;
  addl(1);
  for (Query q : queries) {
    while (R < q.r) {
      R++;
      addr(R);
    }

    while (L > q.l) {
      L--;
      addl(L);
    }

    while (R > q.r) {
      delr(R);
      R--;
    }

    while (L < q.l) {
      dell(L);
      L++;
    }

    ans[q.id] = cntdiff + (cntper == 0);
  }

  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}