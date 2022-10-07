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

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1111;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

int nn;
vector<int> cnt;
int c[N][N];
int dp[11][N];
int pref[N];

void read() {
    scanf("%d", &nn);
    cnt.resize(10);
    for (int i = 0; i < 10; i++)
        scanf("%d", &cnt[i]);
}


void upd(int &a, ll b) {
    a = (a + b) % MOD;
}

ll f(int n, vector<int> cc) {
    int sum = 0;
    for (auto x: cc)
        sum += x;

    if (sum > n) return 0;

    memset(dp, 0, sizeof(dp));
    int canAdd = n - sum;
    dp[0][canAdd] = 1;
    for (int i = 0; i < 10; i++)
        pref[i + 1] = pref[i] + cc[i];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= canAdd; j++) {
            for (int t = 0; t <= j; t++) {
                int before = pref[i] + (canAdd - j); 
                int empty = n - before;
                int cur = cc[i] + t;
                assert(empty >= cur);
                upd(dp[i + 1][j - t], dp[i][j] * 1ll * c[empty][cur]);
            }
        }
    }
    return dp[10][0];
}

void solve() {
    c[0][0] = 1;
    for (int i = 0; i <= nn; i++) 
        for (int j = 0; j <= i; j++) {
            c[i + 1][j] = (c[i + 1][j] + c[i][j]) % MOD;
            c[i + 1][j + 1] = (c[i + 1][j + 1] + c[i][j]) % MOD;
        }
    int res = 0;
    for (int finLen = 1; finLen <= nn; finLen++) {
        for (int i = 1; i <= 9; i++) {
            auto tmp = cnt;
            tmp[i] = max(0, tmp[i] - 1);
            upd(res, f(finLen - 1, tmp));
        }
    }
    //int sum = 0;
    //for (auto x: cnt)
        //sum += x;
    //if (sum == 1)
        //upd(res, 1);
    //if (sum == 0)
        //upd(res, 10);

    cout << res << endl;
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}