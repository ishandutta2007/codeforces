#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll val = (i&1 ? 1LL<<(i+j-1) : 0);
      cout << val << " ";
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    vector<pair<int, int>> pieces(n/2);
    int index = 0;
    for (int i = 0; i < 60; i++) {
      if (k&(1LL<<i)) {
        int start = i;
        while (k&(1LL<<(i+1))) i++;
        pieces[index] = {start-2*index, i-2*index};
        //cout << pieces[index].first << " " << pieces[index].second << endl;
        index++;
      }
    }
    index = 0;
    while (index < n/2) {
      int s = (index == 0 ? 0 : pieces[index-1].second);
      int t = pieces[index].first;
      int u = pieces[index].second;
      // cout << s << " " << t << endl;
      for (int i = s; i <= t; i++) {
        cout << 2*index+1 << " " << i+1 << endl;
      }
      for (int i = t; i <= u; i++) {

        cout << 2*index+2 << " " << i+1 << endl;
      }
      index++;
    }
    if (n&1) {
      int t = pieces[n/2-1].second;
      for (int i = t; i < n; i++) {
        cout << n << " " << i+1 << endl;
      }
    }
  }
}