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
    int n;
    cin >> n;
    if(n == 1)fout("FastestFinger");
    if(n == 2)fout("Ashishgup");
    if(n % 2)fout("Ashishgup");
    int f = n, temp = 1;
    while(f % 2 == 0)f /= 2, temp *= 2;
    if(f == 1)fout("FastestFinger");
    if(temp == 2){
        f = n / 2;
        bool good = 0;
        for(ll i = 2; i * i <= f; i++)if(f % i == 0)good = 1;
        if(!good)fout("FastestFinger");
        fout("Ashishgup");
    }
    fout("Ashishgup");
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> t;

    while(t--)solve();

    return 0;
}