 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int s, n;
        cin >> s >> n;
        vector<int> a;
        vector<int> ans;
        int p = 1;
        int s1 = s;
        while (s1) {
            int r = s1 % 10;
            while (r) {
                a.pb(p);
                r--;
            }
            p *= 10;
            s1 /= 10;
        }
        int sz = a.size();
        if (sz >= n) {
            int x = 0;
            for (int i = 0; i < sz - (n - 1); i++) {
                x += a[i];
            }
            ans.pb(x);
            for (int i = sz - (n - 1); i < sz; i++) {
                ans.pb(a[i]);
            }
        } else {
            multiset<int> s;
            for (auto &c : a) s.insert(c);
            while ((int)s.size() + (int)ans.size() < n) {
                while (*s.begin() == 1) {
                    ans.pb(*s.begin());
                    s.erase(s.begin());
                }
                int x = *s.begin();
                int p = 1;
                while (p < x) p *= 10;
                int cnt = min(9, n - (int)s.size() - (int)ans.size());
                s.erase(s.begin());
                if (cnt == 9) {
                    for (int i = 0; i < 10; i++) s.insert(p / 10);
                } else {
                    int s1 = 0;
                    for (int i = 0; i < cnt; i++) {
                        s1 += p / 10;
                        s.insert(p / 10);
                    }
                    s.insert(p - s1);
                    break;
                }
            }
            for (auto &c : s) ans.pb(c);
        }
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}