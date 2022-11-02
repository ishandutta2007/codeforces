#include <bits/stdc++.h>

using namespace std;

#define int long long

int s[1000009];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    int left = n - 2;
    int right = 1000 * 1000 * 1000;
    int cnt = 0;
    while (right - left > 1)
    {
        int m = (left + right) / 2;
        cout << "> " << m << endl;
        int ans;
        cin >> ans;
        cnt++;
        if (ans == 1)
            left = m;
        else
            right = m;
    }
    int a = right;
    int d = 0;
    for (int i = 0; i < n; i++)
        s[i] = i;
    random_shuffle(s, s + n);
    random_shuffle(s, s + n);
    random_shuffle(s, s + n);
    random_shuffle(s, s + n);
    int e = 0;
    for (; cnt < 60 && e < n; cnt++)
    {
        int i = s[e];
        e++;
        cout << "? " << i + 1 << endl;
        int ans;
        cin >> ans;
        d = __gcd(d, a - ans);
    }
    cout << "! " << a - d * (n - 1) << " " << d << endl;
}