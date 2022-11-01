#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-9;

ll ans = 0;

void gcd(ll a, ll b) {
    if (!b) return;
    ans += a / b;
    gcd(b, a % b);
}

int main() {
    //freopen("a.in", "r", stdin);
    ll a, b;
    cin >> a;
    if (a == 0) {
        cout << "zero";
        return 0;
    }
    if (a >= 10 && a <= 19) {
        if (a == 10) cout << "ten";
        if (a == 11) cout << "eleven";
        if (a == 12) cout << "twelve";
        if (a == 13) cout << "thirteen";
        if (a == 14) cout << "fourteen";
        if (a == 15) cout << "fifteen";
        if (a == 16) cout << "sixteen";
        if (a == 17) cout << "seventeen";
        if (a == 18) cout << "eighteen";
        if (a == 19) cout << "nineteen";
        return 0;

    }
    b = a / 10;
    a %= 10;
    if (b == 9) cout << "ninety";
    if (b == 8) cout << "eighty";
    if (b == 7) cout << "seventy";
    if (b == 6) cout << "sixty";
    if (b == 5) cout << "fifty";
    if (b == 4) cout << "forty";
    if (b == 3) cout << "thirty";
    if (b == 2) cout << "twenty";
    if (b >= 2 && a != 0)
        cout << "-";

    if (a == 9) cout << "nine";
    if (a == 8) cout << "eight";
    if (a == 7) cout << "seven";
    if (a == 6) cout << "six";
    if (a == 5) cout << "five";
    if (a == 4) cout << "four";
    if (a == 3) cout << "three";
    if (a == 2) cout << "two";
    if (a == 1) cout << "one";
}