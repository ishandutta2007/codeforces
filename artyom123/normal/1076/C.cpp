#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        double d;
        cin >> d;
        if (0 < d && d < 4) {
            cout << "N" << "\n";
            continue;
        }
        double D = d * d - 4 * d;
        cout << fixed << setprecision(10) << "Y" << " " << (d + sqrt(D)) / 2.00 << " " << (d - sqrt(D)) / 2.00 << "\n";
    }
    return 0;
}