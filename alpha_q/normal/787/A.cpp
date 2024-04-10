#include <bits/stdc++.h> 

using namespace std;

int main (int argc, char const *argv[]) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = 0; i <= 1000000; ++i) {
    int curr = i * a + b - d;
    if (curr % c == 0) {
      curr /= c;
      if (curr >= 0) {
        printf("%d\n", i * a + b);
        return 0;
      }
    } 
  }
  puts("-1");
  return 0;
}