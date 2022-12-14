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
#define delete _delete

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int kol[N + 5];
bool f[N + 5];

set <pii> s;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, A;

    cin >> n >> A;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= 1e6; i++){
        s.insert({0ll, i});
    }

    ll K = 0;

    f[A] = 1;
    s.erase({0ll, A});

    for(int i = 1; i <= n; i++){
        if(a[i] == A)K++;
        while(!s.empty() && s.begin() -> fi < K){
            f[s.begin() -> se] = 1;
            s.erase(s.begin());
        }

        if(!f[a[i]]){
            s.erase({kol[a[i]], a[i]});
            kol[a[i]]++;
            s.insert({kol[a[i]], a[i]});
        }

    }

    if(s.empty())vout(-1);

    cout << s.begin() -> se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}