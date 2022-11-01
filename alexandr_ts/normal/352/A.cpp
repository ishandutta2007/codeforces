#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 30000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;
ll a[N];
ll b[N];
bool an[N];
bool am[N];
vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int qua5 = 0, qua0 = 0;
    for (int i = 0; i < n; i++)
        if (a[i])
            qua5++;
    else
        qua0++;
    if (qua0 == 0)
        cout << -1;
    else
    {
        for (int i = 0; i < qua5 / 9; i++)
            cout << 555555555;
        if (qua5 >= 9)
        for (int i = 0; i < qua0; i++)
            cout << 0;
            else
                cout << 0;
    }

}