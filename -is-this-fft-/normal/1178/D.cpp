#include <iostream>

using namespace std;

const int MAX_N = 1050;

int sieve [MAX_N];
int primeAfter [MAX_N];

int main () {
  for (int i = 2; i < MAX_N; i++) {
    if (!sieve[i]) {
      for (int j = 2 * i; j < MAX_N; j += i) {
        sieve[j] = 1;
      }
    }
  }

  for (int i = MAX_N - 2; i >= 0; i--) {
    if (sieve[i] == 0) {
      primeAfter[i] = i;
    } else {
      primeAfter[i] = primeAfter[i + 1];
    }
  }

  int vertexc;
  cin >> vertexc;

  if (vertexc == 6) {
    cout << 7 << '\n';
    cout << "1 2\n2 3\n3 4\n4 5\n5 6\n6 1\n1 3\n";
    return 0;
  }
  
  cout << primeAfter[vertexc] << '\n';
  
  int toAdd = primeAfter[vertexc] - vertexc;
  int v = 1;
  while (toAdd >= 2) {
    cout << v << " " << v + 1 << '\n';
    cout << v + 1 << " " << v + 2 << '\n';
    cout << v + 2 << " " << v + 3 << '\n';
    cout << v + 3 << " " << v << '\n';
    cout << v << " " << v + 2 << '\n';
    cout << v + 1 << " " << v + 3 << '\n';
    toAdd -= 2;
    v += 4;
  }

  while (toAdd >= 1) {
    cout << v << " " << v + 1 << '\n';
    cout << v + 1 << " " << v + 2 << '\n';
    cout << v + 2 << " " << v + 3 << '\n';
    cout << v + 3 << " " << v << '\n';
    cout << v << " " << v + 2 << '\n';
    toAdd -= 1;
    v += 4;
  }

  if (v < vertexc) {
    for (int i = v; i < vertexc; i++) {
      cout << i << " " << i + 1 << '\n';
    }
    cout << vertexc << " " << v << '\n';
  }
}