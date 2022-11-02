#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e3 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
int n, k;
int dp[maxn][maxn];
string T[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int b[10];
int a[maxn];
int all;
int get(int pos,int need) {
    if(need < 0) return 0;
    if(pos == n) return need == 0;
    int &res = dp[pos][need];
    if(res != -1) return res;
    res = 0;

    for(int i = 9; i >= 0; i--) {
        if((b[i]^all) & a[pos]) continue;
        if((b[i]^a[pos]) & a[pos]) continue;
        if(get(pos+1, need-__builtin_popcount(a[pos]^b[i]))) res=1;
    }
    return res;
}
void rec(int pos,int need) {
    if(pos == n) return;
    for(int i = 9; i >= 0; i--) {
        if((b[i]^all) & a[pos]) continue;
        if((b[i]^a[pos]) & a[pos]) continue;
        if(get(pos+1, need-__builtin_popcount(a[pos]^b[i]))) {
            cout << i;
            rec(pos+1, need-__builtin_popcount(a[pos]^b[i]));
            return;
        }
    }
}

void solve() {
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 7; j++) b[i] = b[i] * 2  + T[i][j] - '0';
    }
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 7; j++) a[i] = a[i] * 2 + s[j] - '0';
    }
    all = (1<<7) - 1;
    if(!get(0, k)) {
        cout << -1 << "\n";
    } else {
        rec(0, k);
    }
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