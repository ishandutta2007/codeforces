#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ans = 0;
int const maxn = 2e5 + 5;
int nxt[maxn][26], cur = 1;
int L[maxn], R[maxn];
int sz[maxn];
ll mod[2], p[2][maxn], P[2];
map < pair < ll, ll >, vector < int > > cnt[maxn];
ll suff[2][maxn];
int Nxt[maxn], inf = 1e9 + 7;

int get_val(int N, pair < ll, ll > h, int l, int r) {
    if (cnt[N].find(h) == cnt[N].end()) return 0;
    return upper_bound(cnt[N][h].begin(), cnt[N][h].end(), r) - lower_bound(cnt[N][h].begin(), cnt[N][h].end(), l);
}

ll solve_in(vector < string > a) {
    ll good = 0;
    int numb = 0;
    for (auto key : a) {
        int node = 0;
        numb++;
        Nxt[(int)key.size() - 1] = (int)key.size();
        suff[0][(int)key.size()] = 0;
        suff[0][(int)key.size() - 1] = key.back() - 'a' + 1;
        suff[1][(int)key.size()] = 0;
        suff[1][(int)key.size() - 1] = key.back() - 'a' + 1;
        for (int i = (int)key.size() - 2; i >= 0; --i) {
            for (int j = 0; j < 2; ++j) {
                suff[j][i] = (suff[j][i + 1] + (key[i] - 'a' + 1) * p[j][(int)key.size() - i - 1]) % mod[j];
            }
            if (key[i] <= key[i + 1]) Nxt[i] = Nxt[i + 1];
            else Nxt[i] = i + 1;
        }
        for (int i = (int)key.size() - 1; i >= 0; --i) {
            cnt[(int)key.size() - i][{suff[0][i], suff[1][i]}].push_back(numb);
        }
        int len = 0;
        for (auto c : key) {
            int lef = inf, righ = -inf;
            for (int j = 0; j < c - 'a'; ++j) {
                if (nxt[node][j] != 0) {
                    lef = min(lef, L[nxt[node][j]]);
                    righ = max(righ, R[nxt[node][j]]);
                }
            }
            if (lef != inf) {
                if (Nxt[len] == (int)key.size()) good += (righ - lef + 1);
                else {
                    int N = (int)key.size() - Nxt[len];
                    good += get_val(N, {suff[0][Nxt[len]], suff[1][Nxt[len]]}, lef, righ);
                }
            }
            sz[node]++;
            len++;
            if (nxt[node][c - 'a'] == 0) {
                nxt[node][c - 'a'] = cur++;
            }
            node = nxt[node][c - 'a'];
            if (L[node] == 0) L[node] = numb, R[node] = numb;
            L[node] = min(L[node], numb);
            R[node] = max(R[node], numb);
        }
        sz[node]++;
    }
    for (int i = 0; i <= (int)a[0].size(); ++i) cnt[i] = {};
    for (int i = 0; i < cur; ++i) {
        sz[i] = 0;
        L[i] = 0, R[i] = 0;
        for (int j = 0; j < 26; ++j) nxt[i][j] = 0;
    }
    cur = 1;
    return good;
}

ll solve_out(vector < string > a) {
    ll good = 0;
    int numb = 0;
    for (auto key : a) {
        int node = 0;
        numb++;
        Nxt[(int)key.size() - 1] = (int)key.size();
        suff[0][(int)key.size()] = 0;
        suff[0][(int)key.size() - 1] = key.back() - 'a' + 1;
        suff[1][(int)key.size()] = 0;
        suff[1][(int)key.size() - 1] = key.back() - 'a' + 1;
        for (int i = (int)key.size() - 2; i >= 0; --i) {
            for (int j = 0; j < 2; ++j) {
                suff[j][i] = (suff[j][i + 1] + (key[i] - 'a' + 1) * p[j][(int)key.size() - i - 1]) % mod[j];
            }
            if (key[i] <= key[i + 1]) Nxt[i] = Nxt[i + 1];
            else Nxt[i] = i + 1;
        }
        for (int i = (int)key.size() - 1; i >= 0; --i) {
            cnt[(int)key.size() - i][{suff[0][i], suff[1][i]}].push_back(numb);
        }
        int len = 0;
        for (auto c : key) {
            int lef = inf, righ = -inf;
            for (int j = 25; j > c - 'a'; --j) {
                if (nxt[node][j] != 0) {
                    lef = min(lef, L[nxt[node][j]]);
                    righ = max(righ, R[nxt[node][j]]);
                }
            }
            if (lef != inf) {
                if (Nxt[len] == (int)key.size()) good += (righ - lef + 1);
                else {
                    int N = (int)key.size() - Nxt[len];
                    good += get_val(N, {suff[0][Nxt[len]], suff[1][Nxt[len]]}, lef, righ);
                }
            }
            sz[node]++;
            len++;
            if (nxt[node][c - 'a'] == 0) {
                nxt[node][c - 'a'] = cur++;
            }
            node = nxt[node][c - 'a'];
            if (L[node] == 0) L[node] = numb, R[node] = numb;
            L[node] = min(L[node], numb);
            R[node] = max(R[node], numb);
        }
        sz[node]++;
    }
    for (int i = 0; i <= (int)a[0].size(); ++i) cnt[i] = {};
    for (int i = 0; i < cur; ++i) {
        sz[i] = 0;
        L[i] = 0, R[i] = 0;
        for (int j = 0; j < 26; ++j) nxt[i][j] = 0;
    }
    cur = 1;
    return good;
}

void solve(vector < string > oki) {
    sort(oki.begin(), oki.end());
    ll cnt1 = 0;
    ll cnt2 = 0;
    cnt1 += solve_in(oki);
    reverse(oki.begin(), oki.end());
    cnt1 += solve_out(oki);
    cnt2 = ((ll)oki.size() * (ll)(oki.size() - 1)) / 2 - cnt1;
    ans += cnt1 + cnt2 * 2;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    P[0] = 29, P[1] = 31;
    mod[0] = 1e9 + 7, mod[1] = 1e9 + 9;
    p[0][0] = 1, p[1][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[0][i] = p[0][i - 1] * P[0] % mod[0];
        p[1][i] = p[1][i - 1] * P[1] % mod[1];
    }
    int n;
    cin >> n;
    ll max_ans = 1337;
    vector < pair < string, string > > a;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        a.push_back({t, s});
    }
    sort(a.begin(), a.end());
    ll add = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        int j = i;
        while (j < (int)a.size() && a[j].first == a[i].first) {
            j++;
        }
        vector < string > top;
        for (int pos = i; pos < j; ++pos) top.push_back(a[pos].second);
        add += ((ll)(n - (j - i)) * (ll)(j - i) * max_ans);
        solve(top);
        i = j - 1;
    }
    cout << ans + add / 2 << '\n';
    return 0;
}