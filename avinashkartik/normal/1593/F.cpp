#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, a, b, dp[41][41][41][81][2][2];
bool w[41][41][41][81][2][2];
string s, res;

void bt(int i, int j, int k, int ct, int f1, int f2) {
    if (i == n) return;
    if (w[i][j][k][ct][f1][f2] == 1) {
        res += 'R';
        bt(i + 1, (j * 10 + s[i] - '0') % a, k, ct + 1, f1|1, f2);
    } else {
        res += 'B';
        bt(i + 1, j, (k * 10 + s[i] - '0') % b, ct - 1, f1, f2|1);
    }
}

int mem(int i, int j, int k, int ct, int f1, int f2) {
    if (i == n) {
        if (f1 == 0 || f2 == 0) return 300;
        if (j == 0 && k == 0) {
            if (ct >= 40) return ct - 40;
            return 40 - ct;
        }
        return 300;
    }
    int &ans = dp[i][j][k][ct][f1][f2];
    if (ans != -1) return ans;
    ans = 300;
    int a1 = mem(i + 1, (j * 10 + s[i] - '0') % a, k, ct + 1, f1|1, f2);
    int a2 = mem(i + 1, j, (k * 10 + s[i] - '0') % b, ct - 1, f1, f2|1);
    if (a1 < a2) {
        ans = a1;
        w[i][j][k][ct][f1][f2] = 1;
    } else {
        ans = a2;
        w[i][j][k][ct][f1][f2] = 0;
    }
    return ans;
}

void solve() {
    cin >> n >> a >> b;
    cin >> s;
    mset(dp, -1);
    int ans = mem(0, 0, 0, 40, 0, 0);
    res = "";
    if (ans == 300) {
        deb1(-1)
    } else {
        bt(0, 0, 0, 40, 0, 0);
        deb1(res)
    }
}

int main() {
    GODSPEED;
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        solve();
    }
}