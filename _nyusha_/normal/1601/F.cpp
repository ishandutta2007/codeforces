#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1000005;
int mod = 998244353, modd = 1e9 + 7;
int st[15];
string good[maxn];
int N, number;
vector < string > lenn[7];
vector < int > ok[7][7];
int sum[7][7];
int inf = 1000000000000000000;

inline int goal(string s) {
    int answ = 0;
    for (auto c : s) answ = answ * 10 + c - '0';
    return answ;
}

inline __int128 get(string cur, int max_len) {
    if (max_len == -1) return 0;
    int L = max_len / 2, R = max_len - L;
    if (max_len == 1) L = 1, R = 0;
    __int128 ans = (number - goal(cur) + mod * mod) % mod;
    number++;
    //cout << cur << " " << max_len << endl;
    for (auto lef : lenn[L]) {
        ans += (-goal(cur + lef) + number + mod * mod) % mod;
        number++;
        if ((int)lef.size() == L) {
            int c = goal(cur + lef) % mod;
            for (int oth = 1; oth <= R; ++oth) {
                int cnst = (-c * st[oth] + number + mod * mod) % mod;
                int to = lower_bound(ok[R][oth].begin(), ok[R][oth].end(), mod - cnst) - ok[R][oth].begin();
                ans += (int)ok[R][oth].size() * cnst + sum[R][oth] - mod * ((int)ok[R][oth].size() - to);
            }
            number += (int)lenn[R].size();
        }
    }
    return ans;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    N = to_string(n).size();
    st[0] = 1;
    for (int i = 1; i <= 14; ++i) st[i] = st[i - 1] * 10;
    string s = to_string(n);
    string cur = "";
    for (int i = 0; i < maxn; ++i) {
        good[i] = to_string(i);
        string now = good[i];
        while ((int)now.size() <= 6) {
            lenn[(int)now.size()].push_back(now);
            now = "0" + now;
        }
    }
    for (int i = 1; i <= 6; ++i) {
        for (auto key : lenn[i - 1]) lenn[i].push_back(key);
        sort(lenn[i].begin(), lenn[i].end());
        for (int j = 0; j < (int)lenn[i].size(); ++j) {
            ok[i][lenn[i][j].size()].push_back((j - stoi(lenn[i][j]) + mod) % mod);
        }
        for (int j = 1; j <= i; ++j) {
            sort(ok[i][j].begin(), ok[i][j].end());
            for (auto key : ok[i][j]) sum[i][j] += key;
        }
    }
    vector < pair < string, int > > Q;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == s[i] - '0') continue;
            if (i == 0 && j == 0) continue;
            cur += char('0' + j);
            if (j <= s[i] - '0') {
                Q.push_back({cur, (int)s.size() - i - 1});
            } else {
                Q.push_back({cur, (int)s.size() - i - 2});
            }
            cur.pop_back();
        }
        cur += s[i];
        Q.push_back({cur, 0});
    }
    number = 1;
    __int128 ans = 0;
    sort(Q.begin(), Q.end());
    for (auto key : Q) {
        if (s[(int)key.first.size() - 1] == key.first.back()) {
            ans += (-goal(key.first) + number + mod * mod) % mod;
            number += 1;
            continue;
        }
        ans += get(key.first, key.second);
    }
    ans %= modd;
    cout << (long long)ans;
    return 0;
}