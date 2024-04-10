#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];
int n;
set<int> g[MAX_N];
int cnt[MAX_N];
bool used[MAX_N];
int d[MAX_N];
int b[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i += 2)
        cin >> a[i];
    int pr = 0;
    for (int i = 0; i < MAX_N; i++)
        b[i] = -1;
    for (int i = 1; i < n; i += 2)
    {
        int k = a[i];
        if (k % 2 == 1)
        {
            for (auto e = 1; e * e <= k; e += 2)
            {
                if (k % e == 0)
                {
                    int x = (k / e) / 2 - e / 2;
                    if (x > pr && (x < b[i - 1] || b[i - 1] == -1))
                    {
                        b[i - 1] = x;
                        b[i] = x + e;
                    }
                    int e1 = k / e;
                    x = (k / e1) / 2 - e1 / 2;
                    if (x > pr && (x < b[i - 1] || b[i - 1] == -1))
                    {
                        b[i - 1] = x;
                        b[i] = x + e1;
                    }
                }
            }
        }
        else
        {
            for (auto e = 2; e * e <= k; e += 2)
            {
                if (k % e == 0 && (k / e) % 2 == 0)
                {
                    int x = (k / e - 1) / 2 - e / 2 + 1;
                    if (x > pr && (x < b[i - 1] || b[i - 1] == -1))
                    {
                        b[i - 1] = x;
                        b[i] = x + e;
                    }
                    int e1 = k / e;
                    if (e1 % 2 != 0)
                        continue;
                    x = (k / e1 - 1) / 2 - e1 / 2 + 1;
                    if (x > pr && (x < b[i - 1] || b[i - 1] == -1))
                    {
                        b[i - 1] = x;
                        b[i] = x + e1;
                    }
                }
            }
        }
        pr = b[i];
    }
    bool u = true;
    for (int i = 0; i < n; i++)
    {
        if (!(b[i] >= 1 && (i == 0 || b[i] > b[i - 1])))
            u = false;
    }
    if (!u)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    cout << b[0] * b[0] << " ";
    for (int i = 1; i < n; i++)
    {
        cout << b[i] * b[i] - b[i - 1] * b[i - 1] << " ";
    }
}