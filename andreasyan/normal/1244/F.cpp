#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
char a[N];
bool c[N];

void solv(vector<int> v)
{
    if (v.size() % 2 == 1)
    {
        char g;
        if (v[0])
            g = a[v[0] - 1];
        else
            g = a[n - 1];
        if (k >= v.size() / 2 + 1)
        {
            for (int i = 0; i < v.size(); ++i)
                a[v[i]] = g;
            return;
        }
        for (int i = 0; i < k; ++i)
            a[v[i]] = g;
        for (int i = v.size() - 1; i >= v.size() - k; --i)
            a[v[i]] = g;
        if (k % 2 == 1)
        {
            for (int i = k; i < v.size() - k; ++i)
            {
                if (a[v[i]] == 'B')
                    a[v[i]] = 'W';
                else
                    a[v[i]] = 'B';
            }
        }
    }
    else
    {
        char g1, g2;
        if (v[0] == 0)
            g1 = a[n - 1];
        else
            g1 = a[v[0] - 1];
        if (v.back() == n - 1)
            g2 = a[0];
        else
            g2 = a[v.back() + 1];
        if (k >= v.size() / 2)
        {
            for (int i = 0; i < v.size() / 2; ++i)
                a[v[i]] = g1;
            for (int i = v.size() - 1; i >= v.size() / 2; --i)
                a[v[i]] = g2;
            return;
        }
        for (int i = 0; i < k; ++i)
            a[v[i]] = g1;
        for (int i = v.size() - 1; i >= v.size() - k; --i)
            a[v[i]] = g2;
        if (k % 2 == 1)
        {
            for (int i = k; i < v.size() - k; ++i)
            {
                if (a[v[i]] == 'B')
                    a[v[i]] = 'W';
                else
                    a[v[i]] = 'B';
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);
    for (int i = 0; i < n; ++i)
    {
        if ((i == 0 && a[n - 1] == a[i]) || (i != 0 && a[i - 1] == a[i]))
            c[i] = true;
        if ((i == n - 1 && a[0] == a[i]) || (i != n - 1 && a[i + 1] == a[i]))
            c[i] = true;
    }
    bool zz = false;
    for (int i = 0; i < n; ++i)
    {
        if (c[i])
        {
            zz = true;
            break;
        }
    }
    if (!zz)
    {
        if (k % 2 == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (a[i] == 'B')
                    a[i] = 'W';
                else
                    a[i] = 'B';
            }
        }
        cout << a << endl;
        return 0;
    }
    bool z = false;
    for (int i = 0; i < n; ++i)
    {
        if (c[i])
            z = true;
        if (!c[i])
        {
            if (!z)
                continue;
            vector<int> v;
            int j;
            for (j = i; j < n; ++j)
            {
                if (c[j])
                    break;
                v.push_back(j);
            }
            if (j == n)
            {
                for (j = 0; j < n; ++j)
                {
                    if (c[j])
                        break;
                    v.push_back(j);
                }
                solv(v);
                break;
            }
            solv(v);
            i = j - 1;
        }
    }
    if (!c[0] && c[n - 1])
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            if (c[i])
                break;
            v.push_back(i);
        }
        solv(v);
    }
    cout << a << endl;
    return 0;
}