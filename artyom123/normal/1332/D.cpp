#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    int MX = (1 << 18) - 1;
    int p = (1 << 17);
    int a[3][3];
    a[0][0] = a[0][1] = a[1][0] = a[2][1] = a[1][2] = MX;
    a[2][0] = a[0][2] = p;
    a[1][1] = a[2][2] = k;
    cout << 3 << " " << 3 << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}