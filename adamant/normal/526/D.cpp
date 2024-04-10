#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int z[n];
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        z[i] = max(0, min(z[i - l], r - i));
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    string ans(n, '0');
    vector<int> L, R;
    for(int i = 1; i < n; i++)
    {
        int AB = i;
        int64_t ABk = 1LL * k * AB;
        if(ABk <= i + z[i])
            L.push_back(ABk - 1),
            R.push_back(min(0LL + i + z[i], ABk + AB) - 1);
    }
    if(k == 1)
    {
        cout << string(n, '1') << "\n";
        return 0;
    }
    int a = 0, b = 0;
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        while(a < L.size() && L[a] <= i)
            c++, a++;
        while(b < R.size() && R[b] < i)
            c--, b++;
        if(c > 0)
            ans[i] = '1';
    }
    cout << ans << "\n";
    return 0;
}