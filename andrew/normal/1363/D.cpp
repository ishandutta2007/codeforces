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
    ll n, k;
    cin >> n >> k;
    ll Max, Idx;
    vector <vector <ll>> a(k);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        a[i].resize(x);
        for(auto &j : a[i])cin >> j;
    }
    cout << "? " << n;
    for(int i = 1; i <= n; i++)cout << " " << i;
    cout << endl;
    cin >> Max;
    ll l = 1, r = n;
    while(l < r){
        ll c = (l + r) >> 1;
        cout << "? " << c;
        for(int i = 1; i <= c; i++)cout << " " << i;
        cout << endl;
        ll x;
        cin >> x;
        if(x != Max)l = c + 1;
        else r = c;
    }
    Idx = l;

    vector <ll> ans(k);

    for(int i = 0; i < k; i++){
        bool f = 0;
        for(auto j : a[i])if(j == Idx){
            f = 1;
        }
        if(!f){
            ans[i] = Max;
        }else{
            set <int> s;
            for(int i = 1; i <= n; i++)s.insert(i);
            for(auto j : a[i])s.erase(j);
            cout << "? " << sz(s);
            for(auto i : s)cout << " " << i;
            cout << endl;
            ll x;
            cin >> x;
            ans[i] = x;
        }
    }
    cout << "!";
    for(auto i : ans)cout << " " << i;
    cout << endl;
    string c;
    cin >> c;
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

//    #ifdef LOCAL
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif // LOCAL

    ll t;
    cin >> t;
    while(t--)solve();

    return 0;
}