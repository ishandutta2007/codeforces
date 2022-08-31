#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Query {
  int l, r, t, id;

  Query (int _l, int _r, int _t, int _id) :
    l(_l), r(_r), t(_t), id(_id) {}
};

const int MAX_N = 1e5 + 5;
const int BLOCK = 2200;

bool bymo (Query p, Query q) {
  if (p.l / BLOCK != q.l / BLOCK) {
    return p.l < q.l;
  }

  if (p.r / BLOCK != q.r / BLOCK) {
    return p.r < q.r;
  }

  return p.t < q.t;
}

bool byid (Query p, Query q) {
  return p.id < q.id;
}

typedef long long ll;

int arr [MAX_N];
int prv [MAX_N];
int nxt [MAX_N];

// update data
int pos_at [MAX_N];
int oldval [MAX_N];
int newval [MAX_N];
int oldprv [MAX_N];
int oldnxt [MAX_N];
int newprv [MAX_N];
int newnxt [MAX_N];

// Mo functions
ll ans;
int cur_ls [MAX_N];
int cur_rs [MAX_N];
int L, R, T;

void print_state (int n, int m) {
  cerr << "L = " << L << "; R = " << R << "; T = " << T << endl;
  for (int i = 1; i <= n; i++) {
    cerr << arr[i] << " ";
  }
  cerr << endl;
  for (int i = 1; i <= n; i++) {
    cerr << setw(2) << prv[i] << " ";
  }
  cerr << endl;
  for (int i = 1; i <= n; i++) {
    cerr << setw(2) << nxt[i] << " ";
  }
  cerr << endl << endl;

  for (int i = 1; i <= m; i++) {
    cerr << cur_ls[i] << " " << cur_rs[i] << endl;
  }
  cerr << ans << endl << endl << endl;
}

void add_r () {
  R++;
  if (cur_rs[arr[R]] == -1) {
    cur_ls[arr[R]] = R;
    cur_rs[arr[R]] = R;
  } else {  
    ans -= cur_rs[arr[R]];
    cur_rs[arr[R]] = R;
    ans += cur_rs[arr[R]];
  }
}

void sub_r () {
  if (cur_rs[arr[R]] == cur_ls[arr[R]]) {
    cur_rs[arr[R]] = -1;
    cur_ls[arr[R]] = -1;
  } else {
    ans -= cur_rs[arr[R]];
    cur_rs[arr[R]] = prv[R];
    ans += cur_rs[arr[R]];
  }
  R--;
}

void add_l () {
  if (cur_ls[arr[L]] == cur_rs[arr[L]]) {
    cur_ls[arr[L]] = -1;
    cur_rs[arr[L]] = -1;
  } else {
    ans += cur_ls[arr[L]];
    cur_ls[arr[L]] = nxt[L];
    ans -= cur_ls[arr[L]];
  }
  L++;
}

void sub_l () {
  L--;
  if (cur_ls[arr[L]] == -1) {
    cur_ls[arr[L]] = L;
    cur_rs[arr[L]] = L;
  } else {
    ans += cur_ls[arr[L]];
    cur_ls[arr[L]] = L;
    ans -= cur_ls[arr[L]];
  }
}

void add_t () {
  T++;
  int p = pos_at[T];

  // delete the old from the segments
  if (L <= p && p <= R) {
    if (cur_ls[arr[p]] == cur_rs[arr[p]]) {
      cur_ls[arr[p]] = -1;
      cur_rs[arr[p]] = -1;
    } else if (cur_ls[arr[p]] == p) {
      ans += cur_ls[arr[p]];
      cur_ls[arr[p]] = nxt[p];
      ans -= cur_ls[arr[p]];      
    } else if (cur_rs[arr[p]] == p) {
      ans -= cur_rs[arr[p]];
      cur_rs[arr[p]] = prv[p];
      ans += cur_rs[arr[p]];      
    }
  }

  // update the arr, prv, nxt
  if (oldprv[T] != -1) nxt[oldprv[T]] = oldnxt[T];
  if (oldnxt[T] != -1) prv[oldnxt[T]] = oldprv[T];

  arr[p] = newval[T];
  prv[p] = newprv[T];
  nxt[p] = newnxt[T];

  if (prv[p] != -1) nxt[prv[p]] = p;
  if (nxt[p] != -1) prv[nxt[p]] = p;

  // add the new to the segments
  if (L <= p && p <= R) {
    if (cur_ls[arr[p]] == -1) {
      cur_ls[arr[p]] = p;
      cur_rs[arr[p]] = p;
    } else if (p > cur_rs[arr[p]]) {
      ans -= cur_rs[arr[p]];
      cur_rs[arr[p]] = p;
      ans += cur_rs[arr[p]];
    } else if (p < cur_ls[arr[p]]) {
      ans += cur_ls[arr[p]];
      cur_ls[arr[p]] = p;
      ans -= cur_ls[arr[p]];
    }
  }
}

