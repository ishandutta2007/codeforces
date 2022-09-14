#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3000000;


vector<int> prefix_function (string s) {
    int n = (int) s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> z_function (string s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<int> p = prefix_function (s);
    int a[MAXN];
    vector<int> z = z_function (s);
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        int t = i + 1 - p[i];
        if (r > i)
            a[i] = 1;
        if ((i + 1) % (t * k) == 0)
        {
            a[i] = 1;
            int w = (i + 1) / k;
            r = max(r, min(i + 1 + w, i + 1 + z[i + 1]));
        }

    }


    for (int i = 0; i < n; i++)
        cout << a[i];
    return 0;
}