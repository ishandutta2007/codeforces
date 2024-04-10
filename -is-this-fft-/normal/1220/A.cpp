#include <iostream>
#include <string>

using namespace std;

int cnt [200];

int main () {
  int x;
  string str;
  cin >> x >> str;

  for (char c : str) {
    cnt[c]++;
  }

  int numc = min(cnt['o'], cnt['e']);
  int zc = min(cnt['z'], cnt['r']);
  int oc = cnt['n'];

  numc = min(numc, zc + oc);
  zc = min(zc, numc - oc);

  for (int i = 0; i < oc; i++) {
    cout << 1 << " ";
  }
  for (int i = 0; i < zc; i++) {
    cout << 0 << " ";
  }
  cout << endl;
}