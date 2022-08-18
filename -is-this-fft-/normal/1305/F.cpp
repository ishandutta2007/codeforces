#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_SQ = 1e6 + 5;

int sieve [MAX_SQ];
vector<int> primes;

vector<ll> factors (ll x) {
  vector<ll> ans;
  if (x == 0) return ans;
  for (int p : primes) {
    if (x % p == 0) {
      ans.push_back(p);
      while (x % p == 0) {
        x /= p;
      }
    }
  }
  if (x != 1) {
    ans.push_back(x);
  }

  return ans;
}

const int MAX_N = 2e5 + 5;

int n;
ll arr [MAX_N];

ll best;
void test (ll p) {
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll cur = arr[i] % p;
    if (arr[i] == cur) {
      ans += p - cur;
    } else {
      ans += min(cur, p - cur);
    }
    if (ans > best) return;
  }

  best = min(best, ans);
}

const int ITERS = 100;

int main () {
  for (int i = 2; i < MAX_SQ; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i; j < MAX_SQ; j += i) {
        sieve[j] = 1;
      }
    }
  }
  
  mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  shuffle(arr, arr + n, rng);

  best = 3 * n;
  test(2);

  set<ll> seen;
  for (int i = 0; i < min(n, ITERS); i++) {
    for (int k = -1; k <= 1; k++) {
      vector<ll> facts = factors(arr[i] + k);
      for (ll p : facts) {
        if (seen.count(p) == 0) {
          seen.insert(p);
          test(p);
        }
      }
    }
  }

  cout << best << endl;
}