#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int b, k;
    cin >> b >> k;
    b %= 2;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i] %= 2;
    }
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        x *= b;
        x += a[i];
        x %= 2;
    }
    if (x == 0)
        cout << "even";
    else
        cout << "odd";
}