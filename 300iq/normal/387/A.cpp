#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
    int a, b;
    char c;
    int s, p;
    cin >> a >> c >> b;
    s = a * 60 + b;
    cin >> a >> c >> b;
    p = a * 60 + b;
    s -= p;
    int h = 24 * 60;
    s = (s % h + h) % h;
    a = s / 60, b = s % 60;
    if (a < 10) {
        cout << "0";
    }
    cout << a;
    cout << c;
    if (b < 10)
        cout << "0";
    cout << b << endl;
}