#include <bits/stdc++.h>
using namespace std;

bool solution(int n, int a, int b) {
    if (a == 1) {
        return (n - 1) % b == 0;
    }

    long long i = 1;
    while (i <= n) {
        if ((n - i) % b == 0) {
            return true;
        }
        i *= a;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << (solution(n, a, b) ? "Yes\n" : "No\n");
    }
}