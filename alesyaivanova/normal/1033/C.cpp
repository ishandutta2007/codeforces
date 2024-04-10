#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100009;
int a[MAX_N];
vector<int> g[MAX_N];
bool used[MAX_N];
bool t[MAX_N];

void dfs(int v)
{
    used[v] = true;
    for (int to : g[v])
    {
        if (!used[to])
            dfs(to);
        if (!t[to])
            t[v] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int e = i + a[i]; e < n; e += a[i])
        {
            if (a[e] > a[i])
                g[i].push_back(e);
        }
        for (int e = i - a[i]; e >= 0; e -= a[i])
        {
            if (a[e] > a[i])
                g[i].push_back(e);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            dfs(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i])
            cout << "A";
        else
            cout << "B";
    }
}