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
    int n, k, l, c, d, p ,nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int aux1 = (k * l)/ (nl * n);
    int aux2 = (c * d) / n;
    int aux3 = p / (np * n);

    cout << min(min(aux1, aux2), aux3) << endl;

    return 0;
}