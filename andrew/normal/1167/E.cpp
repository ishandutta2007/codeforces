#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
const ll N = 1e6 + 5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

ll t[MAXN];
bool f[MAXN];
ll poz[MAXN];

void u(ll pos, ll val){
    for(int i = pos; i <= N; i += i & -i)t[i] += val;
}

ll get(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += t[i];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v[a[i]].p_b(i);
    }

    ll r = m, ans = 0, mn = N;

    for(int i = m; i > 1; i--){
        if(v[i].empty()){
            f[i] = 1;
            u(mn, 1);
            poz[i] = mn;
            ans++;
        }else{
            ll F = v[i][0], S = v[i].back();
            if(mn < S)break;

            mn = min(mn, F);
            f[i] = 1;
            u(mn, 1);
            poz[i] = mn;
            ans++;
        }
    }

    ll mx = 0;

    for(int i = 1; i < m; i++){

        if(f[i + 1]){
            u(poz[i + 1], -1);
        }

        if(v[i].empty()){
            ans++;
            ans += get(N) - get(mx);
        }else{
            ll F = v[i][0], S = v[i].back();
            if(mx > F)break;

            mx = max(mx, S);
            ans++;
            ans += get(N) - get(mx);
        }
    }



    cout << ans + 1 << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}