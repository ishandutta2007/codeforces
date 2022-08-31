#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

typedef long long ll;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int length;

ll solve_cyc (int k) {
  // length * (# of segment lengths with gcd(n, s) = k
  // O(n)

  ll lenc = 0;
  for (int s = k; s < length; s += k) {
    if (gcd(length, s) == k) {
      lenc++;
    }
  }

  return lenc * length;
}

ll solve_block (int b, int k) {
  // O(b)

  ll ans = 0;
  for (int s = k; s <= b; s += k) {
    if (gcd(length, s) == k) {
      ans += b - s + 1;
    }
  }
  return ans;
}

int arr [MAX_N];
int ok [MAX_N];

int dom [MAX_N];
ll solve_for (int k) { // k = gcd(s, n)
  for (int i = 0; i < k; i++) {
    dom[i] = 0;
  }

  for (int i = 0; i < length; i++) {
    dom[i % k] = max(dom[i % k], arr[i]);
  }

  for (int i = 0; i < length; i++) {
    ok[i] = (dom[i % k] == arr[i]);
  }

  vector<int> blocks;
  for (int i = 0; i < length; i++) {
    if (ok[i]) {
      if (i == 0 || !ok[i - 1]) {
        blocks.push_back(0);
      }
      blocks.back()++;
    }
  }

  if (ok[length - 1] && ok[0] && (int) blocks.size() >= 2) {
    blocks[0] += blocks.back();
    blocks.pop_back();
  }

  if (!blocks.empty() && blocks[0] == length) {
    return solve_cyc(k);
  }

  ll ans = 0;
  for (int block : blocks) {
    ans += solve_block(block, k); 
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> length;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  set<int> divs;
  for (int i = 1; i * i <= length; i++) {
    if (length % i == 0) {
      divs.insert(i);
      divs.insert(length / i);
    }
  }

  ll ans = 0;
  for (int d : divs) {
    if (d != length) {
      ans += solve_for(d);
    }
  }

  cout << ans << endl;
}