#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int q;
int ans[26];

int n;
char a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while (q--)
    {
        cin >> a;
        n = strlen(a);

        bool z = true;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != a[0])
                z = false;
        }

        int pq = 0, sq = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != a[0])
                break;
            pq++;
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != a[n - 1])
                break;
            sq++;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (ans[i] == 0)
                continue;
            if (z && i == (a[0] - 'a'))
            {
                ans[i] += (n * (ans[i] + 1));
                continue;
            }
            if (i == (a[0] - 'a') && i == (a[n - 1] - 'a'))
                ans[i] = 1 + sq + pq;
            else if (i == (a[0] - 'a'))
                ans[i] = 1 + pq;
            else if (i == (a[n - 1] - 'a'))
                ans[i] = 1 + sq;
            else
                ans[i] = 1;
        }

        char x = a[0];
        int q = 1;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] == a[i - 1])
                ++q;
            else
            {
                ans[x - 'a'] = max(ans[x - 'a'], q);
                x = a[i];
                q = 1;
            }
        }
        ans[x - 'a'] = max(ans[x - 'a'], q);
    }
    int yans = 0;
    for (int i = 0; i < 26; ++i)
        yans = max(yans, ans[i]);
    cout << yans << endl;
    return 0;
}