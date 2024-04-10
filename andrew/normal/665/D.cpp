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
const ll N = 2e6;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool f[N + 3];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 2; i * i <= N; i++)if(!f[i]){
        for(int j = i * i; j <= N; j += i)f[j] = 1;
    }

    vector <ll> ans;

    for(int i = 1; i <= n; i++)if(a[i] == 1)ans.p_b(1ll);
    for(int i = 1; i <= n; i++)if(a[i] > 1 && !f[a[i] + 1]){
        ans.p_b(a[i]);
        break;
    }

    if(ans.empty())ans.p_b(a[1]);

    for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)if(ans.size() < 2 && !f[a[i] + a[j]]){
        ans.clear();
        ans.p_b(a[i]);
        ans.p_b(a[j]);
    }

    cout << ans.size() << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}