#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

vector <int> rev(vector <int> v) {
  reverse(v.begin(), v.end());
  return v;
}

bool attempt(int x) {
  vector <int> rest;
  for (int i = 0; i < N; i++)
    if (a[i] != x)
      rest.push_back(a[i]);
  return rev(rest) == rest;
}

bool solve() {
  for (int i = 0; i < N; i++)
    if (a[i] != a[N - i - 1])
      return attempt(a[i]) || attempt(a[N - i - 1]);
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}