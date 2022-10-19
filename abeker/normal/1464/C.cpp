#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll T;
int N;
char s[MAXN];

void load() {
  scanf("%d%lld%s", &N, &T, s);
}

bool solve() {
  vector <int> cnt(100);
  for (int i = 0; i < N; i++) {
    int tmp = s[i] - 'a';
    if (i == N - 1)
      T -= 1 << tmp;
    else if (i == N - 2)
      T += 1 << tmp;
    else {
      T += 1 << tmp;
      cnt[tmp]++;
    } 
  }
  if (T % 2 || T < 0)
    return false;
  T /= 2;
  for (int i = 0; i < 99; i++) {
    cnt[i] -= T % 2;
    if (cnt[i] < 0)
      return false;
    cnt[i + 1] += cnt[i] / 2;
    T /= 2;
  }
  return !T;
}

int main() {
  load();
  puts(solve() ? "Yes" : "No");
  return 0;
}