#include <bits/stdc++.h>

using namespace std;

int main() {
    double n;
    cin >> n;
    double s=0;
    for (int i = 0; i < n; ++i) {
        double a;
        cin >> a;
        s+=a;
    }
    s/=n;
    cout << s;
}