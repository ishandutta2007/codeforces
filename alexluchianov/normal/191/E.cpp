#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int const lgmax = 20;
int const nmax = 100000;
int v[1 + nmax];

ll pref[1 + nmax];
ll far[1 + lgmax][1 + nmax];
ll far2[1 + lgmax][1 + nmax];
ll aux[1 + nmax];

void build(int from, int to, int level) {
  if(from < to) {
    int mid = (from + to) / 2;
    build(from, mid, level + 1);
    build(mid + 1, to, level + 1);
   
    ll sumleft = pref[mid] - pref[from - 1], sumright = pref[to] - pref[mid];
    for(int i = from; i <= mid; i++)
      far2[level + 1][i] += sumright;
    for(int i = mid + 1; i <= to; i++)
      far[level + 1][i] += sumleft;

    std::merge(far[level + 1] + from, far[level + 1] + mid + 1,
               far[level + 1] + mid + 1, far[level + 1] + to + 1,
               far[level] + from);
    std::merge(far2[level + 1] + from, far2[level + 1] + mid + 1,
               far2[level + 1] + mid + 1, far2[level + 1] + to + 1,
               far2[level] + from);
    
    for(int i = from; i <= mid; i++)
      far2[level + 1][i] -= sumright;
    for(int i = mid + 1; i <= to; i++)
      far[level + 1][i] -= sumleft;

  } else
    far2[level][from] = far[level][from] = v[from];
}

ll solve(int from, int to, int level, ll target) {
  if(from < to) {
    int mid = (from + to) / 2;
    int ptr = mid + 1;
    ll result = solve(from, mid, level + 1, target) + solve(mid + 1, to, level + 1, target);
    for(int i = mid; from <= i; i--) {
      while(ptr <= to && far2[level + 1][i] + far[level + 1][ptr] < target)
        ptr++;
      result += (to + 1) - ptr;
    }
    return result;
  } else 
    return (target <= v[from]);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  ll k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    pref[i] = pref[i - 1] + v[i];
  build(1, n, 1);
  ll x = -(1LL << 60);
  for(ll jump = (1LL << 60); 0 < jump; jump /= 2) {
    if(k <= solve(1, n, 1, x + jump))
      x += jump;
  }
  std::cout << x << '\n';
  return 0;
}