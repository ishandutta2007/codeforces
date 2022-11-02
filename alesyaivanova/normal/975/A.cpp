#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool v[26];
    vector<int> d(n, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < 26; e++)
            v[e] = false;
        for (int e = 0; e < (int) s.length(); e++)
            v[s[e] - 'a'] = true;
        for (int e = 0; e < 26; e++)
        {
            d[i] *= 2;
            if (v[e])
                d[i]++;
        }
    }
    sort(d.begin(), d.end());
    auto last = unique(d.begin(), d.end());
    int ans = last - d.begin();
    cout << ans;
}