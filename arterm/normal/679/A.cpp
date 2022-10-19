#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;
const int B = 107;

bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

bool ask(int x) {
  if (x > 100)
    return false;
  cout << x << endl;
  string ans;
  cin >> ans;
  return ans == "yes";
}

void kill() {
  vector<int> p;
  for (int i = 2; i <= 50; ++i)
    if (isPrime(i))
      p.push_back(i);

  //cerr << p.size() << endl;

  vector<int> d;

  for (int x : p)
    if (ask(x)) {
      d.push_back(x);
    }

  if (d.empty()) {
    cout << "prime" << endl;
    return;
  }

  if (d.size() >= 2) {
    cout << "composite" << endl;
    return;
  }

  if (ask(d[0] * d[0])) {
    cout << "composite" << endl;
  } else {
    cout << "prime" << endl;
  }
}

int main() {
  kill();
}