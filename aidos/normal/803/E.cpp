#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;

string s;
int dp[1010][1010];
int get(int pos, int dif) {
    if(pos == n) {
        return abs(dif) == k;
    }
    if(abs(dif) >= k) return 0;
    int &res = dp[pos][dif + k];
    if(res != -1) return res;
    if(s[pos] == 'D') {
        res = get(pos + 1, dif);
        return res;
    }
    if(s[pos] == 'W') {
        res = get(pos + 1, dif + 1);
        return res;
    }
    if(s[pos] == 'L') {
        res = get(pos + 1, dif - 1);
        return res;
    }
    res = get(pos + 1, dif) | get(pos + 1, dif + 1) | get(pos + 1, dif-1);
    return res;
}
void rec(int pos,int dif) {
    if(pos == n) return;
    if(get(pos + 1, dif) && (s[pos] == 'D' || s[pos] == '?')) {
        cout << 'D';
        rec(pos + 1, dif);
        return;
    }
    if(get(pos + 1, dif + 1) && (s[pos] == 'W' || s[pos] == '?')) {
        cout << 'W';
        rec(pos + 1, dif + 1);
        return;
    }

    if(get(pos + 1, dif - 1) && (s[pos] == 'L' || s[pos] == '?')) {
        cout << 'L';
        rec(pos + 1, dif - 1);
        return;
    }
}
void solve() {
    cin >> n >> k >> s;
    memset(dp, -1, sizeof dp);
    if(get(0, 0)) {
        rec(0, 0);
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}