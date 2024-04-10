#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll a[N];
bool pr[N];

vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, tmp;
    cin >> n;
    int a25 = 0, a50 = 0, a100 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 25)
            a25++;
        if (tmp == 50)
            a25--, a50++;
        if (tmp == 100)
            a50--, a25--;
        if (a50 == -1 && a25 >= 2)
            a50++, a25 -= 2;
        if (a25 < 0 || a50 < 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}