#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int base = 4, mod1 = 1000000007, mod2 = 1000000011;
pair<int, int> st[600001];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    st[0].f = st[0].s = 1;
    for (int i = 0; i < 600000; ++i)
        st[i+1].f = (st[i].f*base)%mod1, st[i+1].s = (st[i].s*base)%mod2;
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        string s2;
        cin >> s2;
        pair<int, int> h = {0, 0};
        for (int j = 0; j < s2.size(); ++j)
            h.f = (h.f*base+s2[j]-'a'+1)%mod1, h.s = (h.s*base+s2[j]-'a'+1)%mod2;
        s.insert(h);
    }
    while (m--) {
        string s2;
        cin >> s2;
        pair<int, int> h = {0, 0};
        for (int j = 0; j < s2.size(); ++j)
            h.f = (h.f*base+s2[j]-'a'+1)%mod1, h.s = (h.s*base+s2[j]-'a'+1)%mod2;
        bool ans = 0;
        for (int i = 0; i < s2.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                if (s2[i]-'a' == j)
                    continue;
                pair<int, int> h2;
                h2.f = h.f-(s2[i]-'a'+1)*st[s2.size()-i-1].f+(j+1)*st[s2.size()-i-1].f;
                h2.f = (h2.f%mod1+mod1)%mod1;
                h2.s = h.s-(s2[i]-'a'+1)*st[s2.size()-i-1].s+(j+1)*st[s2.size()-i-1].s;
                h2.s = (h2.s%mod2+mod2)%mod2;
                if (s.count(h2))
                    ans = 1;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}