#include <iostream>
#include <vector>

using namespace std;

int ask (string str) {
  cout << str << endl;

  int ans;
  cin >> ans;

  if (ans < 0) exit(0);
  if (ans == 0) exit(0);
  return ans;
}

string make_of (vector<int> v) {
  string ans;
  for (int k = 0; k < (int) v.size(); k++) {
    if (k != 0) {
      ans += 'a';
    }
    for (int i = 0; i < v[k]; i++) {
      ans += 'b';
    }
  }
  return ans;
}

int main () {
  int n = ask(string("a")) + 1;

  if (n > 300) {
    string ones;
    for (int i = 0; i < n - 1; i++) {
      ones += 'b';
    }
    ask(ones);    
  }

  string zeros;
  for (int i = 0; i < n; i++) {
    zeros += 'a';
  }

  int onec = ask(zeros);
  if (onec == n) {
    string ones;
    for (int i = 0; i < n - 1; i++) {
      ones += 'b';
    }
    ask(ones);
    exit(0);
  }
  int zeroc = n - onec;

  vector<int> curv (zeroc + 1);
  for (int i = 0; i <= zeroc; i++) {
    while (true) {
      curv[i]++;
      int cur = ask(make_of(curv));
      if (cur != n - (int) make_of(curv).size()) {
        curv[i]--;
        break;
      }
    }
  }
}