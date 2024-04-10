#include <bits/stdc++.h>
using namespace std;

void output(vector<int>& s) {
  int k = s.size();
  for (int i = 0; i < k; i++) {
    cout << s[i] << ".\n"[i+1==k];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> s;
    while (n--) {
      int x;
      cin >> x;
      if (x == 1) s.push_back(x);
      else {
        while (s.size() && s.back()+1 != x) s.pop_back();
        if (s.size()) s.back()++;
      }
      output(s);
    }
  }
}