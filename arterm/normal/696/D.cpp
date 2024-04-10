#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 239;
const int A = 30;
const ll inf = ll(2e18) + 10;

struct Node {
  Node* next[A];
  Node* p;
  int by;
  int cost;
  Node* link;
  Node* go[A];
  int id;

  Node() {
    fill(next, next + A, nullptr);
    p = nullptr;
    by = -1;
    cost = 0;
    link = nullptr;
    fill(go, go + A, nullptr);
    id = -1;
  }

} pool[M];

int last = 0;

Node *getNode() {
  pool[last].id = last;
  return pool + last++;
}

int n;
ll l;
int a[M], b[M];
vector<int> g[M];
Node *root;

Node* go(Node *cur, int x);
Node* getLink(Node *cur);

Node* getLink(Node *cur) {
  if (cur->link == nullptr) {
    if (cur == root || cur->p == root)
      cur->link = root;
    else
      cur->link = go(getLink(cur->p), cur->by);
  }
  return cur->link;
}

Node* go(Node *cur, int x) {
  if (cur->go[x] == nullptr) {
    if (cur->next[x] != nullptr)
      cur->go[x] = cur->next[x];
    else
      cur->go[x] = cur == root ? root : go(getLink(cur), x);
  }
  return cur->go[x];
}
  

void read() {
  cin >> n >> l;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  root = getNode();

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    
    Node *cur = root;

    for (char c : s) {
      int x = c - 'a';
      if (cur->next[x] == nullptr) {
        cur->next[x] = getNode();

        Node *nxt = cur->next[x];
        nxt->p = cur;
        nxt->by = x;

      }
      cur = cur->next[x];
    }

    cur->cost += a[i];
  }
}

struct Matrix {
  ll a[M][M];

  Matrix() {
    for (int i = 0; i < M; ++i)
      fill(a[i], a[i] + M, -inf);
  }

  ll* operator[](int x) {
    return a[x];
  }
} I;

Matrix operator*(Matrix &A, Matrix &B) {
  Matrix C;
  for (int i = 0; i < M; ++i)
    for (int k = 0; k < M; ++k)
      for (int j = 0; j < M; ++j) {
        C[i][j] = max(A[i][k] + B[k][j], C[i][j]);
      }
  return C;
}

Matrix bin(Matrix A, ll to) {
  Matrix B = I;
  while (to) {
    if (to & 1)
      B = B * A;
    A = A * A;
    to >>= 1;
  }
  return B;
}

void kill() {
  for (int i = 0; i < M; ++i)
    I[i][i] = 0;

  for (int i = 0; i < last; ++i) {
    Node *cur = pool + i;
    while (cur != root) {
      b[i] += cur->cost;
      cur = getLink(cur);
    }

    cur = pool + i;
    for (int x = 0; x < A; ++x)
      g[i].push_back(go(cur, x) - pool);
  }
    
  Matrix A;

  for (int i = 0; i < last; ++i)
    for (int to : g[i])
      A[i][to] = max<ll>(A[i][to], b[to]);

  A = bin(A, l);

  ll ans = 0;
  for (int i = 0; i < last; ++i)
    ans = max(ans, A[0][i]);

  cout << ans << "\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}