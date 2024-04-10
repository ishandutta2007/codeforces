#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool palin (string s) {
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != s[(int) s.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

bool allsame (string s) {
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != s[0]) {
      return false;
    }
  }
  return true;
}

int countother (string s, char c) {
  int ans = 0;
  for (char d : s) {
    if (d != c) {
      ans ++;
    }
  }
  return ans;
}

int main () {
  string src;
  cin >> src;

  string orig = src;

  vector<string> path;
  int oddc = 0;
  while (true) {
    if (src.size() == 1 || !palin(src)) {
      path.push_back(src);
      break;
    } else if ((int) src.size() % 2 == 0) {
      path.push_back(string(""));
      src = src.substr(0, (int) src.size() / 2);
    } else {
      char mid = src[(int) src.size() / 2];
      path.push_back(string("") + mid);
      src = src.substr(0, (int) src.size() / 2);
      oddc++;
    }
  }

  if (path.back().size() != 1) {
    if (oddc == 0) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  } else {
    if (countother(orig, orig[0]) <= 1) {
      cout << "Impossible" << endl;
    } else {
      cout << 2 << endl;
    }
  }
}