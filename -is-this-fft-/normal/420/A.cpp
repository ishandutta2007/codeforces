#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  set<char> allowed =
    {'A', 'H', 'I', 'M', 'O',
     'T', 'U', 'V', 'W', 'X', 'Y'};
  
  string s;
  cin >> s;

  for (char c : s) {
    if (!allowed.count(c)) {
      failure();
    }
  }

  string t = s;
  reverse(t.begin(), t.end());

  if (s != t) {
    failure();
  }

  cout << "YES" << endl;
}