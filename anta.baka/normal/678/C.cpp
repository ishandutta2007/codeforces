#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    long long lcm = a / __gcd(a, b) * b;
    cout << (n / a - n / lcm) * p + (n / b - n / lcm) * q + (n / lcm * max(p, q));
    return 0;
}