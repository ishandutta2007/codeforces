#include <bits/stdc++.h>
using namespace std;
const int N = 12, M = 10004;

int n;
string a[N];

map<string, int> q;

void solv()
{
    q.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        q[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (q[a[i]] > 1)
        {
            --q[a[i]];
            ++ans;
            for (char j = '0'; j <= '9'; ++j)
            {
                a[i][3] = j;
                if (q[a[i]] == 0)
                {
                    q[a[i]]++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << endl;
    }
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