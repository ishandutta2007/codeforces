#include <bits/stdc++.h>

using namespace std;

#define int long long

int q[26];
int k, n;
bool used[26];

bool check(int i, string& s, string& a, int t)
{
    /*cout << i << " " << s << " " << a << " " << t << endl;
    for (int i = 0; i < k; i++)
        cout << char('a' + q[i]);
    cout << endl;*/
    vector<int> ch;
    if (t == 0)
    {
        for (int e = i; e < n; e++)
        {
            int s1 = s[e] - 'a';
            int a1 = a[e] - 'a';
            if (q[s1] != -1 && q[s1] < a1)
            {
                for (int u : ch)
                {
                    used[q[u]] = false;
                    q[u] = -1;
                }
                return false;
            }
            if (q[s1] > a1)
                return true;
            if (q[s1] == a1)
                continue;
            for (int u = a1 + 1; u < k; u++)
            {
                if (!used[u])
                {
                    q[s1] = u;
                    used[u] = true;
                    return true;
                }
            }
            if (used[a1])
            {
                for (int u : ch)
                {
                    used[q[u]] = false;
                    q[u] = -1;
                }
                return false;
            }
            q[s1] = a1;
            used[a1] = true;
            ch.push_back(s1);
        }
        return true;
    }
    else
    {
        for (int e = i; e < n; e++)
        {
            int s1 = s[e] - 'a';
            int a1 = a[e] - 'a';
            if (q[s1] != -1 && q[s1] > a1)
            {
                for (int u : ch)
                {
                    used[q[u]] = false;
                    q[u] = -1;
                }
                return false;
            }
            if (q[s1] != -1 && q[s1] < a1)
                return true;
            if (q[s1] == a1)
                continue;
            for (int u = a1 - 1; u >= 0; u--)
            {
                if (!used[u])
                {
                    q[s1] = u;
                    used[u] = true;
                    return true;
                }
            }
            if (used[a1])
            {
                for (int u : ch)
                {
                    used[q[u]] = false;
                    q[u] = -1;
                }
                return false;
            }
            q[s1] = a1;
            used[a1] = true;
            ch.push_back(s1);
        }
        return true;
    }
}

bool solve()
{
    string s, a, b;
    cin >> k >> s >> a >> b;
    n = s.length();
    for (int i = 0; i < 26; i++)
    {
        q[i] = -1;
        used[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        int s1 = s[i] - 'a';
        int a1 = a[i] - 'a';
        int b1 = b[i] - 'a';
        if (q[s1] != -1 && (q[s1] < a1 || q[s1] > b1))
            return false;
        if (a1 == b1)
        {
            if (q[s1] == -1)
            {
                if (used[a1])
                    return false;
                q[s1] = a1;
                used[a1] = true;
            }
            continue;
        }
        if (q[s1] == a1)
            return check(i + 1, s, a, 0);
        if (q[s1] == b1)
            return check(i + 1, s, b, 1);
        if (q[s1] != -1)
            return true;
        if (b1 - a1 >= 2)
        {
            for (int u = a1 + 1; u <= b1 - 1; u++)
            {
                if (!used[u])
                {
                    q[s1] = u;
                    used[u] = true;
                    return true;
                }
            }
        }
        if (!used[a1])
        {
            q[s1] = a1;
            used[a1] = true;
            if (check(i + 1, s, a, 0))
                return true;
            q[s1] = -1;
            used[a1] = false;
        }
        if (!used[b1])
        {
            q[s1] = b1;
            used[b1] = true;
            if (check(i + 1, s, b, 1))
                return true;
            q[s1] = -1;
            used[b1] = false;
        }
        return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int e = 0;
        if (solve())
        {
            cout << "YES\n";
            for (int i = 0; i < k; i++)
            {
                if (q[i] != -1)
                    used[q[i]] = true;
            }
            for (int i = 0; i < k; i++)
            {
                if (q[i] != -1)
                    cout << char('a' + q[i]);
                else
                {
                    while (used[e])
                        e++;
                    cout << char('a' + e);
                    e++;
                }
            }
            cout << "\n";
        }
        else
            cout << "NO\n";
    }
}