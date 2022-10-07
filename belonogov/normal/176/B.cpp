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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

string s, t;
ll dp[N][2];

void upd(ll &A, ll B) {
    A = (A + B) % MOD;
}

void read() {
    int k;
    cin >> s >> t;
    cin >> k;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string tmp = s;
        rotate(tmp.begin(), tmp.begin() + i, tmp.end());
        cnt += tmp == t;
    }

    if (s == t) {
        dp[0][0] = 1;
    }
    else {
        dp[0][1] = 1;
    }

    for (int i = 0; i < k; i++) {
        upd(dp[i + 1][0], dp[i][0] * (cnt - 1));
        upd(dp[i + 1][0], dp[i][1] * cnt);

        upd(dp[i + 1][1], dp[i][0] * (n - cnt));
        upd(dp[i + 1][1], dp[i][1] * (n - 1 -  cnt));
    }

    cout << dp[k][0] << endl;



}

void solve() {

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