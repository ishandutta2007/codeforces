#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;

    int a = 0;
    while (s[a] == t[a])
        a++;
    int b = n - 1;
    while (s[b] == t[b])
        b--;
    int ans = 0;

    string u = "";
    for (int i = 0; i < a; i++)
        u += s[i];
    u += t[a];
    for (int i = a; i < n; i++)
        u += s[i];

    string v = "";
    for (int i = 0; i <= b; i++)
        v += t[i];
    v += s[b];
    for (int i = b + 1; i < n; i++)
        v += t[i];

    if (u == v)
        ans++;

    u = "";
    for (int i = 0; i < a; i++)
        u += t[i];
    u += s[a];
    for (int i = a; i < n; i++)
        u += t[i];

    v = "";
    for (int i = 0; i <= b; i++)
        v += s[i];
    v += t[b];
    for (int i = b + 1; i < n; i++)
        v += s[i];

    if (u == v)
        ans++;

    cout << ans;

    return 0;
}