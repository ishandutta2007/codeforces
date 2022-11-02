#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  map<char, char> par = {{']', '['}, {')', '('}, {'}', '{'}, {'>', '<'}};
  string s;
  cin >> s;
  int ans = 0;
  vector<char> st;
  for(char c : s) {
    if(par.count(c)) {
      if(st.empty()) {
        cout << "Impossible";
        return 0;
      }
      if(par[c] != st.back()) {
        ans++;
      }
      st.pop_back();
    } else {
      st.push_back(c);
    }
  }
  if(st.empty()) {
    cout << ans;
  } else {
    cout << "Impossible";
  }
}