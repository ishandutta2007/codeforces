#include <bits/stdc++.h>

using namespace std;

int n, a[100000], D, odd, ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    D = a[0];
    for(int i = 1; i < n; i++) D = __gcd(D, a[i]);
    if(D != 1) return cout << "YES\n0", 0;
    for(int i = 0; i < n; i++)
        if(a[i] & 1) odd++;
        else
        {
            ans += (odd / 2) + 2 * (odd & 1);
            odd = 0;
        }
    cout << "YES\n" << ans + (odd / 2) + 2 * (odd & 1);
}