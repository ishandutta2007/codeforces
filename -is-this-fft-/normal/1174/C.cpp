#include <iostream>
#include <map>

using namespace std;

const int MAX_P = 1e5 + 5;

int factor [MAX_P];
int color [MAX_P];

int main () {
  int n;
  cin >> n;

  int cur = 1;
  for (int i = 2; i <= n; i++) {
    if (factor[i] == 0) {
      color[i] = cur;
      cur++;
      for (int j = i; j <= n; j += i) {
        factor[j] = i;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << color[factor[i]] << " ";
  }
  cout << endl;
}