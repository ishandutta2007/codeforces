#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

string s, t;
map<string, int> to;
int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void ini() {
  to["mo"] = 0;
  to["tu"] = 1;
  to["we"] = 2;
  to["th"] = 3;
  to["fr"] = 4;
  to["sa"] = 5;
  to["su"] = 6;
}

void read() {
  cin >> s >> t;
  s = s.substr(0, 2);
  t = t.substr(0, 2);
}

void kill() {
  int x = to[s];
  int y = to[t];
  for (int i = 0; i + 1 < 12; ++i)
    if ((x + m[i]) % 7 == y) {
      cout << "YES\n";
      return;
    }
  cout << "NO\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  ini();
  read();
  kill();
}