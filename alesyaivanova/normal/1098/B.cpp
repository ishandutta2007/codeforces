#include <bits/stdc++.h>

using namespace std;

#define int long long

int find_ans(vector<vector<int> >& a, int n, int m)
{
    int ans = 1000 * 1000 * 1000;
    int ans_i, ans_e, ans_p, ans_t;
    for (int i = 0; i < 4; i++)
    {
        for (int e = i + 1; e < 4; e++)
        {
            int p = 0;
            while (p == i || p == e)
                p++;
            int t = 0;
            while (t == i || t == e || t == p)
                t++;
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                int cnt[2] = {};
                for (int k = 0; k < m; k++)
                {
                    if (j % 2 == 0 && a[j][k] != i)
                        cnt[k % 2]++;
                    if (j % 2 == 0 && a[j][k] != e)
                        cnt[1 - k % 2]++;
                    if (j % 2 == 1 && a[j][k] != p)
                        cnt[k % 2]++;
                    if (j % 2 == 1 && a[j][k] != t)
                        cnt[1 - k % 2]++;
                }
                cur += min(cnt[0], cnt[1]);
            }
            if (cur < ans)
            {
                ans = cur;
                ans_i = i;
                ans_e = e;
                ans_p = p;
                ans_t = t;
            }
        }
    }
    int i = ans_i, e = ans_e, p = ans_p, t = ans_t;
    for (int j = 0; j < n; j++)
    {
        int cnt[2] = {};
        for (int k = 0; k < m; k++)
        {
            if (j % 2 == 0 && a[j][k] != i)
                cnt[k % 2]++;
            if (j % 2 == 0 && a[j][k] != e)
                cnt[1 - k % 2]++;
            if (j % 2 == 1 && a[j][k] != p)
                cnt[k % 2]++;
            if (j % 2 == 1 && a[j][k] != t)
                cnt[1 - k % 2]++;
        }
        if (cnt[0] <= cnt[1])
        {
            for (int k = 0; k < m; k++)
            {
                if (j % 2 == 0 && k % 2 == 0)
                    a[j][k] = i;
                if (j % 2 == 0 && k % 2 == 1)
                    a[j][k] = e;
                if (j % 2 == 1 && k % 2 == 0)
                    a[j][k] = p;
                if (j % 2 == 1 && k % 2 == 1)
                    a[j][k] = t;
            }
        }
        else
        {
            for (int k = 0; k < m; k++)
            {
                if (j % 2 == 0 && k % 2 == 0)
                    a[j][k] = e;
                if (j % 2 == 0 && k % 2 == 1)
                    a[j][k] = i;
                if (j % 2 == 1 && k % 2 == 0)
                    a[j][k] = t;
                if (j % 2 == 1 && k % 2 == 1)
                    a[j][k] = p;
            }
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a[i].resize(m);
        for (int e = 0; e < m; e++)
        {
            if (s[e] == 'A')
                a[i][e] = 0;
            else if (s[e] == 'G')
                a[i][e] = 1;
            else if (s[e] == 'C')
                a[i][e] = 2;
            else
                a[i][e] = 3;
        }
    }
    vector<vector<int> > b(m);
    for (int i = 0; i < m; i++)
    {
        b[i].resize(n);
        for (int e = 0; e < n; e++)
            b[i][e] = a[e][i];
    }
    int ans1 = find_ans(a, n, m);
    int ans2 = find_ans(b, m, n);
    if (ans1 < ans2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int e = 0; e < m; e++)
            {
                if (a[i][e] == 0)
                    cout << "A";
                else if (a[i][e] == 1)
                    cout << "G";
                else if (a[i][e] == 2)
                    cout << "C";
                else
                    cout << "T";
            }
            cout << "\n";
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int e = 0; e < m; e++)
            {
                if (b[e][i] == 0)
                    cout << "A";
                else if (b[e][i] == 1)
                    cout << "G";
                else if (b[e][i] == 2)
                    cout << "C";
                else
                    cout << "T";
            }
            cout << "\n";
        }
    }
}