#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const int LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , q , ps[MAXN][26] , kmp[MAXN];
string s[LOG] , t;

int calc(const string &s , const string &t){
    int n = SZ(s) , m = SZ(t) , ans = 0;
    fill(kmp , kmp + n , 0);
    for(int i = 1 , k = 0 ; i < n ; i++){
        while(k > 0 && s[i] != s[k])    k = kmp[k - 1];
        if(s[i] == s[k])    k++;
        kmp[i] = k;
    }
    for(int i = 0 , k = 0 ; i < m ; i++){
        while(k > 0 && t[i] != s[k])    k = kmp[k - 1];
        if(t[i] == s[k])    k++;
        // cout << i << sep << k << endl;
        if(k == n)  k = kmp[k - 1] , ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q >> s[0] >> t;
    for(int i = 1 ; i <= min(n , LOG - 1) ; i++){
        if(SZ(s[i - 1]) >= MAXN)    continue;
        s[i] = s[i - 1] + t[i - 1] + s[i - 1];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 26 ; j++){
            ps[i][j] = ps[i - 1][j];
        }
        int x = t[i - 1] - 97;
        ps[i][x] = (ps[i][x] + poww(2 , MOD - 1 - i , MOD)) % MOD;
    }
    //q = 1;
    while(q--){
        int k , cur = 0;
        string x;
        cin >> k >> x;
        while(SZ(s[cur]) < SZ(x))   cur++;
        if(cur > k){
            cout << 0 << endl;
            continue;
        }
        int val = calc(x , s[cur]) , ans = 0;
        //cout << s[cur] << sep << x << sep << val << endl;
        ans = 1ll * val * poww(2 , MOD - 1 - cur , MOD) % MOD;
        for(int i = 0 ; i < 26 ; i++){
            int F = calc(x , s[cur] + char(i + 'a') + s[cur]) - val * 2;
            //cout << i << sep << F << endl;
            ans += 1ll * (ps[k][i] - ps[cur][i] + MOD) % MOD * F % MOD;
            if(ans >= MOD)  ans -= MOD;
        }
        cout << 1ll * ans * poww(2 , k , MOD) % MOD << endl;
    }

    return 0;
}
/*

*/