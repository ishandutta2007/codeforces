#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    while (b > 0) {
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    long long a, b, w, h;
    cin >> a >> b >> w >> h;
    long long w1 = w / gcd(w, h), h1 = h / gcd(w, h);
    cout << min(a / w1, b / h1);
    return 0;
}