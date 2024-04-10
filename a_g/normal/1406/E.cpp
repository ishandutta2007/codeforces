#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const int M = 150;
bool prime[N], used[N];

int queryA(int a) {
  cout << "A " << a << endl;
  int ans;
  cin >> ans;
  return ans;
}

int queryB(int a) {
  cout << "B " << a << endl;
  int ans;
  cin >> ans;
  return ans;
}

void finish(int a) {
  cout << "C " << a << endl;
  exit(0);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(prime+2, prime+N, 1);
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = 2*i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
  int n;
  cin >> n;

  int c = n;
  fill(used+1, used+n+1, 1);
  vector<vector<int>> blocks;
  for (int i = 1; i <= n; i++) {
    if (prime[i]) {
      if (blocks.empty() || blocks.back().size() >= M) {
        blocks.push_back(vector<int>(1, i));
      }
      else {
        blocks.back().push_back(i);
      }
    }
  }

  int x = 1;
  for (vector<int> block: blocks) {
    for (int p: block) {
      queryB(p);
      for (int j = p; j <= n; j += p) {
        if (used[j]) {
          used[j] = 0;
          c--;
        }
      }
    }
    if (queryA(1) > c) {
      for (int p: block) {
        bool found = 0;
        for (long long k = p; k <= n && queryA(k); k *= p) {
          x *= p;
          found = 1;
        }
        if (found) {
          for (int q = p+1; 1LL*x*q <= n; q++) {
            if (prime[q]) {
              for (long long k = q; k <= n; k *= q) {
                int expected = 0;
                for (int j = k; j <= n; j += k) {
                  if (used[j]) expected++;
                }
                if (queryA(k) > expected) {
                  x *= q;
                }
                else {
                  break;
                }
              }
            }
          }
          finish(x);
        }
      }
    }
  }

  finish(1);
}