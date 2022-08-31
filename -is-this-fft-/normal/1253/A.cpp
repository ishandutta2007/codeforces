#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int length;
  cin >> length;

  vector<int> A (length + 2), B (length + 2);
  for (int i = 1; i <= length; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= length; i++) {
    cin >> B[i];
  }

  vector<int> dA (length + 1), dB (length + 1);
  for (int i = 0; i <= length; i++) {
    dA[i] = A[i + 1] - A[i];
    dB[i] = B[i + 1] - B[i];
  }

  vector<int> ch;
  for (int i = 0; i <= length; i++) {
    if (dA[i] != dB[i]) {
      ch.push_back(dB[i] - dA[i]);
    }
  }

  if (ch.empty()) {
    cout << "YES" << '\n';
  } else if (ch.size() == 2) {
    if (ch[0] > 0 && ch[1] == -ch[0]) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  } else {
    cout << "NO" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}