#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1003;
const int N = 1e6 + 10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int x1 = 0, x2 = 1023;
    fr(i, n) {
        char ch;
        cin >> ch;
        int x;
        cin >> x;
        if (ch == '|') {
            x1 |= x;
            x2 |= x;
        }
        else if (ch == '^') {
            x1 ^= x;
            x2 ^= x;
        }
        else {
            x1 &= x;
            x2 &= x;
        }
    }

    int and1 = 1023, or1 = 0, xor1 = 0;

    fr(i, 10) {
        int m = (1 << i);
        if ((m & x1) && (m & x2)) {
            or1 |= m;
        }
        else if (!(m & x1) && !(m & x2)) {
            and1 ^= m;
        }
        else if (m & x1) {
            xor1 |= m;
        }
    }

    cout << 3 << endl;
    cout << "| " << or1 << endl;
    cout << "^ " << xor1 << endl;
    cout << "& " << and1 << endl;
}