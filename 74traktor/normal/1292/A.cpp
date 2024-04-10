#include<bits/stdc++.h>

using namespace std;

int ok[100005][2];
int cnt[100005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, r, c, go = 0;
    cin >> n >> q;
    multiset < int > Q;
    for (int i = 1; i <= n; ++i) Q.insert(0);
    for (int i = 1; i <= q; ++i) {
        cin >> r >> c;
        if (ok[c][r] == 0) {
            ok[c][r] = 1;
            Q.erase(Q.find(cnt[c]));
            cnt[c]++;
            Q.insert(cnt[c]);
            if (r == 1) {
                if (ok[c - 1][2]) go++;
                if (ok[c + 1][2]) go++;
            }
            else {
                if (ok[c + 1][1]) go++;
                if (ok[c - 1][1]) go++;
            }
        }
        else {
            ok[c][r] = 0;
            Q.erase(Q.find(cnt[c]));
            cnt[c]--;
            Q.insert(cnt[c]);
            if (r == 1) {
                if (ok[c - 1][2]) go--;
                if (ok[c + 1][2]) go--;
            }
            else {
                if (ok[c - 1][1]) go--;
                if (ok[c + 1][1]) go--;
            }
        }
        if ((*Q.rbegin()) == 2) {
            cout << "No" << '\n';
            continue;
        }
        if (go > 0) {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
    }
    return 0;
}