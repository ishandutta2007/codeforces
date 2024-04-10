#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, n;
   cin >> a >> b >> c >> n;
   int tot = a + b - c;
   if (tot >= n) {
    cout << -1;
    return 0;
   }
   if (a < c || b < c) {
       cout << -1;
       return 0;
   }
   cout << n - tot;
    return 0;
}