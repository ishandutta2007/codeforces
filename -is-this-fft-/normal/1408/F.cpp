#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

vector<pair<int, int>> ops;

const int MAX_N = 15005;

vector<int> group [MAX_N];
set<pair<int, int>> sizes;

map<int, int> cnt;
set<int> bigs;

void redcnt (int x) {
  cnt[x]--;
  if (cnt[x] == 1) {
    bigs.erase(x);
  }
}

void inccnt (int x) {
  cnt[x]++;
  if (cnt[x] == 2) {
    bigs.insert(x);
  }
}

void merge (int a, int b) {
  if (group[a].size() < group[b].size()) {
    merge(b, a);
    return;
  }

  vector<int> &A = group[a];
  vector<int> &B = group[b];
  
  sizes.erase(make_pair((int) A.size(), a));
  redcnt(A.size());
  sizes.erase(make_pair((int) B.size(), b));
  redcnt(B.size());
  
  if (A.size() == B.size()) {
    for (int i = 0; i < (int) A.size(); i++) {
      ops.push_back(make_pair(A[i], B[i]));
    }
    while (!B.empty()) {
      A.push_back(B.back());
      B.pop_back();
    }
  } else {
    for (int i = 0; i < (int) B.size(); i++) {
      ops.push_back(make_pair(A[(int) A.size() - i - 1], B[i]));
    }

    int K = B.size();
    for (int i = 0; i < K; i++) {
      B.push_back(A.back());
      A.pop_back();
    }
  }

  sizes.insert(make_pair((int) A.size(), a));
  inccnt(A.size());
  if (!B.empty()) {
    sizes.insert(make_pair((int) B.size(), b));
    inccnt(B.size());
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    group[i].push_back(i);
    sizes.insert(make_pair(1, i));
  }
  cnt[1] = n;
  bigs.insert(1);
  
  while ((int) sizes.size() > 2) {
    if (!bigs.empty()) {
      int sz = *bigs.begin();
      auto lb = sizes.lower_bound(make_pair(sz, -1));
      assert(lb != sizes.end() && next(lb) != sizes.end());
      assert(lb->first == next(lb)->first);

      int a = lb->second;
      int b = next(lb)->second;
      merge(a, b);
    } else {
      int c0 = sizes.begin()->second;
      int cl = sizes.rbegin()->second;
      merge(c0, cl);
    }
  }

  cout << (int) ops.size() << '\n';
  for (auto op : ops) {
    cout << op.first << " " << op.second << '\n';
  }
}