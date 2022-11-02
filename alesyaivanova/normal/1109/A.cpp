#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 300009;
int a[MAX_N];
pair<int, int> s[MAX_N];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            s[i].first = s[i - 1].first;
        s[i].first ^= a[i];
        s[i].second = i % 2;
        //cout << s[i].first << " " << s[i].second << "\n";
    }
    s[n].first = 0;
    s[n].second = 1;
    n++;
    sort(s, s + n);
    int ans = 0;
    int pr = -1;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && s[i] == s[i + 1])
            continue;
        int k = i - pr;
        ans += k * (k - 1) / 2;
        pr = i;
    }
    cout << ans;
}