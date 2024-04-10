#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LOG = 20;

int N;
vector <string> ans;
unordered_set <ll> have;

void add(ll a, ll b, char op) {
  assert(have.count(a) && have.count(b));
  ans.push_back(to_string(a) + ' ' + op + ' ' + to_string(b));
}

void apply_plus(ll a, ll b) {
  add(a, b, '+');
  have.insert(a + b);
}

void apply_xor(ll a, ll b) {
  add(a, b, '^');
  have.insert(a ^ b);
}

void apply_or(ll a, ll b) {
  apply_plus(a, b);
  apply_xor(a, b);
  apply_plus(a + b, a ^ b);
}

void apply_and(ll a, ll b) {
  apply_or(a, b);
  apply_plus(a ^ b, a ^ b);
  apply_xor(2 * (a | b), 2 * (a ^ b));
}

void solve(int x) {
  int hibit = -1;
  for (int i = LOG - 1; i >= 0; i--)
    if (x >> i & 1) {
      hibit = i;
      break;
    }
  if (!hibit)
    return;
  for (int i = 0; i < hibit; i++)
    apply_plus((ll)x * (1 << i), (ll)x * (1 << i));
  apply_and(x, (ll)x * (1 << hibit));
  int curr = x;
  for (int i = 0; i < hibit; i++) {
    apply_plus(curr, curr);
    curr *= 2;
    if (curr >> hibit + 1 & 1) {
      apply_xor(curr, 1 << hibit + 1);
      curr ^= 1 << hibit + 1;
    }
  }
  apply_xor(x, 1 << hibit);
  solve(x ^ 1 << hibit);
}

int main() {
  scanf("%d", &N);
  have.insert(N);
  solve(N);
  assert(have.count(1));
  assert(ans.size() <= 100000);
  printf("%d\n", ans.size());
  for (auto it : ans)
    puts(it.c_str());
  return 0;
}