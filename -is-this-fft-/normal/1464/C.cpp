#include <iostream>

using namespace std;

typedef long long ll;

void failure () {
  cout << "No" << endl;
  exit(0);
}

const int MAX_A = 60;

int cnt [MAX_A];

int main () {
  int n;
  ll T;
  cin >> n >> T;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    int x = c - 'a';
    if (i == n - 2) {
      T += 1LL << x;
    } else if (i == n - 1) {
      T -= 1LL << x;
    } else {
      cnt[x]++;
    }
  }

  for (int i = 0; i < MAX_A; i++) {
    T += cnt[i] * (1LL << i);
  }

  if (T < 0) failure();
  if (T % 2 == 1) failure();

  for (int i = 0; i < MAX_A - 1; i++) {
    if (T & 1LL << (i + 1)) {
      if (!cnt[i]) {
        failure();
      } else {
        cnt[i]--;
      }
    }
    cnt[i + 1] += cnt[i] / 2;
  }

  cout << "Yes" << endl;
}