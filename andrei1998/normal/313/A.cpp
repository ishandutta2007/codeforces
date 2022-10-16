#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int rem_last (int x) {
    if (x > 0) {
        return x / 10;
    }
    else {
        return -((-x) / 10);
    }
}

int rem_secondlast (int x) {
    if (x > 0) {
        return (x / 100) * 10 + x % 10;
    }
    else {
        x = - x;
        return -((x / 100) * 10 + x % 10);
    }
}

int main()
{
    int n = 0;
    cin >> n;

    int nn = rem_last(n);
    int nnn = rem_secondlast(n);

    cout << max(max(n, nn), nnn) << endl;
    return 0;
}