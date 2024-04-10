#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

bool eq(char a, char b) {
  if (a == '?') {
    return true;
  }
  return a == b;
}

bool check(string s) {
  int n = s.size();
  int cnt1 = 0;
  string s2 = "abacaba";
  for (int i = 0; i + 7 <= n; i++) {
    if (s.substr(i, 7) == s2) {
      cnt1++;
    }
  }
  return cnt1 == 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0;
    string s2 = "abacaba";
    for (int i = 0; i + 7 <= n; i++) {
      if (s.substr(i, 7) == s2) {
	cnt1++;
      }
    }
    if (cnt1 > 1) {
      cout << "NO" << endl;
    } else if (cnt1 == 1) {
      cout << "YES" << endl;
      for (char c : s) {
	if (c == '?') {
	  cout << 'z';
	} else {
	  cout << c;
	}
      }
      cout << endl;
    } else {
      bool found = false;
      for (int i = 0; i + 7 <= n; i++) {
	bool bad = false;
	for (int j = 0; j < 7; j++) {
	  if (!eq(s[i + j], s2[j])) {
	    bad = 1;
	    break;
	  }
	}
	if (!bad) {
	  
	  string s3 = s;
	  for (int j = 0; j < 7; j++) {
	    s3[i + j] = s2[j];
	  }
	  if (check(s3)) {
	    s = s3;
	    found = 1;
	    break;
	  }
	}
      }
      if (found) {
	cout << "YES" << endl;
	for (char c : s) {
	  if (c == '?') {
	    cout << "z";
	  } else {
	    cout << c;
	  }
	}
	cout << endl;
      } else {
	cout << "NO" << endl;
      }
    }
  }
}