#include <iostream>

using namespace std;

const int MAX_SQ = 1e3 + 5;
const int MAX_A = MAX_SQ * MAX_SQ;

bool is_sq [MAX_A];

int main () {
  for (int i = 0; i < MAX_SQ; i++) {
    is_sq[i * i] = 1;
  }

  int n;
  cin >> n;

  int ans = -MAX_A;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x < 0 || !is_sq[x]) {
      ans = max(ans, x);
    }
  }

  cout << ans << endl;
}