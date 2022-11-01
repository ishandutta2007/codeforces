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

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k;
    cin >> n >> k;
    cout << k * (6 * n - 1) << endl;
    for (int i = 0; i < n; i++)
        cout << k*(6*i+1) << " " << k*(6*i+2) << " " << k*(6*i+3) << " " << k*(6*i+5) << endl;



}