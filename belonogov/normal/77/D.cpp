#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

    


void add(ll& a, ll b) {
    a = (a + b) % MOD;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m); 
    vector<string> s(n * 4 + 1);
    for (int i = 0; i < n * 4 + 1; i++) {
        cin >> s[i];
    }

    vector<vector<string>> ver = {
    { "...",
      "...",
      "..."},
    { "...",
      ".O.",
      "..."},
    { "..O",
      "...",
      "O.."},
    { "..O",
      ".O.",
      "O.."},
    { "O.O",
      "...",
      "O.O"},
    { "O.O",
      ".O.",
      "O.O"},
    { "O.O",
      "O.O",
      "O.O"}};
    vector<vector<string>> hor = {
    { "...",
      "...",
      "..."},
    { "...",
      ".O.",
      "..."},
    { "O..",
      "...",
      "..O"},
    { "O..",
      ".O.",
      "..O"},
    { "O.O",
      "...",
      "O.O"},
    { "O.O",
      ".O.",
      "O.O"},
    { "OOO",
      "...",
      "OOO"}};
    assert(hor.size() == ver.size() && hor.size() == 7);

    auto check = [&](int i, int j, vector<vector<string>> tmp) {
        //db2(i, j);
        for (int t = 0; t < sz(tmp); t++) {
            bool ok = 1;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    ok &= s[i * 4 + x + 1][j * 4 + 1 + y] == tmp[t][x][y];
                }
            }
            if (ok) {
                return t;
            }
        }
        return -1;
    };

    const int HOR = 1;
    const int VER = 2;

    auto get = [&](int i, int j) {
        //db2(i, j);
        auto res = check(i, j, hor);
        //db(res);
        if (res != -1) {
            if (res != 2 && res != 3 && res != 6) {
                return make_pair(res, 0);
            }
            return make_pair(res, 1);
        }
        res = check(i, j, ver);
        assert(res != -1);
        assert(res == 2 || res == 3 || res == 6);
        return make_pair(res, 2);
    };

    vector<vector<pair<int,int>>> board(n, vector<pair<int,int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = get(i, j);          
        }
    }
    
    vector<ll> dp(m + 1);     
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        if (n % 2 == 0) {
            ll cof = 1; 
            for (int j = 0; j < n; j++) {
                cof &= board[j][i].S != HOR;
            }
            if (cof) {
                add(dp[i + 1], dp[i]);
                //dp[i + 1] = (dp[i + 1] + dp[i]) % MOD; 
            }
        }

        if (i + 2 <= m) {
            vector<vector<ll>> dph(n + 1, vector<ll>(2));
            dph[0][0] = 1;
            for (int j = 0; j < n; j++) {
                if (board[j][i].S != VER && board[j][i + 1].S != VER) {
                    add(dph[j + 1][1], dph[j][0]);
                    add(dph[j + 1][1], dph[j][1]);
                } 
                if (j + 2 <= n) {
                    if (board[j][i].S != HOR && board[j][i + 1].S != HOR && board[j + 1][i].S != HOR && board[j + 1][i + 1].S != HOR) {
                        add(dph[j + 2][0], dph[j][0]);
                        add(dph[j + 2][1], dph[j][1]);
                    }
                }
            }
            add(dp[i + 2], dp[i] * dph[n][1]);
        }
    }
    cout << dp[m] << endl;

#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}