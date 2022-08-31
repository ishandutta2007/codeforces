#include <iostream>
#include <string>

using namespace std;

char iseq [10005];
char nseq [10005];

int main () {
  string s;
  cin >> s;
  for (int i = 1; i <= s.size(); i++) {
    iseq[i] = s.at(i-1);
  }

  int queryc, l, r, k;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    cin >> l >> r >> k;
    for (int j = l; j <= r; j++) {
      nseq[(((j-l)+k) % (r-l+1))+l] = iseq[j];
    }
    for (int j = l; j <= r; j++) {
      iseq[j] = nseq[j];
    }
  }

  for (int i = 1; i <= s.size(); i++) {
    cout << iseq[i];
  }
  cout << endl;
}