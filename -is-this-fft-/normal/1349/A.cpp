#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

typedef long long ll;

int factor [MAX_N];
vector<int> visits [MAX_N];

void process (int x) {
  while (x != 1) {
    int p = factor[x];
    int pp = 1;
    while (x % p == 0) {
      pp *= p;
      x /= p;
    }
    visits[p].push_back(pp);
  }
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 2; i < MAX_N; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_N; j += i) {
        factor[j] = i;
      }
    }
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    process(x);
  }

  ll ans = 1;
  for (int i = 1; i < MAX_N; i++) {
    if ((int) visits[i].size() == n - 1) {
      int mn = 1e9;
      for (auto p : visits[i]) {
        mn = min(mn, p);
      }
      ans *= mn;
    } else if ((int) visits[i].size() == n) {
      int mn = 1e9;
      int smn = 1e9;
      for (auto p : visits[i]){
        if (p < mn) {
          smn = mn;
          mn = p;
        } else if (p < smn) {
          smn = p;
        }
      }
      ans *= smn;
    }
  }

  cout << ans << endl;
}