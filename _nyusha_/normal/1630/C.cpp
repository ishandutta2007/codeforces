#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
int r[maxn], lst[maxn], open[maxn], close[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        if (lst[a[i]] == 0) {
            lst[a[i]] = i;
            r[i] = i;
        }
        else r[i] = lst[a[i]];
    }
    vector < pair < int, int > > Q;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (r[i] > mx) {
            Q.push_back({i, 0});
            Q.push_back({r[i], 1});
            mx = r[i];
        }
    }
    sort(Q.begin(), Q.end());
    int ans = 0, bal = 0, lst = 1, cnt = 0, t = 0, need = 0;
    vector < int > R;
    for (auto key : Q) {
        if (bal) ans += max((key.first - lst - 1), 0);
        if (key.second == 0) {
            bal++;
            if (bal == 1) cnt = 0, need = r[key.first];
            t++;
            cnt++;
            R.push_back(r[key.first]);
        }
        else {
            bal--;
            if (key.first == need) {
                ans += max(0, cnt - 2);
                need = R.back();
                cnt = 1;
            }
        }
        if (bal == 0) {
            ans += max(0, t - 1);
            t = 0;
        }
        lst = key.first;
    }
    cout << ans << '\n';
    return 0;
}