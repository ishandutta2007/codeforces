#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double mi=100000;
    for (int i = 0; i< n; ++i) {
        double a, b;
        cin >> a >> b;
        a/=b;
        mi=min(mi, a);
    }
    cout.precision(9);
    cout << mi*m;
}