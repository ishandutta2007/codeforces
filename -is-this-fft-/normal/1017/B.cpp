#include <iostream>
#include <string>

using namespace std;

typedef long long llong;

int main () {
  string s, t;
  int n;
  cin >> n >> s >> t;

  llong zzc = 0, ozc = 0, zoc = 0, ooc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && t[i] == '0') {
      zzc++;
    } else if (s[i] == '0' && t[i] == '1') {
      zoc++;
    } else if (s[i] == '1' && t[i] == '0') {
      ozc++;
    } else {
      ooc++;
    }
  }

  cout << zzc * ozc + zzc * ooc + zoc * ozc << endl;
}