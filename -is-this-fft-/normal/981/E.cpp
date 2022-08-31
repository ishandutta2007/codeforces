#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 5;
const int BLOCKW = 80;
typedef bitset<MAX_N> bits;

struct Query {
  int l, r, x;
};

int n, q;
Query queries [MAX_N];
int on [MAX_N];
int evc [MAX_N];

int curl, curr;
bool over_block (const Query &qs) {
  return qs.l <= curl && curr <= qs.r;
}

bool contains (const Query &qs, int idx) {
  return qs.l <= idx && idx <= qs.r;
}

bits prefix;
void rebuild (int pos) {
  curl = pos;
  curr = min(n, curl + BLOCKW);
  
  prefix.reset();
  prefix[0] = 1;
  for (int i = 0; i < q; i++) {
    if (over_block(queries[i])) {
      prefix = prefix | (prefix << queries[i].x);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n >> q;

  for (int i = 0; i < q; i++) {
    cin >> queries[i].l >> queries[i].r >> queries[i].x;
    evc[queries[i].l]++;
    evc[queries[i].r]++;
  }

  bits ans;
  bits cur;
  for (int i = 1; i <= n; i++) {
    if (i > curr) {
      rebuild(i);
    }

    cur = prefix;
    for (int j = 0; j < q; j++) {
      if (contains(queries[j], i) && !over_block(queries[j])) {
        cur = cur | (cur << queries[j].x);
      }
    }
    ans |= cur;
  }

  vector<int> ansv;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      ansv.push_back(i);
    }
  }

  cout << (int) ansv.size() << endl;
  for (int u : ansv) {
    cout << u << " ";
  }
  cout << endl;
}