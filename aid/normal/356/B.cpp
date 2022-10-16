#include <iostream>
#include <string>

using namespace std;

const int MAXLEN = 1000 * 1000 + 5, SIGMA = 26;
int c[MAXLEN][SIGMA];

int gcd(int p, int q) {
    return q? gcd(q, p % q) : p;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    string x, y;
    cin >> x >> y;
    int g = gcd(x.length(), y.length());
    for(size_t i = 0; i < x.length(); i++)
        c[i % g][x[i] - 'a']++;
    long long ans = 0;
    for(size_t i = 0; i < y.length(); i++)
        ans += c[i % g][y[i] - 'a'];
    long long k = n * x.length() / ((long long)x.length() / g * y.length());
    cout << n * x.length() - ans * k << '\n';
}