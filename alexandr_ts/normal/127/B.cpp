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

int a[N];
int b[N];

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int qua = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
            qua++, i++;
    }
    cout << qua / 2;
}