void sub_t () {
  int p = pos_at[T];

  // delete the new from the segments
  if (L <= p && p <= R) {
    if (cur_ls[arr[p]] == cur_rs[arr[p]]) {
      cur_ls[arr[p]] = -1;
      cur_rs[arr[p]] = -1;
    } else if (cur_ls[arr[p]] == p) {
      ans += cur_ls[arr[p]];
      cur_ls[arr[p]] = nxt[p];
      ans -= cur_ls[arr[p]];      
    } else if (cur_rs[arr[p]] == p) {
      ans -= cur_rs[arr[p]];
      cur_rs[arr[p]] = prv[p];
      ans += cur_rs[arr[p]];      
    }
  }

  // update the arr, prv, nxt
  if (newprv[T] != -1) nxt[newprv[T]] = newnxt[T];
  if (newnxt[T] != -1) prv[newnxt[T]] = newprv[T];

  arr[p] = oldval[T];
  prv[p] = oldprv[T];
  nxt[p] = oldnxt[T];

  if (prv[p] != -1) nxt[prv[p]] = p;
  if (nxt[p] != -1) prv[nxt[p]] = p;

  // add the old to the segments
  if (L <= p && p <= R) {
    if (cur_ls[arr[p]] == -1) {
      cur_ls[arr[p]] = p;
      cur_rs[arr[p]] = p;
    } else if (p > cur_rs[arr[p]]) {
      ans -= cur_rs[arr[p]];
      cur_rs[arr[p]] = p;
      ans += cur_rs[arr[p]];
    } else if (p < cur_ls[arr[p]]) {
      ans += cur_ls[arr[p]];
      cur_ls[arr[p]] = p;
      ans -= cur_ls[arr[p]];
    }
  }

  T--;
}

ll qans [MAX_N];

// only to be used during precalc
set<int> poses [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    poses[arr[i]].insert(i);
  }

  for (int i = 1; i <= n; i++) {
    auto it = poses[arr[i]].find(i);
    if (it == poses[arr[i]].begin()) {
      prv[i] = -1;
    } else {
      prv[i] = *prev(it);
    }

    if (next(it) == poses[arr[i]].end()) {
      nxt[i] = -1;
    } else {
      nxt[i] = *next(it);
    }
  }
  
  vector<Query> queries;
  int curt = 0, curid = 0;
  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int p, x;
      cin >> p >> x;
      
      curt++;
      pos_at[curt] = p;
      oldval[curt] = arr[p];
      oldprv[curt] = prv[p];
      oldnxt[curt] = nxt[p];

      poses[arr[p]].erase(p);
      if (oldprv[curt] != -1) nxt[oldprv[curt]] = oldnxt[curt];
      if (oldnxt[curt] != -1) prv[oldnxt[curt]] = oldprv[curt];
      
      arr[p] = x;

      auto it = poses[arr[p]].insert(p).first;
      if (it == poses[arr[p]].begin()) {
        prv[p] = -1;
      } else {
        prv[p] = *prev(it);
      }

      if (next(it) == poses[arr[p]].end()) {
        nxt[p] = -1;
      } else {
        nxt[p] = *next(it);
      }

      newval[curt] = arr[p];
      newprv[curt] = prv[p];
      newnxt[curt] = nxt[p];

      if (prv[p] != -1) {
        nxt[prv[p]] = p;
      }
      if (nxt[p] != -1) {
        prv[nxt[p]] = p;
      }
    } else {
      int l, r;
      cin >> l >> r;

      queries.push_back(Query(l, r, curt, curid));
      curid++;
    }
  }

  T = curt;
  L = 1;
  R = 1;
  for (int i = 1; i <= n; i++) {
    cur_ls[i] = -1;
    cur_rs[i] = -1;
  }
  cur_ls[arr[1]] = 1;
  cur_rs[arr[1]] = 1;

  sort(queries.begin(), queries.end(), bymo);

  print_state(4, 2);
  
  for (Query q : queries) {
    while (R < q.r) add_r();
    while (L > q.l) sub_l();
    while (R > q.r) sub_r();
    while (L < q.l) add_l();
    while (T < q.t) add_t();
    while (T > q.t) sub_t();

    qans[q.id] = ans;
  }

  for (int i = 0; i < curid; i++) {
    cout << qans[i] << '\n';
  }
}