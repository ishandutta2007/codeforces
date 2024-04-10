#include <bits/stdc++.h>
using namespace std;
double PI = atan(1) * 4;
int main() {
    int t;
    cin >> t;
    while (t--) {
        double n;
        cin >> n;
        n *= 2;
        printf("%.10f\n", cos(PI / 2 / n) / sin(PI / n));
    }
    return 0;
}