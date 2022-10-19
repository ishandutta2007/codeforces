#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Node {
  int idx, parity;
  Node *nxt, *prev;
};

int N;
char s[MAXN];
Node circle[MAXN];
set <Node*> ones;

void load() {
  scanf("%d%s", &N, s);
}

void update(Node* x) {
  if (x -> parity)
    ones.insert(x);
  else
    ones.erase(x);
}

void output(Node* x, Node* y) {
  printf("%d %d\n", x -> idx, y -> idx);
}

void solve() {
  ones.clear();
  for (int i = 0; i < N; i++) {
    circle[i] = {i + 1, s[i] - '0', circle + (i + 1) % N, circle + (i + N - 1) % N};
    update(circle + i);
  }
  if (ones.empty() || ones.size() % 2) {
    puts("NO");
    return;
  }
  puts("YES");
  Node* curr;
  while (1) {
    curr = *ones.begin();
    if (ones.size() == 2 && curr -> nxt -> parity)
      break;
    output(curr, curr -> nxt);
    curr -> prev -> nxt = curr -> nxt;
    curr -> nxt -> prev = curr -> prev;
    curr -> nxt -> parity ^= 1;
    update(curr -> nxt);
    ones.erase(curr);
  }
  for (Node* x = curr -> nxt; x != curr; x = x -> nxt)
    output(x, x -> nxt);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}