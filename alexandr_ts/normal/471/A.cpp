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
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    sort(a, a + 6);
    if (a[0] == a[3])
        if (a[4] == a[5])
            cout << "Elephant";
        else
            cout << "Bear";
    else if (a[1] == a[4])
        cout << "Bear";
    else if (a[2] == a[5])
        if (a[0] == a[1])
            cout << "Elephant";
        else
            cout << "Bear";
    else
        cout << "Alien";

}