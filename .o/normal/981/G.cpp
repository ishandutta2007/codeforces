#include <bits/stdc++.h>

const int LEAF = 1<<18;

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MOD = 998244353;
const int MAX_TREE_SIZE = 1 << 19;

// https://github.com/ojuz/ojuz11/blob/master/rail/solutions/tncks0121_subtask5.cpp

int N, Q;

namespace segtree {
  struct node {
    int sum, mul, add;
    node(int sum = 0, int mul = 1, int add = 0): sum(sum), mul(mul), add(add) { }
  };

  node tree[MAX_TREE_SIZE + 1];

  void spread (int idx, int nl, int nr) {
    node& nd = tree[idx];
    node& c1 = (nl == nr) ? tree[0] : tree[idx * 2];
    node& c2 = (nl == nr) ? tree[0] : tree[idx * 2 + 1];

    if(nd.mul != 1) {
      nd.sum = ((ll)nd.sum * nd.mul) % MOD;
      for(auto &child : {&c1, &c2}) {
        child->mul = ((ll)child->mul * nd.mul) % MOD;
        child->add = ((ll)child->add * nd.mul) % MOD;
      }
      nd.mul = 1;
    }

    if(nd.add != 0) {
      nd.sum += ((ll)nd.add * (nr - nl + 1)) % MOD;
      nd.sum = nd.sum >= MOD ? nd.sum - MOD : nd.sum;
      for(auto &child : {&c1, &c2}) {
        child->add += nd.add;
        if(child->add >= MOD) child->add %= MOD;
      }
      nd.add = 0;
    }
  }

  int update (int idx, int nl, int nr, int l, int r, char type, int v) {
    node &nd = tree[idx];
    spread(idx, nl, nr);  
    if(l > r) return nd.sum;
    if(l <= nl && nr <= r) {
      (type == '*' ? nd.mul : nd.add) = v;
      spread(idx, nl, nr);
      return nd.sum;
    }
    int nm = (nl + nr) >> 1;
    nd.sum = 0;
    nd.sum += update(idx*2,   nl, nm,   l, min(nm, r),   type, v);
    nd.sum += update(idx*2+1, nm+1, nr, max(nm+1, l), r, type, v);
    if(nd.sum >= MOD) nd.sum -= MOD;
    return nd.sum;
  }

  void multiply(int l, int r, int v) {
    update(1, 0, N, l, r, '*', v);
  }

  void add (int l, int r, int v) {
    update(1, 0, N, l, r, '+', v);
  }

  int get (int idx, int nl, int nr, int l, int r) {
    spread(idx, nl, nr);
    if(nl == l && nr == r) return tree[idx].sum;
    int nm = (nl + nr) >> 1;
    int ret = ((l <= nm) ? get(idx*2, nl, nm, l, min(nm, r)) : 0)
          + ((nm+1 <= r) ? get(idx*2+1, nm+1, nr, max(nm+1, l), r) : 0);
    if(ret >= MOD) ret -= MOD;
    return ret;
  }

  int get(int x, int y) {
    return get(1, 0, N, x, y);
  }
};

using pii = pair<int, int>;

set<pii> intervals[int(2.1e5)];

int main() {
  scanf("%d%d", &N, &Q);

  while(Q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int l, r, x; scanf("%d%d%d", &l, &r, &x);

      set<pii> &alive = intervals[x];
      pii intv(l, r);
      
      if(alive.empty()) {
        alive.insert(intv);
        segtree::add(l, r, 1);
        continue;
      }

      auto it = alive.lower_bound(pii(l, -1));
      if(it != alive.begin()) {
        it--;
      }
      if(it != alive.end() && it->second < l) {
        it++;
      }

      if(it == alive.end()) {
        alive.insert(intv);
        segtree::add(l, r, 1);
        continue;
      }

      if(it->second < l || it->first > r) {
        alive.insert(intv);
        segtree::add(l, r, 1);
        continue;
      }

      if(it->first < intv.first)
        intv.first = it->first;

      int last = l-1;
      while(it != alive.end()) {
        pii intersection (max(it->first, l), min(it->second, r));
        if(intersection.first <= intersection.second) {
          if(last < intersection.first - 1) {
            segtree::add(last + 1, intersection.first - 1, 1);
          }
          segtree::multiply(intersection.first, intersection.second, 2);
          last = intersection.second;
          if(intv.second < it->second)
            intv.second = it->second;
          
          auto tmp = it;
          it++;
          alive.erase(tmp);
        }else {
          break;
        }
      }

      if(last < r) {
        segtree::add(last + 1, r, 1);
      }
      alive.insert(intv);
    }else {
      int l, r; scanf("%d%d", &l, &r);
      printf("%d\n", segtree::get(l, r));
    }
  }
  return 0;
}