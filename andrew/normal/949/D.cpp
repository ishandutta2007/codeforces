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
#define pii pair<int,int>
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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


ll n, B, d;
vector <ll> a, pref;

bool check(ll l, ll r){
    vector <ll> b;
    b = a;
    ll ukl = 1, ukr = n;

    ll le = 1, ri = n;
    ll time = 0;

    while(le <= ri){
        time++;

        if(l <= le && le <= r){
            ll Su = B;
            while(Su){
                if(ukl > n || abs(ukl - le) > time * d)return 0;
                ll k = min(b[ukl], Su);
                Su -= k;
                b[ukl] -= k;
                if(!b[ukl])ukl++;
            }
        }
        if(le != ri && l <= ri && ri <= r){
            ll Su = B;
            while(Su){
                if(ukr < 1 || abs(ukr - ri) > time * d){
                    return 0;
                }
                ll k = min(b[ukr], Su);
                Su -= k;
                b[ukr] -= k;
                if(!b[ukr])ukr--;
            }
        }
        le++, ri--;
    }
    return 1;
}

ll sol(){
    ll l = 0, r = n / 2;
    while(l < r){
        ll c = (l + r) >> 1;
        if(!check(1 + c, n - c))l = c + 1; else r = c;
    }
    return l;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> B;

    a.resize(n + 1);


    for(int i = 1; i <= n; i++)cin >> a[i];
    cout << sol() << "\n";
    return 0;
}