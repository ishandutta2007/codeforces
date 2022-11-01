#include <bits/stdc++.h>
 
using namespace std;

int a, b, c;

int main (int argc, char const *argv[]) {
    cin >> a >> b >> c;
    int x = a, y = b/2, z = c/4;
    int r = min(x, min(y, z));
    cout << 7 * r << '\n';
    return 0;
}