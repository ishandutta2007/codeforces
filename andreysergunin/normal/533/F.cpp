#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;
int n, m;
int pf[MAXN];

void kmp(int a[MAXN])
{
    pf[0] = 0;
    for (int i = 1; i < n + m + 1; i++)
    {
        int j = pf[i-1];
        while (j > 0 && a[i] != a[j])
            j = pf[j-1];
        if (a[i] == a[j])  ++j;
        pf[i] = j;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s, t;
    cin >> n >> m;
    cin >> s;
    cin >> t;

    int b[MAXN];
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < 26; i++)
        for (int j = i + 1; j < 26; j++)
        {
            int f1 = 0;
            int f2 = 0;
            for (int k = 0; k < m; k++)
            {
                if (t[k] == 'a' + j)
                    f1 = 1;
                if (t[k] == 'a' + i)
                    f2 = 1;
            }
            if (f1 + f2 == 0)
                continue;
            int a[MAXN];
            bool f[MAXN];
            for (int k = 0; k < n; k++)
                f[k] = true;
            for (int k = 0; k < m; k++)
                a[k] = ((t[k] == 'a' + j) ? 1 : 0);
            a[m] = 2;
            for (int k = 0; k < n; k++)
                a[k + m + 1] = ((s[k] == 'a' + i) ? 1 : 0);
            kmp(a);
            for (int k = 0; k < n; k++)
                if (pf[k + m + 1] != m)
                    f[k] = false;

            for (int k = 0; k < m; k++)
                a[k] = ((t[k] == 'a' + i) ? 1 : 0);
            a[m] = 2;
            for (int k = 0; k < n; k++)
                a[k + m + 1] = ((s[k] == 'a' + j) ? 1 : 0);
            kmp(a);
            for (int k = 0; k < n; k++)
                if (pf[k + m + 1] != m)
                    f[k] = false;
            for (int k = 0; k < n; k++)
                if (f[k])
                    b[k] += f1 + f2;

        }

    for (int i = 0; i < 26; i++)
    {
        bool fl = true;
        for (int k = 0; k < m; k++)
            if (t[k] == 'a' + i)
                fl = false;;
        if (fl)
            continue;
        int a[MAXN];
        bool f[MAXN];
        for (int k = 0; k < n; k++)
            f[k] = true;
        for (int k = 0; k < m; k++)
            a[k] = ((t[k] == 'a' + i) ? 1 : 0);
        a[m] = 2;
        for (int k = 0; k < n; k++)
            a[k + m + 1] = ((s[k] == 'a' + i) ? 1 : 0);
        kmp(a);
        for (int k = 0; k < n; k++)
            if (pf[k + m + 1] != m)
                f[k] = false;

        for (int k = 0; k < n; k++)
            if (f[k])
                b[k] += 1;
    }


    int r[26];
    for (int i = 0; i < 26; i++)
        r[i] = 0;
    for (int i = 0; i < m; i++)
        r[t[i] - 'a'] = 1;
    int q = 0;
    for (int i = 0; i < 26; i++)
        q += r[i];
    int ans[MAXN];
    int ansn = 0;
    for (int i = 0; i < n; i++)
        if (b[i] == q)
            ans[ansn++] = i;





    cout << ansn << endl;


    sort(ans, ans + ansn);
    for (int i = 0; i < ansn; i++)
        cout << ans[i] + 2 - m << ' ';
    return 0;
}