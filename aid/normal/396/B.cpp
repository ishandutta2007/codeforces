#include <iostream>

using namespace std;

bool prime(int n) {
    for(int i = 2; i * i <= n; i++)
        if(!(n % i))
            return false;
    return true;
}

long long gcd(long long a, long long b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        int p = n, q = n + 1;
        while(!prime(p))
            p--;
        while(!prime(q))
            q++;
        long long num = (long long)p * q - 2 * q + 2 * (n - p + 1),
            den = 2 * (long long)p * q, g = gcd(num, den);
        cout << num / g << '/' << den / g << '\n';
    }
    return 0;
}