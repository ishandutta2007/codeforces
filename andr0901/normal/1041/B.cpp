#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long g = gcd(x, y);
    //cout << g << endl;
    x /= g;
    y /= g;
    //cout << endl;
    cout << min(a / x, b / y);
    return 0;
}