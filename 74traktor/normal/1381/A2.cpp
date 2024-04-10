#include<bits/stdc++.h>

using namespace std;

#define int long long
string SS;
vector < int > ans;
int cur, S;

inline char get(int pos) {
    /*int cur = 0;
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        if (ans[i] == 1) continue;
        pos = ans[i] - pos - 1;
        cur++;
    }*/
    if (cur % 2 == 1) {
        pos = S - pos - 1;
    }
    else {
        pos = pos + S;
    }
    if (cur % 2 == 0) return SS[pos];
    if (SS[pos] == '0') return '1';
    return '0';
}

inline void f(string &s, int x) {
    for (int i = 0; i < x; ++i) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    for (int i = 0; i < x / 2; ++i) swap(s[i], s[x - i - 1]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> n;
        cin >> a >> b;
        SS = a;
        ans = {};
        cur = 0;
        S = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (get(i) == b[i]) continue;
            if (get(0) != b[i]) {
                if (cur % 2 == 0) S += (i + 1);
                else S -= (i + 1);
                ans.push_back(i + 1);
                cur++;
                //f(a, i + 1);
            }
            else {
                if (cur % 2 == 0) S += (i + 1);
                else S -= (i + 1);
                ans.push_back(1);
                //f(a, 1);
                ans.push_back(i + 1);
                //f(a, i + 1);
                cur++;
            }
        }
        cout << ans.size() << " ";
        for (auto key : ans) cout << key << " ";
        cout << '\n';
    }
    return 0;
}