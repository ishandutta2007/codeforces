#include <bits/stdc++.h>
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> s >> n;
    vector<int> vals;
    int mod = 1;
    while (s > 0) {
      int a = s % (10*mod);
      if (a) {
        int digit = (a / mod);
        for (int i = 0; i < digit; i++) {
          vals.push_back(mod);
        }
        s -= a;
      }
      mod *= 10;
    }
    while (vals.size() < n) {
      int split = 0;
      while (vals[split] == 1) {
        split += 1;
      }
      int digit = vals[split];
      int a = vals[split];
      int mul = 1;
      while (digit >= 10) {
        digit /= 10;
        mul *= 10;
      }
      if (digit > 1) {
        vals[split] = mul;
        vals.insert(vals.begin()+split, a-mul);
      }
      else {
        mul /= 10;
        vals[split] = mul;
        vals.insert(vals.begin()+split, a-mul);
      }
    }

    while (vals.size() > n) {
      vals[1] += vals[0];
      vals.erase(vals.begin());
    }

    for (int i: vals) {
      cout << i << " ";
    }
    cout << endl;
  }
}