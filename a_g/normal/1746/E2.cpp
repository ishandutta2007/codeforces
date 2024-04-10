#include <bits/stdc++.h>
using namespace std;

// ecnerwala's solution

bool query(vector<int>& a) {
  cout << "? " << a.size();
  for (int x: a) cout << ' ' << x;
  cout << endl;
  string ans;
  cin >> ans;
  return ans == "YES";
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> no_lies(n), one_lie;
  iota(no_lies.begin(), no_lies.end(), 1);
  while ((int)no_lies.size() + (int)one_lie.size() > 2) {
    vector<int> query_set;
    int a = (int)no_lies.size();
    int b = (int)one_lie.size();
    int bs = b/2;
    int as = (a+1+(b&1))/2;
    vector<int> new_no_lies;
    vector<int> new_one_lie;
    for (int i = 0; i < as; i++) {
      query_set.push_back(no_lies[i]);
    }
    for (int i = 0; i < bs; i++) {
      query_set.push_back(one_lie[i]);
    }
    if (query(query_set)) {
      new_no_lies.insert(new_no_lies.end(), no_lies.begin(), no_lies.begin()+as);
      new_no_lies.insert(new_no_lies.end(), one_lie.begin(), one_lie.begin()+bs);
      new_one_lie.insert(new_one_lie.end(), no_lies.begin()+as, no_lies.end());
    }
    else {
      new_one_lie.insert(new_one_lie.end(), no_lies.begin(), no_lies.begin()+as);
      new_no_lies.insert(new_no_lies.end(), one_lie.begin()+bs, one_lie.end());
      new_no_lies.insert(new_no_lies.end(), no_lies.begin()+as, no_lies.end());
    }
    no_lies = new_no_lies;
    one_lie = new_one_lie;
  }
  for (vector<int> v: {no_lies, one_lie}) {
    for (int x: v) {
      cout << "! " << x << endl;
      string ans;
      cin >> ans;
      if (ans == ":)") return 0;
    }
  }
}