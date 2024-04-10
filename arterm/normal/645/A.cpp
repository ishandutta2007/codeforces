#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

string norm(string s) {
  for (int i = 0; i < 2; ++i)
    if (s[i] == 'X')
      swap(s[i], s[i + 2]);

  if (s[2] == 'X')
    swap(s[2], s[3]);


  while (s[0] != 'A') {
    swap(s[3], s[2]);
    swap(s[2], s[0]);
    swap(s[0], s[1]);
    swap(s[1], s[3]);
  }
  return s;
}

void read() {
  string s, t;
  string d;
  
  cin >> s >> d;
  s += d;

  cin >> t >> d;
  t += d;

  if (norm(s) == norm(t))
    cout << "YES\n";
  else
    cout << "NO\n";
}


void kill() {

}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}