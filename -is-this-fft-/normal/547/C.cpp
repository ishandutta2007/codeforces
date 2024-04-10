#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;
const int MAX_P = 5e5 + 5;

int factor [MAX_P];
int types [MAX_N];
vector<int> factors [MAX_N];

vector<int> get_factors (int x) {
  vector<int> ans;
  while (x != 1) {
    ans.push_back(factor[x]);
    int f = factor[x];
    while (x % f == 0) {
      x /= f;
    }
  }
  return ans;
}

int isin [MAX_N];
int cnt [MAX_P];
ll pairc;

int sgn [2] = {1, -1};

void del (const vector<int> &fs) {
  for (int mask = 0; mask < 1 << fs.size(); mask++) {
    int cur = 1;
    for (int i = 0; i < (int) fs.size(); i++) {
      if (mask & 1 << i) {
        cur *= fs[i];
      }
    }
    cnt[cur]--;
    pairc -= sgn[__builtin_popcount(mask) % 2] * cnt[cur];
  }
}

void add (const vector<int> &fs) {
  for (int mask = 0; mask < 1 << fs.size(); mask++) {
    int cur = 1;
    for (int i = 0; i < (int) fs.size(); i++) {
      if (mask & 1 << i) {
        cur *= fs[i];
      }
    }
    pairc += sgn[__builtin_popcount(mask) % 2] * cnt[cur];
    cnt[cur]++;
  }
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 2; i < MAX_P; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_P; j += i) {
        factor[j] = i;
      }
    }
  }
  
  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> types[i];
    factors[i] = get_factors(types[i]);
  }

  for (int i = 0; i < qc; i++) {
    int x;
    cin >> x;

    if (isin[x]) {
      del(factors[x]);
      isin[x] = 0;
    } else {
      add(factors[x]);
      isin[x] = 1;
    }

    cout << pairc << '\n';
  }
}