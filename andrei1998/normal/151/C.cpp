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

    lint q = 0;
    cin >> q;

    if (q == 1) {
        cout << "1\n";
        cout << "0\n";
    }
    else {
        vector <lint> factors;

        for (lint i = 2; i * i <= q; i++)
            if (q % i == 0) {
                while (q % i == 0) {
                    factors.pb(i);
                    q /= i;
                }
            }

        if (q > 1)
            factors.pb(q);

        if (factors.size() == 1){
            cout << "1\n";
            cout << "0\n";
        }
        else if (factors.size() == 2) {
            cout << "2\n";
        }
        else {
            lint ans = q;
            q /= factors[0];
            q /= factors[1];

            cout << "1\n";
            cout << factors[0] * factors[1] << endl;
        }
    }

    return 0;
}