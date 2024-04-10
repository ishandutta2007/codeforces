#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;

bitset <N> vis;
vector <int> pr;
int n, size;
map <int, int> k;
map <int, int> a[N];

void sieve (void) {
  for (int i = 2; i * i < N; ++i) {
    if (vis[i]) continue;
    for (int j = i * i; j < N; j += i) {
      vis[j] = 1;
    }
  }
  for (int i = 2; i < N; ++i) {
    if (vis[i]) continue;
    pr.push_back(i);
  }
  size = pr.size();
}

void factor (int x, map <int, int> &f) {
  for (int i = 0; i < size and pr[i] * 1LL * pr[i] <= x; ++i) {
    if (x % pr[i]) continue;
    while (x % pr[i] == 0) {
      ++f[pr[i]];
      x /= pr[i];
    }
  }
  if (x > 1) {
    ++f[x];
  }
}

// does p divide q
bool isDivisible (map <int, int> &q, map <int, int> &p) {
  for (auto it : p) {
    if (q.find(it.first) == q.end()) {
      return 0;
    }
    if (q[it.first] < it.second) {
      return 0;
    }
  }
  return 1;
}

// p = p * q
void multiply (map <int, int> &p, map <int, int> &q) {
  for (auto it : q) {
    p[it.first] += it.second;
  }
}

void print (map <int, int> &f) {
  for (auto it : f) {
    cout << it.first << " --> " << it.second << endl;
  }
  cout << endl;
}

// p = p / q
void divide (map <int, int> &p, map <int, int> &q) {
  // cout << "p-->\n"; print(p); cout<<"q-->\n"; print(q);
  for (auto it : q) {
    // cout << it.first << " " << p[it.first] << " " << it.second << endl;
    // assert(p[it.first] >= it.second);
    p[it.first] -= it.second;
  }
}

int main() {
  sieve();
  int x;
  scanf("%d %d", &n, &x);
  factor(x, k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    factor(x, a[i]);
  }
  long long tot = 0;
  map <int, int> cur = a[1];
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= n and !isDivisible(cur, k)) {
      multiply(cur, a[++j]);
    }
    tot += (long long) (n + 1 - j);
    divide(cur, a[i]);
    if (i == j) multiply(cur, a[++j]);
  }
  printf("%lld\n", tot);
  return 0;
}