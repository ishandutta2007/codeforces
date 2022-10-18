#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string st = s;
    reverse(st.begin(), st.end());
    st = s + '#' + st;
    int l = 0, r = 0;
    int n = st.size();
    int z[n];
    memset(z, 0, sizeof(z));
    for(int i = 1; i < n; i++)
    {
        if(i < r) z[i] = min(z[i - l], r - i);
        while(i + z[i] < n && st[z[i]] == st[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    int ans[n];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < s.size(); i++)
        if(z[n - i - 1] == i + 1)
            ans[i] = 1 + (i ? ans[(i + 1) / 2 - 1] : 0);
    cout << accumulate(ans, ans + n, 0);
    return 0;
}