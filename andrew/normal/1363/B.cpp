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
    string s;
    cin >> s;
    int n = sz(s);
    vector <int> pref(n + 1);
    for(int i = 0; i < n; i++){
        if(s[i] == '1')pref[i] = 1;
        if(i)pref[i] += pref[i - 1];
    }
    int ans = n - max(pref[n - 1], n - pref[n - 1]);
    int ra, rb;
    ra = rb = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')ra++;
        ans = min(ans, ra + (n - pref[n - 1]) - (i + 1 - pref[i]));
    }

    ra = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '0')ra++;
        ans = min(ans, ra + pref[n - 1] - pref[i]);
    }
    fout(ans);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    ll t;
    cin >> t;
    while(t--)solve();

    return 0;
}