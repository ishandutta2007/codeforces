#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e3 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
int n, m;
int dp[maxn][11][11];
string s;
int get(int pos,int dif, int last) {
    if(pos == m) return 1;
    int &res = dp[pos][dif][last];
    if(res != -1) return res;
    res = 0;

    for(int i = 1; i <= 10; i++) {
        if(s[i-1] == '1' && last != i && dif < i) {
            res |= get(pos + 1, i - dif, i);
        }
    }
    return res;
}
void rec(int pos,int dif, int last) {
    if(pos == m) return;
    for(int i = 1; i <= 10; i++) {
        if(s[i-1] == '1' && last != i && dif < i && get(pos + 1, i - dif, i)) {
            cout << i << " ";
            rec(pos + 1, i - dif, i);
            return;
        }
    }
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> s >> m;
    if(!get(0, 0, 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rec(0, 0, 0);
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}