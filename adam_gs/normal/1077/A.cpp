#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << a*((c+1)/2)-(b*(c/2)) << '\n';
    }
}