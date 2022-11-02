#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

int dp[2][2][1010][1010];
int u[2][2][1010][1010];

int rec(int t, int rev, int a, int b) {
    if(t + a + b == 0) return 0;
    int &res = dp[t][rev][a][b];
    if(u[t][rev][a][b]) return res;
    u[t][rev][a][b] = 1;
    res = 1e9;
    if(a > 0) {
        res = min(res, -rec(t, 0, a-1, b) + 1);
    }

    if(b > 0) {
        res = min(res, -rec(t, 0, a+1, b-1) + 1);
    }
    if(t > 0) {
        res = min(res, -rec(0, 0, a, b) + 1);
    }
    if(!rev && a > 0) {
        res = min(res, -rec(t, 1, a, b));
    }
    return res;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int t = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '1') continue;
        if(i == n-i-1) t = 1;
        else if(s[i] != s[n-i-1]) {
            a++;
        } else {
            b++;
        }
    }
    b /= 2;
    int dif = rec(t, 0, a, b);
    if(dif>0) {
        cout << "BOB\n";
    } else if(dif < 0) {
        cout << "ALICE\n";
    } else{
        cout << "DRAW\n";
    }

}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}