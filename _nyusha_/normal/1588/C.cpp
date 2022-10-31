#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 3e5 + 5;
int a[maxn];
int r[maxn];
int pref[maxn];
int imin[3][(1 << 20)];
int inf = 1e18;
map < int, vector < int > > all_pos[2];

inline int add(int t, int l, int r, int val) {
    auto L = lower_bound(all_pos[t][val].begin(), all_pos[t][val].end(), l) - all_pos[t][val].begin();
    auto R = upper_bound(all_pos[t][val].begin(), all_pos[t][val].end(), r) - all_pos[t][val].begin();
    return R - L;
}

void build(int t, int i, int l, int r) {
    if (r - l == 1) {
        imin[t][i] = a[2 * (l - 1) + t] - pref[2 * (l - 1) + t - 1];
    } else {
        int m = (r + l) / 2;
        build(t, 2 * i + 1, l, m);
        build(t, 2 * i + 2, m, r);
        imin[t][i] = min(imin[t][2 * i + 1], imin[t][2 * i + 2]);
    }
}

int get(int t, int i, int l, int r, int lq, int rq, int x) {
    if (imin[t][i] >= x) return inf;
    if (lq >= r || l >= rq) return inf;
    if (r - l == 1) return t + 2 * (l - 1);
    int m = (r + l) / 2;
    int ans1 = get(t, 2 * i + 1, l, m, lq, rq, x);
    if (ans1 != inf) return ans1;
    return get(t, 2 * i + 2, m, r, lq, rq, x);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n == 1) {
            if (a[1] == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }
        all_pos[0].clear();
        all_pos[1].clear();
        for (int i = 1; i <= n; ++i) {
            pref[i] = a[i] - pref[i - 1];
            all_pos[i % 2][a[i] - pref[i - 1]].push_back(i);
        }
        int answer = 0;
        build(2, 0, 1, n / 2 + 1);
        build(1, 0, 1, (n + 1) / 2 + 1);
        for (int i = 1; i <= n; ++i) {
            r[i] = n;
            /*for (int R = i; R <= n; R += 2) {
                if (a[R] - pref[R - 1] < -pref[i - 1]) {
                    r[i] = min(r[i], R - 1);
                    break;
                }
            }
            for (int R = i + 1; R <= n; R += 2) {
                if (a[R] - pref[R - 1] < pref[i - 1]) {
                    r[i] = min(r[i], R - 1);
                    break;
                }
            }*/
            if (i % 2 == 0) {
                r[i] = min({r[i], get(2, 0, 1, n / 2 + 1, i / 2, n / 2 + 1, -pref[i - 1]), get(1, 0, 1, (n + 1) / 2 + 1, (i + 1) / 2, (n + 1) / 2 + 1, pref[i - 1])});
                answer += add(0, i, r[i], -pref[i - 1]);
                answer += add(1, i, r[i], pref[i - 1]);
            } else {
                r[i] = min({r[i], get(2, 0, 1, n / 2 + 1, (i + 1) / 2, n / 2 + 1, pref[i - 1]), get(1, 0, 1, (n + 1) / 2 + 1, (i + 1) / 2, (n + 1) / 2 + 1, -pref[i - 1])});
                answer += add(0, i, r[i], pref[i - 1]);
                answer += add(1, i, r[i], -pref[i - 1]);
            }
            /*for (int R = i; R <= r[i]; R += 2) {
                if (a[R] - pref[R - 1] == -pref[i - 1]) answer++;
            }
            for (int R = i + 1; R <= r[i]; R += 2) {
                if (a[R] - pref[R - 1] == pref[i - 1]) answer++;
            }*/
        }
        cout << answer << '\n';
    }
    return 0;
}