#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 50500;
const int N = 31 * M;

struct Node {
  Node *to[2];
  int sz;

  Node() {
    sz = 0;
    to[0] = to[1] = nullptr;
  }

} pool[N];
int last;

Node* getNode() {
  pool[last] = Node();
  return pool + last++;
}

Node* root;

int n, y[M];
int b[M], t;
vector<int> bits[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> y[i];

  for (int i = 0; i < n; ++i) {
    int cur = y[i];
    while (cur) {
      bits[i].push_back(cur & 1);
      cur >>= 1;
    }
  }
}

void add(vector<int> &a, int len) {
  Node *cur = root;
  for (int i = a.size() - 1; i >= len; --i) {
    int x = a[i];
    cur->sz++;
    if (cur->to[x] == nullptr)
      cur->to[x] = getNode();
    cur = cur->to[x];
  }
  cur->sz++;
}

int dfs(Node *v, int cur) {
  if (v == nullptr)
    return 0;

  int ans = dfs(v->to[0], cur << 1) + dfs(v->to[1], (cur << 1) | 1);
  if (cur > 0 && ans < v->sz) {
    ++ans;
    b[t++] = cur;
  }
  return ans;
}

bool pos(int x) {
  last = 0;
  root = getNode();

  for (int i = 0; i < n; ++i) {
    int cur = y[i];
    int len = 0;
    while (cur > x) {
      cur >>= 1;
      ++len;
    }
    add(bits[i], len);
  }
  t = 0;
  return dfs(root, 0) >= n;
}


void kill() {
  int l = 1, r = (1 << 30), m;
  while (l < r) {
    m = (l + r) / 2;
    if (pos(m))
      r = m;
    else
      l = m + 1;
  }
  pos(l);
  for (int i = 0; i < n; ++i)
    cout << b[i] << " ";
  cout << "\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}