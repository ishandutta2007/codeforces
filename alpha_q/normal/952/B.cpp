#include <bits/stdc++.h>

using namespace std;

vector <string> w({"no", "no", "no", "no", "no", "great", "not bad", "cool", "dont think so", "dont touch me"});
vector <string> v({"no", "no", "no", "no way", "no way", "terrible", "are you serious", "worse", "go die in a hole", "don't even"});

int main() {
  string s;
  int gr = 0, no = 0;
  for (int i = 0; i < 10; ++i) {
    cout << i << endl;
    getline(cin, s);
    for (int i = 0; i < (int) v.size(); ++i) {
      if (v[i] == s) {
        v.erase(v.begin() + i);
        ++gr;
        break;
      }
    }
    for (int i = 0; i < (int) w.size(); ++i) {
      if (w[i] == s) {
        w.erase(w.begin() + i);
        ++no;
        break;
      }
    }
    if (gr == no) continue;
    cout << (gr > no ? "grumpy" : "normal") << endl;
    return 0;
  }
  cout << (gr > no ? "grumpy" : "normal") << endl;
  return 0;
}