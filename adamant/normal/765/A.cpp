#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string home;
    cin >> home;
    int cnt[2] = {0};
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        string a = t.substr(0, 3);
        string b = t.substr(5, 3);
        cnt[0] += a == home;
        cnt[1] += b == home;
    }
    cout << (cnt[0] > cnt[1] ? "contest" : "home") << endl;
}