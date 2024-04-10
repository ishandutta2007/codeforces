#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int t, n;
string s;
set<int> od0, ev0, od1, ev1;

bool ok() {
    if (od0.size() && ev0.size()) return false;
    if (od1.size() && ev1.size()) return false;
    if (od0.size() && od1.size()) return false;
    if (ev0.size() && ev1.size()) return false;
    return true;
}

void ins(int idx) {
    if (s[idx] == '0') {
        if (idx % 2) od0.insert(idx);
        else ev0.insert(idx);
    } else if (s[idx] == '1') {
        if (idx % 2) od1.insert(idx);
        else ev1.insert(idx);
    }
}

void rem(int idx) {
    if (s[idx] == '0') {
        if (idx % 2) od0.erase(idx);
        else ev0.erase(idx);
    } else if (s[idx] == '1') {
        if (idx % 2) od1.erase(idx);
        else ev1.erase(idx);
    }
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        od0.clear();
        ev0.clear();
        od1.clear();
        ev1.clear();
        cin >> s;
        n = s.size();
        int r = -1;
        int ans = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n) {
                r++;
                ins(r);
                if (!ok()) {
                    rem(r);
                    r--;
                    break;
                }
            }
           // printf("%d %d\n", l, r);
            ans += r - l + 1;
            rem(l);
        }
        printf("%lld\n", ans);
    }

    return 0;
}