#include <bits/stdc++.h>
#define fr(i, n) for (int = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-10;
const int INF = 2e9 + 1;

bool isprime(int n) {
    frab(i, 2, sqrt(n) + 1)
        if (n % i == 0 && i < n)
            return false;
    return true;
}

int main() {
    //freopen ("manyangle.in", "r", stdin);
    char c1, c2;
    cin >> c1 >> c2;
    if (c1 > 'a' && c1 < 'h')
        if (c2 == '1' || c2 == '8')
            cout << 5;
        else
            cout << 8;
    else if (c2 == '1' || c2 == '8')
        cout << 3;
    else
        cout << 5;

}