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
const ll MAXN = 2123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll ans[MAXN];

const ll mod = 1e9 + 7;

void fufel(){
    ll n;
    cin >> n;
    cout << (ans[n] * 4) % mod << "\n";
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 1;
    ans[4] = 1;
    ans[5] = 3;
    for(int i = 6; i < MAXN; i++){
        ll a = ans[i - 1], b = ans[i - 1];
        if((i - 4) % 6 == 0)b = (b - 1 + mod) % mod;
        if((i - 4) % 6 == 5)b = (b + 1) % mod;
        if((i - 4) % 6 == 1)b = (b + 1) % mod;
        ans[i] = (a + b) % mod;
    }

    int t = 1;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> t;

    while(t--)fufel();

    return 0;
}