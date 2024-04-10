#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 30;

int a [MAX_N], s [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[i] = a[i];
  }

  sort(s, s + n);
  map<int, int> spos;
  for (int i = 0; i < n; i++) {
    spos[s[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << s[(spos[a[i]] + 1) % n] << " ";
  }
  cout << endl;
}