#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n;
  cin >> n;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    ll val;
    cin >> val;
    total += val;
  }
  ll h = (n*(n-1))/2;
  ll rem = (total + h) % n;
  ll base = (total-h)/n;
  for (int i = 0; i < n; i++) {
    ll v = base + i + (i < rem ? 1 : 0);
    cout << v << " ";
  }
  cout << endl;
}