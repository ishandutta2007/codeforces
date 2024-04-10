#include <bits/stdc++.h> 

using namespace std;

int n, h;

int main (int argc, char const *argv[]) {
  cin >> n >> h;
  for (int i = 1; i < n; ++i) {
    double x = h * sqrt(1.0 * i / n);
    printf("%0.12f ", x);
  } 
  puts("");
  return 0;
}