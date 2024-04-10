#include <bits/stdc++.h>

using namespace std;

int main() {
   double d, l, v1, v2;
   cin >> d >> l >> v1 >> v2;
   double ans = l - d;
   ans /= (v1 + v2);
   cout << setprecision(20) << ans << endl;
}