#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> nutpos;
  int length;
  cin >> length;
  
  for (int i = 0; i < length; i++) {
    int piece;
    cin >> piece;
    if (piece == 1) {
      nutpos.push_back(i);
    }
  }

  if (nutpos.size() == 0) {
    cout << 0 << endl;
  } else {
    long long ans = 1;
    for (int i = 0; i < nutpos.size() - 1; i++) {
      ans *= nutpos[i + 1] - nutpos[i];
    }

    cout << ans << endl;
  }
}