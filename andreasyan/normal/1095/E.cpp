#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];

int p[N];

int s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> a;
    int b = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
            ++b;
    }
    if (abs(b - (n - b)) != 2)
    {
        cout << 0 << endl;
        return 0;
    }

    if (a[0] == '(')
        p[0] = 1;
    else
        p[0] = -1;
    for (int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == '(')
            p[i]++;
        else
            p[i]--;
    }
    s[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; --i)
        s[i] = min(s[i + 1], p[i]);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(' && b > (n - b))
        {
            if (s[i] - 2 >= 0)
                ++ans;
        }
        if (a[i] == ')' && b < (n - b))
        {
            if (s[i] + 2 >= 0)
                ++ans;
        }
        if (p[i] < 0)
            break;
    }

    cout << ans << endl;
    return 0;
}