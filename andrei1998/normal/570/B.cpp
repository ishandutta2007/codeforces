#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    else if (m == 1) {
        cout << "2\n";
        return 0;
    }
    else if (m == n) {
        cout << n - 1 << '\n';
        return 0;
    }

    int v1 = m - 1;
    int v2 = m + 1;

    int aux1 = m - 1;
    int aux2 = n - m;

    if (aux1 >= aux2)
        cout << v1 << '\n';
    else
        cout << v2 << '\n';
    return 0;
}