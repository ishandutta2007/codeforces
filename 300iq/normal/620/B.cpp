#include <bits/stdc++.h>

using namespace std;

main() {
    int segm[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int a, b;
    cin >> a >> b;
    int t = 0;
    for (int i = a; i <= b; i++) {
        int n = i;
        while (n > 0) {
            t += segm[n % 10];
            n /= 10;
        }
    }
    cout << t << endl;
}