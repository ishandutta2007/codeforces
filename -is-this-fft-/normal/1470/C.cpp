#include <iostream>
#include <chrono>
#include <random>

using namespace std;

mt19937 rng;

int n, K;

int norm (int pos) {
  pos %= n;
  if (pos < 0) {
    pos += n;
  }
  pos %= n;
  return pos;
}

int ask (int pos) {
  pos = norm(pos);
  pos++;
  cout << "? " << pos << '\n';

  int resp;
  cin >> resp;

  return resp;
}

void report (int pos) {
  pos = norm(pos);
  pos++;
  cout << "! " << pos << '\n';
  exit(0);
}

const int MAX_T = 512;

void bss (int pos) {
  int add = 0;
  for (int k = MAX_T; k != 0; k /= 2) {
    if (add + k < n / 2) {
      if (ask(pos + add + k) < K) {
        add += k;
      }
    }
  }

  report(pos + add + 1);
}

void bsl (int pos) {
  int add = 0;
  for (int k = MAX_T; k != 0; k /= 2) {
    if (add + k < n / 2) {
      if (ask(pos - (add + k)) > K) {
        add += k;
      }
    }
  }

  report(pos - (add + 1));
}

int main () {
  rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
  ios::sync_with_stdio(false);

  cin >> n >> K;

  while (true) {
    int pos = rng() % n;

    int val = ask(pos);
    if (val < K) {
      bss(pos);
    } else if (val > K) {
      bsl(pos);
    }
  }
}