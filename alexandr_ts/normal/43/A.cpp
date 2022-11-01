#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 10000001ll;
const ll MOD = 1000000007ll;

bool prime[N];

set <ll> divs;
set <ll> :: iterator it;

string a[10];
int b[10];

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    a[1] = "12Z1!?!@#$%^&*adkfkja";
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (i == 0)
        {
            a[0] = s;
            b[0]++;
        }
        else
            if (a[0] != s)
                if (a[1] == s)
                    b[1]++;
                else
                    a[1] = s;
            else
                b[0]++;

    }
    if (b[0] > b[1])
        cout << a[0];
    else
        cout << a[1];
}