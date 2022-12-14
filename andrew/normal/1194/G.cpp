#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll u(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

ll add(ll a, ll b){
    if(a + b >= mod)return a + b - mod;
    return a + b;
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

struct ForDp{
    ll musk1, musk2, fl1, fl2, ost1, ost2;
};

inline bool operator <(ForDp a, ForDp b){

    if(a.musk1 < b.musk1)return 1;
    if(a.musk1 > b.musk1)return 0;

    if(a.musk2 < b.musk2)return 1;
    if(a.musk2 > b.musk2)return 0;

    if(a.ost1 < b.ost1)return 1;
    if(a.ost1 > b.ost1)return 0;

    if(a.ost2 < b.ost2)return 1;
    if(a.ost2 > b.ost2)return 0;

    if(a.fl1 < b.fl1)return 1;
    if(a.fl1 > b.fl1)return 0;

    if(a.fl2 < b.fl2)return 1;
    if(a.fl2 > b.fl2)return 0;

    return 0;

}
inline bool operator >(ForDp a, ForDp b){

    if(a.musk1 > b.musk1)return 1;
    if(a.musk1 < b.musk1)return 0;

    if(a.musk2 > b.musk2)return 1;
    if(a.musk2 < b.musk2)return 0;

    if(a.ost1 > b.ost1)return 1;
    if(a.ost1 < b.ost1)return 0;

    if(a.ost2 > b.ost2)return 1;
    if(a.ost2 < b.ost2)return 0;

    if(a.fl1 > b.fl1)return 1;
    if(a.fl1 < b.fl1)return 0;

    if(a.fl2 > b.fl2)return 1;
    if(a.fl2 < b.fl2)return 0;

    return 0;

}
inline bool operator ==(ForDp a, ForDp b){
    if(a.musk1 == b.musk1 && a.musk2 == b.musk2 && a.ost1 == b.ost1 && a.ost2 == b.ost2 && a.fl1 == b.fl1 && a.fl2 == b.fl2)return 1;
    return 0;
}

map <ForDp, ll> dp[103];

string s;
ll n;

ll fnumber[20], fdenominat[20];

ForDp Useless;

ll sol(ll x, ll y){

    for(int i = 0; i < 10; i++)fnumber[i] = fdenominat[i] = -1;

    ll stn = 0;
    ll x1 = x, y1 = y;

    while(x1 < 10 && y1 < 10){
        fnumber[x1] = stn;
        fdenominat[y1] = stn;
        stn++;
        x1 += x;
        y1 += y;
    }

    for(int i = 0; i <= n; i++)dp[i].clear();

    Useless.fl1 = 0;
    Useless.fl2 = 0;
    Useless.musk1 = 0;
    Useless.musk2 = 0;
    Useless.ost1 = 0;
    Useless.ost2 = 0;

    dp[0][Useless] = 1;

    for(int step = 0; step < n; step++){
        for(auto old : dp[step]){
            for(int digit_z = 0; digit_z < 10; digit_z++){
                ll val1 = digit_z * x + old.fi.ost1, val2 = digit_z * y + old.fi.ost2;
                ll digit1 = val1 % 10, digit2 = val2 % 10;
                ll R = s[step] - '0';
                bool fl1 = 0, fl2 = 0;

                if((digit1 > R) || (digit1 == R && old.fi.fl1))fl1 = 1;
                if((digit2 > R) || (digit2 == R && old.fi.fl2))fl2 = 1;
                ll musk1, musk2;
                musk1 = old.fi.musk1;
                musk2 = old.fi.musk2;
                if(fnumber[digit1] != -1)musk1 |= pw(fnumber[digit1]);
                if(fdenominat[digit2] != -1)musk2 |= pw(fdenominat[digit2]);
                Useless.fl1 = fl1;
                Useless.fl2 = fl2;
                Useless.musk1 = musk1;
                Useless.musk2 = musk2;
                Useless.ost1 = val1 / 10;
                Useless.ost2 = val2 / 10;
                u(dp[step + 1][Useless], old.se);
            }
        }
    }

    ll res = 0;
    for(auto i : dp[n])if(i.fi.fl1 == 0 && i.fi.fl2 == 0 && (i.fi.musk1 & i.fi.musk2)){
        u(res, i.se);
    }

    return res;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    s = "00" + s;
    reverse(all(s));

    n = s.size();

    ll ans = 0;

    for(int x = 1; x < 10; x++)
        for(int y = 1; y < 10; y++)if(__gcd(x, y) == 1)u(ans, sol(x, y));

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}