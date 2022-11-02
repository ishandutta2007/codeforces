#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b)
{
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int g = gcd(180, a);
        a /= g;
        int b = 180 / g;
        int left = 0;
        int right = 1000 * 1000 * 1000;
        while (right - left > 1)
        {
            //cout << " " << left << " " << right << endl;
            int m = (left + right) / 2;
            int y = b * m;
            int x = a * m;
            if (x <= y - 2)
                right = m;
            else
                left = m;
        }
        cout << b * right << "\n";
    }
}