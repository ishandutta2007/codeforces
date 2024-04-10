#include <bits/stdc++.h>

using namespace std;

const int LEAF = 1<<14;
int N, Q;
vector<int> tree[LEAF + LEAF];

using ds = bitset<10001>;

ds ans;

void go(int nd, int nl, int nr, ds cur) {
  for(int c : tree[nd]) {
    cur = cur | (cur << c);
  }

  if(nl == nr) {
    ans |= cur;
    return;
  }

  int nm = (nl + nr) >> 1;
  go(nd * 2, nl, nm, cur);
  go(nd * 2 + 1, nm+1, nr, cur);
}

int main() {
  scanf("%d%d", &N, &Q);
  while(Q--) {
    int l, r, c; scanf("%d%d%d", &l, &r, &c);
    l += LEAF;
    r += LEAF;
    while(l <= r) {
      if((l & 1) == 1) tree[l].push_back(c);
      if((r & 1) == 0) tree[r].push_back(c);
      l = (l + 1) >> 1;
      r = (r - 1) >> 1;
    }
  }  

  go(1, 1, LEAF, ds(1));

  vector<int> pos;
  for(int i = 1; i <= N; i++) if(ans[i]) pos.push_back(i);

  printf("%lu\n", pos.size());
  for(int i : pos) printf("%d ", i);

  return 0;
}