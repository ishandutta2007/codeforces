#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

int main () {
  string s;
  cin >> s;

  for (int i = 2; i < (int) s.size(); i++) {
    int l1 = s[i - 2] - 'A';
    int l2 = s[i - 1] - 'A';
    int cur = s[i] - 'A';
    if ((l1 + l2) % 26 != cur) {
      failure();
    }
  }

  cout << "YES" << endl;
}