#include <bits/stdc++.h>

using namespace std;

char a[6], b[6];

int main() {
    for (int i = 0; i < 4; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> b[i];
    string x = "", y = "";
    if (a[0] != 'X') x += a[0];
    if (a[1] != 'X') x += a[1];
    if (a[3] != 'X') x += a[3];
    if (a[2] != 'X') x += a[2];
    if (b[0] != 'X') y += b[0];
    if (b[1] != 'X') y += b[1];
    if (b[3] != 'X') y += b[3];
    if (b[2] != 'X') y += b[2];
    string z = "";
    int j;
    for (j = 0; j < 3; j++) if (y[j] == x[0]) break;
    for (int i = j; i < j + 3; i++) z += y[i % 3];
    if (z == x) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}