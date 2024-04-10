#include <bits/stdc++.h>
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int i = 0;
    int j = 0;
    int count = 0;
    set<int> used;
    while (i < n) {
      if (b.at(i) == '1') {
        if (a.at(i) == '0') {
          count++;
        }
        else {
          if (i > 0 && a.at(i-1) == '1' && used.find(i-1) == used.end()) {
            count++;
            used.insert(i-1);
          }
          else if (i < n-1 && a.at(i+1) == '1') {
            count++;
            used.insert(i+1);
          }
        }
      }
      i++;
    }
    cout << count << endl;
  }
}