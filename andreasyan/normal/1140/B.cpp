#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;
    int ans = N;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '>')
        {
            ans = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == '<')
        {
            ans = min(ans, n - i - 1);
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}