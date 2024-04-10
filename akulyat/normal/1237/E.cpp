#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<ll> m;
vector<ll> sz;
vector<ll> ans[2];
bool viv = false;

void count(ll k) {
    for (int a = 0; a < k; a++) {
        ll b = k - 1 - a;
        int ra = a & 1;
        int rb = 0;
        if ((sz[a] == sz[k] - 1 || ((sz[a] == 0 || sz[a] == 1) && sz[a] == sz[k] - 2)) && (sz[b] == sz[k] - 1 || ((sz[b] == 0 || sz[b] == 1) && sz[b] == sz[k] - 2)))
            ans[ra^1][k] += (ans[ra][a] * ans[rb][b]) % mod;
        ans[ra^1][k] %= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/**
    cin >> n;
//    n = 100;
    sz.resize(n+10);
    sz[0] = 0;
    sz[1] = 1;
    for (int i = 2; i < n+10; i++) {
        sz[i] = sz[i-1];
        if ((i & (i-1)) == 0)
            sz[i]++;
    }

    ans[0].resize(n+10);
    ans[1].resize(n+10);
    ans[0][0] = 1;
    ans[1][0] = 1;
    for (ll i = 0; i <= n; i++)
        count(i);
    vector<ll> v;
    v.resize(ans[0].size());
    for (int i = 0; i < v.size(); i++)
        v[i] = (ans[0][i] + ans[1][i])%mod;
    cout << v[n];
// /**
    for (int i = 0; i < n; i++) {
        if ((i & (i-1)) == 0)
            cout << endl;
        cout << i << ':' << ans[0][i] << ' ' << ans[1][i] << ' ' <<  v[i] << endl;
    }
// **/

    set <ll> ans;
    ans.insert(1);
    ans.insert(2);
    ans.insert(4);
    ans.insert(5);
    ll st = 4;
    ll delt = 0;
    for (int i = 0; i < 24; i++) {
        st *= 2;
        if (i & 1) {
            delt++;
            delt *= 2;
        } else {
            delt *= 2;
            delt++;
        }
        ans.insert(st + delt);
        ans.insert(st + delt + 1);
    }

    ll n;
    cin >> n;
    if (ans.count(n))
        cout << 1;
    else
        cout << 0;


    return 0;
}