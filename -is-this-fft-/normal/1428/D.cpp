#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> ans;
  vector<int> stk1;
  vector<int> stk2;
  for (int i = n; i >= 1; i--) {
    if (arr[i] == 1) {
      ans.push_back(make_pair(i, i));
      stk1.push_back(i);
    } else if (arr[i] == 2) {
      if (stk1.empty()) {
        failure();
      }
      
      int partner = stk1.back();
      stk1.pop_back();

      ans.push_back(make_pair(partner, i));
      stk2.push_back(i);
    } else if (arr[i] == 3) {
      int partner;
      if (!stk2.empty()) {
        partner = stk2.back();
        stk2.pop_back();
      } else if (!stk1.empty()) {
        partner = stk1.back();
        stk1.pop_back();
      } else {
        failure();
      }
        
      ans.push_back(make_pair(i, i));
      ans.push_back(make_pair(i, partner));
      stk2.push_back(i);
    }
  }

  cout << (int) ans.size() << '\n';
  for (auto pr : ans) {
    cout << pr.first << " " << pr.second << '\n';
  }
}