#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cur_l = 0;
  vector<int> anses;
  while (cur_l < n) {
    set<int> s;
    set<int> ss;
    int i = cur_l;
    do {
      if (arr[i] > 0) {
        if (s.count(arr[i])) {
          cout << -1 << endl;;
          return 0;
        }
        s.insert(arr[i]);
        ss.insert(arr[i]);
      } else if (!ss.count(-arr[i])) {
        cout << -1 << endl;
        return 0;
      } else {
        ss.erase(-arr[i]); 
      }
      i++;
    } while (!ss.empty() && i < n);
    if (!ss.empty()) {
      cout << -1 << endl;
      return 0;
    }
    anses.push_back(i - cur_l);
    cur_l = i;
  }
  cout << anses.size() << endl;
  for (int el : anses) {
    cout << el << " ";
  }
  cout << endl;
  return 0;
}