#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const double pi=3.141592653589793;
    int t;
    cin >> t;
    while(t--)
    {
        double n;
        cin >> n;
        cout << fixed << setprecision(9) << cos(pi/(4*n))/sin(pi/(2*n)) << "\n";
    }
    return 0;
}