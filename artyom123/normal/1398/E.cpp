#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<pii> s1, s2;
    ll ans = 0;
    int cntl = 0, cntb = 0;
    while (n--) {
        int tp, d;
        cin >> tp >> d;
        if (tp == 0) {
            if (d > 0) {
                s1.insert({d, 1});
                ans += d;
            } else {
                d = -d;
                if (s1.find({d, 1}) != s1.end()) {
                    s1.erase({d, 1});
                    ans -= d;
                } else {
                    s2.erase({d, 1});
                    ans -= 2 * d;
                    cntb--;
                }
            }
        } else {
            if (d > 0) {
                cntl++;
                s1.insert({d, 0});
                ans += d;
            } else {
                d = -d;
                cntl--;
                if (s1.find({d, 0}) != s1.end()) {
                    s1.erase({d, 0});
                    ans -= d;
                } else {
                    s2.erase({d, 0});
                    ans -= 2 * d;
                }
            }
        }
        while ((int)s2.size() > cntl) {
            ans -= s2.begin()->fi;
            cntb -= s2.begin()->se;
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        while ((int)s2.size() < cntl) {
            ans += s1.rbegin()->fi;
            cntb += s1.rbegin()->se;
            s2.insert(*s1.rbegin());
            s1.erase(*s1.rbegin());
        }
        while (s1.size() && s2.size() && *s1.rbegin() > *s2.begin()) {
            auto tmp1 = *s1.rbegin(), tmp2 = *s2.begin();
            s1.erase(tmp1); s2.erase(tmp2);
            s2.insert(tmp1);
            s1.insert(tmp2);
            cntb -= tmp2.se; cntb += tmp1.se;
            ans -= tmp2.fi; ans += tmp1.fi;
        }
        //cout << cntl << " " << cntb << " " << s1.size() << " " << s2.size() << " " << ans << "\n";
        ll now = ans;
        if (cntb == 0) {
            if (cntl) now -= s2.begin()->fi;
            if (s1.size() && cntl) now += s1.rbegin()->fi;
        }
        cout << now << "\n";
    }
    return 0;
}