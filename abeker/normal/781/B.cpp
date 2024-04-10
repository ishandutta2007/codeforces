#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
using namespace std;

const int MAXN = 1005;

int N;
string club[MAXN], city[MAXN];
multiset <string> S[MAXN];
map <string, int> cnt;
string f[MAXN], s[MAXN];
string sol[MAXN];

void load() {
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> club[i] >> city[i];
}

void bye() {
  puts("NO");
  exit(0);
}

void solve() {
  for (int i = 0; i < N; i++) {
    f[i] = club[i].substr(0, 3);
    s[i] = club[i].substr(0, 2) + city[i].substr(0, 1);
    S[i].insert(f[i]);
    S[i].insert(s[i]);
    cnt[f[i]]++;
  }
  
  for (int i = 0; i < N; i++)
    if (cnt[f[i]] > 1)
      S[i].erase(S[i].find(f[i]));
  
  for (int k = 0; k < N; k++) {
    int idx = -1;
    for (int i = 0; i < N; i++)
      if (S[i].size() == 1) {
        idx = i;
        break;
      }
    if (idx == -1)
      break;
    sol[idx] = *S[idx].begin();
    for (int i = 0; i < N; i++)
      if (S[i].count(sol[idx]))
        S[i].erase(sol[idx]);
  }
  
  for (int i = 0; i < N; i++)
    if (S[i].empty() && sol[i].empty())
      bye();
  
  for (int i = 0; i < N; i++)
    if (sol[i].empty())
      sol[i] = f[i];
  
  puts("YES");
  for (int i = 0; i < N; i++)
    puts(sol[i].c_str());
}

int main() {
  load();
  solve();
  return 0;
}