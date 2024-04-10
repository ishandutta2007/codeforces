#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  int c = 0;
  while (pow(k, c) < n) c++;
  cout << c << endl;
  int colors[n][n];
  for (int i = 0; i < c; i++) {
    int power = (int)pow(k, i);
    for (int j = 0; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if (j/power != k/power) {
          colors[j][k] = i;
        }
      }
    }
  }
  for (int j = 0; j < n; j++) {
    for (int k = j+1; k < n; k++) {
      //cout << j << " " << k << " ";
      cout << colors[j][k]+1 << " ";
      //cout << endl;
    }
  }
  cout << endl;
}