#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second 
const int mod = 998244353, x = 8641+97532;

lli hashh[26];

long long modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}


int f (string s) {
    lli now1 = 0, now2 = 0;
    int ans = 0;
    fop (i,0,s.length()) {
        now1 = (now1 + modpow(x, i) * hashh[s[i] - 'a'] % mod) % mod;
        now2 = (now2 * x + hashh[s[i] - 'a']) % mod;
        if (now1 == now2) ans = i + 1;
    }
    return ans;
}

void solve() {
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    int count = 0;
    while (count < s.length() and s[count] == t[count]) count++;
    if (count * 2 >= s.length()) {
        cout << s << endl;
        return;
    }
    string ss =  s.substr(count, s.length() - count * 2);
    string tt = ss;
    reverse(tt.begin(), tt.end());
    int aa = f(ss), bb = f(tt);
    if (aa > bb) {
        cout << s.substr(0, count) + ss.substr(0, aa) + s.substr(s.length() - count) << endl;
    } else {
        cout << s.substr(0, count) + tt.substr(0, bb) + s.substr(s.length() - count) << endl;
    }
}

int main () {
    srand(time(NULL));
    int t;
    cin >> t;
    fop (i,0,26) {
        hashh[i] = 0;
        fop (_,0,6) {
            hashh[i] = (hashh[i] << 10) | (rand() & 1023);
        }
        hashh[i] %= mod;
    }
    while (t--) solve();
}