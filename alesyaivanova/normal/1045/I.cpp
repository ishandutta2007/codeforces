#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100010;
int a[MAX_N];
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0;
    unordered_map<int, int> st;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < (int)s.length(); e++)
        {
            int u = (1 << (s[e] - 'a'));
            a[i] ^= u;
        }
        if (st.find(a[i]) != st.end())
            ans += st[a[i]];
        for (int e = 0; e < 26; e++)
        {
            int b = (a[i] ^ (1 << e));
            if (st.find(b) != st.end())
                ans += st[b];
        }
        st[a[i]]++;
    }
    cout << ans;
}