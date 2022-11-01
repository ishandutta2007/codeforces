#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll a[100000];

int main()
{
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll summ = 0;
    for(ll i = 0; i < n; i++)
        summ += a[i];
    summ /= n;

    ll ans = 0;
    ll cur = 0;
    for(ll i = 0; i < n - 1; i++)
    {
        ans += fabs(a[i] - summ);
        a[i + 1] += a[i] - summ;
        a[i] = summ;
    }
    cout << ans;
    return 0;
}