#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n, k;
  int m;
  cin >> n >> m >> k;
  vector<ll> pages(m);
  for (int i = 0; i < m; i++) cin >> pages[i];
  int i = 0;
  int ops = 0;
  while (i < m) {
    int prev = i;
    ll pagenum = (pages[i]-1-prev)/k;
    i++;
    while (i < m && ((pages[i]-1-prev)/k == pagenum)) i++;
    ops++;
  }
  cout << ops << endl;
}