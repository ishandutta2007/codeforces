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
const ll MAXN = 3123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll ans = 0;
    int n;
    cin >> n;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector <int> cnt(n + 1);
    for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++){
        for(int i1 = 1; i1 <= n; i1++)cnt[i1] = 0;
        for(int i1 = 1; i1 <= n; i1++)cnt[a[i1]]++;
        ll sc = 1, S = a[i] + a[j];
        cnt[a[i]]--;
        cnt[a[j]]--;
        for(int i1 = 1; i1 <= n; i1++)if(i != i1 && j != i1 && cnt[a[i1]]){
            int x = a[i1];
            cnt[x]--;
            if(1 <= S - x && S - x <= n){
                if(cnt[S - x]){
                    cnt[S - x]--;
                    sc++;
                }
            }
        }
        ans = max(ans, sc);
    }
    fout(ans);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    cin >> t;
    while(t--)solve();

    return 0;
}