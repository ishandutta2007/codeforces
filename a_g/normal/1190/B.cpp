#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n;
  cin >> n;
  map<int, int> counts;
  int duplicates = 0;
  int repeatedval;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    total += val;
    if (counts[val]) {
      duplicates += counts[val];
      if (duplicates > 1) {
        cout << "cslnb" << endl;
        return 0;
      }
      repeatedval = val;
    }
    counts[val]++;
  }
  if (duplicates) {
    if (repeatedval == 0 || counts[repeatedval-1] > 0) {
      cout << "cslnb" << endl;
      return 0;
    }
  }
  ll moves = total - ((n-1)*(n))/2;
  cout << (moves & 1 ? "sjfnb" : "cslnb") << endl;
}