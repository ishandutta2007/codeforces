#include <bits/stdc++.h>

using namespace std;

#define int long long
vector < int > t[16];
int ok[16][16];
int sums[16];
unordered_map < int, pair < int, int > > gett;
pair < int, int > go[16][5005];
pair < int, int > S[17];
int used[17];
int cur, ptr, OK;
vector < pair < int, int > > dp[33000];
int answ[33000];
pair < int, int > out[20];

void get_ans(int mask) {
    if (mask == 0) return;
    if ((int)dp[mask].size() != 0) {
        for (int j = 0; j < (int)dp[mask].size(); ++j) {
            int nxt = j - 1;
            if (j == 0) nxt = (int)dp[mask].size() - 1;
            out[dp[mask][j].first] = {t[dp[mask][j].first][dp[mask][j].second], dp[mask][nxt].first};
        }
        return;
    }
    for (int B = mask; B != 0; B = ((B - 1)&mask)) {
        if (B != mask && (answ[B]&answ[(mask^B)])) {
            get_ans(B);
            get_ans((mask^B));
            break;
        }
    }
}

inline void dfs(int i, int j) {
    cur++;
    ptr = 1;
    OK = 1;
    int i_first = i, j_first = j;
    while (1) {
        used[i] = cur;
        S[ptr++] = {i, j};
        //if (i_first == 1 && j_first == 2) cout << i << " " << j << '\n';
        if (go[i][j].first == 0) {
            OK = 0;
            break;
        }
        if (used[go[i][j].first] == cur) {
            //if (i_first == 1 && j_first == 2) cout << go[i][j].first << " " << go[i][j].second << '\n';
            if (go[i][j].first == i_first && go[i][j].second == j_first) {
                OK = 1;
                //cout << "OK" << '\n';
                return;
            }
            OK = 0;
            break;
        }
        int x = go[i][j].first, y = go[i][j].second;
        i = x, j = y;
    }
    OK = 0;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n, sum = 0, x;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            t[i].push_back(x);
            sum += x;
            sums[i] += x;
        }
    }
    for (int i = 1; i <= k; ++i) sort(t[i].begin(), t[i].end());
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (int)t[i].size(); ++j) gett[t[i][j]] = {i, j};
    }
    if (sum % k != 0) {
        cout << "No";
        return 0;
    }
    int block = sum / k;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (int)t[i].size(); ++j) {
            int f = block - (sums[i] - t[i][j]);
            if (gett.find(f) != gett.end()) {
                go[i][j] = gett[f];
                //cout << i << " " << j << " " << go[i][j].first << " " << go[i][j].second << '\n';
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (int)t[i].size(); ++j) {
            dfs(i, j);
            if (OK) {
                //cout << "OK" << '\n';
                int mask = 0;
                for (int z = 1; z < ptr; ++z) {
                    mask += (1ll << (S[z].first - 1));
                }
                if ((int)dp[mask].size() == 0) {
                    for (int z = 1; z < ptr; ++z) {
                        dp[mask].push_back(S[z]);
                    }
                    answ[mask] = 1;
                    //cout << mask << '\n';
                }
            }
        }
    }
    answ[0] = 1;
    for (int mask = 1; mask < (1 << k); ++mask) {
        for (int B = mask; B != 0; B = ((B - 1)&mask)) {
            if (B == mask) continue;
            answ[mask] = max(answ[mask], (answ[B]&answ[(mask^B)]));
        }
    }
    int mask = (1 << k) - 1;
    if (answ[mask] == 1) {
        cout << "Yes" << '\n';
        get_ans(mask);
        for (int i = 1; i <= k; ++i) {
            cout << out[i].first << " " << out[i].second << '\n';
        }
    }
    else cout << "No" << '\n';
    return 0;
}