#include <bits/stdc++.h>
using namespace std;

// cp-algorithms
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

/*
string longest_palindromic_prefix(string s) {
  int n = s.size();
  if (n == 0) return "";
  string t = s;
  reverse(s.begin(), s.end());
  t += s;
  vector<int> pf = prefix_function(t);
  int k = min(n, pf[2*n-1]); 
  return t.substr(0, k);
}
*/

bool palindromic(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n-1-i]) return 0;
  }
  return 1;
};

string longest_palindromic_prefix(string s) {
  int n = s.size();
  for (int i = n; i >= 1; i--) {
    if (palindromic(s.substr(0, i))) {
      return s.substr(0, i);
    }
  }
  return s.substr(0, 1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int p = 0;
    int n = s.size();
    while (p < n-1-p && s[p] == s[n-1-p]) p++;
    string pref = s.substr(0, p);
    s = s.substr(p, n-2*p);
    string a = longest_palindromic_prefix(s);
    reverse(s.begin(), s.end());
    string b = longest_palindromic_prefix(s);
    if (a.size() < b.size()) swap(a, b);
    cout << pref << a;
    reverse(pref.begin(), pref.end());
    cout << pref << '\n';
  }
}