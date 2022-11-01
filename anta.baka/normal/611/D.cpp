#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int mod = 1e9 + 7;

struct num {
    static const int MA = 1e9 + 7, MB = 1e9 + 9;
    int a, b;
    num() {}
    num(int x) : a(x), b(x) {}
    num(int a, int b) : a(a), b(b) {}
    bool operator == (const num &he) const {
        return a == he.a && b == he.b;
    }
    num operator + (const num &he) const {
        return num((a + he.a) % MA, (b + he.b) %  MB);
    }
    num operator - (const num &he) const {
        return num((a - he.a + MA) % MA, (b - he.b + MB) %  MB);
    }
    num operator * (const num &he) const {
        return num(ll(a) * he.a % MA, ll(b) * he.b % MB);
    }
};

num P = max(239, rand());
vector<num> h, p;

inline num get(int l, int r) {
    return h[r + 1] - h[l] * p[r - l + 1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; string s; cin >> n >> s;
    srand(322);
    h.resize(n + 1);
    p.resize(n + 1);
    h[0] = 0;
    p[0] = 1;
    for(int i = 0; i < n; i++) {
        h[i + 1] = h[i] * P + s[i];
        p[i + 1] = p[i] * P;
    }
    vector<int> pos(n, -1);
    for(int i = n - 1; i >= 0; i--)
        if(s[i] != '0') pos[i] = i;
        else if(i != n - 1) pos[i] = pos[i + 1];
    vector<vector<int>> dp(n, vector<int>(n, 0)), sum(n, vector<int>(n, 0));
    for(int r = 0; r < n; r++) {
        dp[0][r] = 1;
        for(int l = 1; l <= r; l++) {
            if(s[l] == '0') continue;
            int len = r - l + 1;
            int k = max(0, l - len);
            k = pos[k];
            if(k > l - 1) continue;
            if(l - k == len) {
                if(get(k, l - 1) == get(l, r)) {
                    k++;
                } else {
                    int lf = 0, rg = len - 1;
                    while(lf < rg) {
                        int md = (lf + rg + 1) >> 1;
                        if(get(k, k + md - 1) == get(l, l + md - 1)) lf = md;
                        else rg = md - 1;
                    }
                    if(s[k + lf] > s[l + lf]) k++;
                }
            }
            k = pos[k];

//            if(k <= l - 1) {
//                for(int z = k; z < l; z++) cout << s[z];
//                cout << ' ';
//                for(int z = l; z <= r; z++) cout << s[z];
//                cout << endl;
//            }

            if(k <= l - 1) dp[l][r] = (sum[l - 1][l - 1] - (k ? sum[k - 1][l - 1] : 0) + mod) % mod;
        }
        for(int l = 0; l <= r; l++)
            sum[l][r] = ((l ? sum[l - 1][r] : 0) + dp[l][r]) % mod;
    }

//    for(int r = 0; r < n; r++)
//        for(int l = 0; l <= r; l++)
//            cout << l << ' ' << r << ' ' << dp[l][r] << endl;

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + dp[i][n - 1]) % mod;
    cout << ans;
}