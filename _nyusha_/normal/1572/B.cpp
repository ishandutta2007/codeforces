#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
vector < int > ans;

void dfs(int l, int ok, int r) {
    if (l > r) return;
    //cout << l << " " << ok << " " << r << endl;
    assert(a[ok] == 0);
    if (l == r) return;
    if (ok != l && ok != r && a[ok - 1] == a[ok + 1]) {
        if (a[ok - 1] == 0) {
            dfs(l, ok - 1, ok - 1);
            dfs(ok + 1, ok + 1, r);
        }
        else {
            ans.push_back(ok - 1);
            a[ok - 1] = 0, a[ok + 1] = 0;
            dfs(l, ok - 1, ok - 1);
            dfs(ok + 1, ok + 1, r);
        }
        return;
    }
    if (ok == l) {
        if (a[ok + 1] == 0) dfs(l + 1, l + 1, r);
        else {
            if (a[ok + 1] == a[ok + 2]) {
                ans.push_back(ok);
                a[ok + 1] = 0, a[ok + 2] = 0;
                dfs(l + 2, l + 2, r);
            }
            else {
                dfs(l + 1, l + 2, r);
            }
        }
    }
    else if (ok == r) {
        if (a[ok - 1] == 0) dfs(l, r - 1, r - 1);
        else {
            if (a[ok - 1] == a[ok - 2]) {
                ans.push_back(ok - 2);
                a[ok - 2] = 0, a[ok - 1] = 0;
                dfs(l, r - 2, r - 2);
            }
            else {
                dfs(l, r - 2, r - 1);
            }
        }
    }
    else {
        if (a[ok - 1] == 0) dfs(l, ok - 1, ok - 1), dfs(ok, ok, r);
        else if (a[ok + 1] == 0) dfs(ok + 1, ok + 1, r), dfs(l, ok, ok);
        else {
            dfs(l, ok, ok);
            dfs(ok, ok, r);
        }
    }
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
        ans = {};
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2 == 1 || sum == n) {
            cout << "NO" << '\n';
            continue;
        }
        ans = {};
        for (int i = 1; i < n - 1;) {
            int v1 = a[i], v2 = a[i + 1], v3 = a[i + 2];
            if (v1 == v2) {
                i += 2;
            }
            else {
                if ((v1^v2^v3) == 0) i += 3;
                else {
                    if (a[i] == 0) i++;
                    else {
                        ans.push_back(i);
                        a[i] = 1;
                        a[i + 1] = 1;
                        a[i + 2] = 1;
                        i += 2;
                    }
                }
            }
        }
        int good = -1;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) good = i;
            sum += a[i];
            a[i] = (sum * a[i] + 1) / 2;
            //cout << a[i] << " ";
        }
        if (good == -1) {
            cout << "NO" << '\n';
            continue;
        }
        dfs(1, good, n);
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for (auto key : ans) cout << key << " ";
        cout << '\n';
    }
    return 0;
}