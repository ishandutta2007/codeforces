#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

int factor [MAX_N];

vector<int> factors (int x) {
  vector<int> ans;
  while (x != 1) {
    int p = factor[x];
    ans.push_back(p);
    while (x % p == 0) {
      x /= p;
    }
  }
  return ans;
}

vector<ll> sums;

int sta [MAX_N];
ll arr [MAX_N];

void solve () {
  int n, qc;
  cin >> n >> qc;

  auto fact = factors(n);
  vector<int> steps;
  for (int p : fact) {
    steps.push_back(n / p);
  }

  sums.clear();
  for (int s : steps) {
    sta[s] = sums.size();
    for (int i = 0; i < s; i++) {
      sums.push_back(0);
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    for (int s : steps) {
      sums[sta[s] + i % s] += (ll) s * arr[i];
    }
  }

  set<pair<ll, int>> best;
  for (int i = 0; i < (int) sums.size(); i++) {
    best.insert({sums[i], i});
  }

  cout << best.rbegin()->first << '\n';
  for (int i = 0; i < qc; i++) {
    int pos, val;
    cin >> pos >> val;
    pos--;

    for (int s : steps) {
      int idx = sta[s] + pos % s;
      best.erase({sums[idx], idx});
      sums[idx] -= (ll) s * arr[pos];
    }

    arr[pos] = val;
    
    for (int s : steps) {
      int idx = sta[s] + pos % s;
      sums[idx] += (ll) s * arr[pos];
      best.insert({sums[idx], idx});
    }

    cout << best.rbegin()->first << '\n';
  }
}

int main () {
  for (int i = 2; i < MAX_N; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_N; j += i) {
        factor[j] = i;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}