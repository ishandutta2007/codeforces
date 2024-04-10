#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> A (n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i]--;
  }

  vector<int> iB (n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;

    iB[x] = i;
  }

  int free = 0;
  int cur_pos = -1;
  for (int i = 0; i < n; i++) {
    if (iB[A[i]] < cur_pos) {
      break;
    }

    cur_pos = iB[A[i]];
    free++;
  }

  cout << n - free << endl;
}