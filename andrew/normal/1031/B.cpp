#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
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
mt19937_64 gen;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


vector <ll> t, a, b;
ll n;
vector <ll> mb;
void dfs(ll x){
    t.p_b(x);

    if(t.size() == n){
        mb = t;
        t.pop_back();
        return;
    }

    for(int i = 0; i < 2; i++)if((t.back() & i) == (b[t.size()] & 1) && (t.back() | i) == (a[t.size()] & 1))dfs(i);
    t.pop_back();
}

void rec(ll x){
    t.p_b(x);
    if(t.size() == n){
        if(mb.empty())vout("NO");
        for(int i = 0; i < t.size(); i++)mb[i] |= t[i] << 1;
        cout << "YES\n";
        for(auto i : mb)cout << i << " ";
        cout << "\n";
        exit(0);
    }
    for(int i = 0; i < 2; i++)if((t.back() & i) == ((b[t.size()] >> 1) & 1) && (t.back() | i) == ((a[t.size()] >> 1) & 1))rec(i);
    t.pop_back();

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    a.resize(n);
    b.resize(n);
    for(int i = 1; i < n; i++)cin >> a[i];
    for(int i = 1; i < n; i++)cin >> b[i];

    for(int i = 0; i < 2; i++)dfs(i);
    for(int i = 0; i < 2; i++)rec(i);
    vout("NO");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}