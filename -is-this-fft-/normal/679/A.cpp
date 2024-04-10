#include <iostream>
#include <vector>

using namespace std;

const int MAX_P = 50;

bool ask (int n) {
  cout << n << endl;

  string resp;
  cin >> resp;

  return resp[0] == 'y';
}

int sieve [MAX_P];

int main () {
  vector<int> primes;
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }
  
  int a2 = ask(2);
  int a3 = ask(3);
  int a5 = ask(5);
  int a7 = ask(7);
  if (!(a2 || a3 || a5 || a7)) {
    cout << "prime" << endl;
    exit(0);
  }

  if (a2 + a3 + a5 + a7 > 1) {
    cout << "composite" << endl;
    exit(0);
  }

  // determine if n is one of these four
  int pdiv = a2 * 2 + a3 * 3 + a5 * 5 + a7 * 7;

  if (ask(pdiv * pdiv)) {
    cout << "composite" << endl;
    exit(0);
  }

  for (int p : primes) {
    if (p > 10 && p * pdiv <= 100) {
      if (ask(p)) {
        cout << "composite" << endl;
        exit(0);
      }
    }
  }

  cout << "prime" << endl;
}