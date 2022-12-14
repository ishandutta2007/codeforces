#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll MOD = 1e9 + 7;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

deque <ll> S;

pll wh[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        S.push_back(a[i]);
    }

    for(int i = 1; i <= n; i++){
        ll Fi = S.front();
        S.pop_front();
        ll Se = S.front();
        S.pop_front();
        wh[i] = {Fi, Se};
        if(Fi > Se){
            S.push_front(Fi);
            S.push_back(Se);
        }else{
            S.push_front(Se);
            S.push_back(Fi);
        }
    }

    vector <ll> b;

    ll X = S[0];

    for(int i = 1; i < n; i++){
        b.p_b(S[i]);
    }

    while(q--){
        ll x;
        cin >> x;
        if(x <= n)cout << wh[x].fi << " " << wh[x].se << "\n"; else{
            x -= n;
            x %= n - 1;
            if(x == 0)x = n - 1;
            cout << X << " " << b[x - 1] << "\n";
        }
    }

    return 0;
}