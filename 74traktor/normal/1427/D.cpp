#include<bits/stdc++.h>

using namespace std;

int a[53];
int b[53];
int n;

void dodo(vector < int > t) {
    int r = n, l = 1;
    for (int i = 0; i < (int)t.size(); ++i) {
        for (int j = l; j < l + t[i]; ++j) {
            b[r - t[i] + 1 + (j - l)] = a[j];
        }
        r -= t[i];
        l += t[i];
    }
    assert(r == 0);
    for (int i = 1; i <= n; ++i) a[i] = b[i];
}

void print() {
    return;
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector < vector < int > > ans;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (1) {
        int ok = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != i) ok = 0;
        }
        if (ok) break;
        int pref = 0;
        while (a[pref + 1] == pref + 1) pref++;
        int pos;
        for (int i = 1; i <= n; ++i) if (a[i] == pref + 1) pos = i;
        ans.emplace_back();
        if (pref != 0) ans.back().push_back(pref);
        assert(pos != pref);
        ans.back().push_back(pos - pref);
        if (pos != n) ans.back().push_back(n - pos);
        dodo(ans.back());
        print();
        pos = -1;
        for (int i = 1; i <= n; ++i) if (a[i] == pref + 2) pos = i;
        assert(pos != -1);
        ans.emplace_back();
        if (pos != 1) ans.back().push_back(pos - 1);
        ans.back().push_back(n - pref - 1 - (pos - 1));
        ans.back().push_back(1);
        if (pref != 0) ans.back().push_back(pref);
        dodo(ans.back());
        print();
    }
    vector < vector < int > > good_ans;
    for (auto key : ans) if ((int)key.size() > 1) good_ans.push_back(key);
    ans = good_ans;
    cout << ans.size() << '\n';
    for (auto key : ans) {
        cout << key.size() << " ";
        for (auto elem : key) cout << elem << " ";
        cout << '\n';
    }
    return 0;
}