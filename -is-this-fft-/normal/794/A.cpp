#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int oleg, lb, ub;
  cin >> oleg >> lb >> ub;

  int notec;
  cin >> notec;

  int ans = 0;
  for (int i = 0; i < notec; i++) {
    int safe;
    cin >> safe;

    if (lb < safe &&
        safe < ub) {
      ans++;
    }
  }

  cout << ans << endl;
}