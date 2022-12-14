#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    int n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    if(k == n){
        ll mx_even, mx_odd;
        mx_even = mx_odd = 0;
        for(int i = 0; i < n; i += 2)mx_even = max(mx_even, a[i]);
        for(int i = 1; i < n; i += 2)mx_odd = max(mx_odd, a[i]);
        fout(min(mx_even, mx_odd));
    }

    ll l = 1, r = 1e9;
    while(l < r){
        ll c = (l + r) >> 1;
        bool good = 0;

        vector <int> pos;

        for(int i = 0; i < n; i++){
            if(a[i] <= c)pos.p_b(i);
        }

        vector <int> ans;

        for(int i : pos){
            if(ans.empty())ans.p_b(i);
            else if(i - ans.back() > 1)ans.p_b(i);
        }

        if(!ans.empty()){
            if(sz(ans) * 2 - (ans.back() == n - 1) >= k)good = 1;
        }

        ans.clear();

        for(int i : pos){
            if(!i)continue;
            if(ans.empty())ans.p_b(i);
            else if(i - ans.back() > 1)ans.p_b(i);
        }

        if(!ans.empty()){
            int sc = sz(ans) * 2;
            if(ans.back() != n - 1)sc++;
            if(sc >= k)good = 1;
        }
        if(!good)l = c + 1;
        else r = c;
    }
    fout(l);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif // LOCAL

    while(t--)solve();

    return 0;
}