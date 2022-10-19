#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+2;
vector<int> pairs[N];
int partners[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "First" << endl;
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        cout << j << " ";
      }
    }
    cout << endl;
  }
  else {
    cout << "Second" << endl;
    set<int> unusedmods;
    for (int i = 1; i <= 2*n; i++) {
      int a;
      cin >> a;
      pairs[a].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      unusedmods.insert(i);
      vector<int> pairing = pairs[i];
      partners[pairing[0]] = pairing[1];
      partners[pairing[1]] = pairing[0];
    }
    vector<int> first;
    vector<int> second;
    while (unusedmods.size() > 0) {
      int mod = *unusedmods.begin();
      while (unusedmods.count((mod - 1) % n + 1)) {
        first.push_back(mod);
        int val = mod > n ? mod - n :  mod + n;
        second.push_back(val);
        unusedmods.erase((mod - 1) % n + 1);
        mod = partners[val];
      }
    }
    if (accumulate(first.begin(), first.end(), 0LL) % 2*n != 0) swap(first, second);
    for (int i: first) {
      cout << i << " ";
    }
    cout << endl;
  }
}