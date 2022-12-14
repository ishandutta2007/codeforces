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

vector <int> v[N];

int stn, deep[N];
int a[N], b[N], c[N];
int cnt_0[N], cnt_1[N];

ll ans = 0;

void go(int x, int pr = 0){
    int ca, cb;
    ca = cb = 0;
    deep[x] = min(deep[pr], a[x]);
    ca += cnt_0[x];
    cb += cnt_1[x];
    for(auto to : v[x])if(to != pr){
        go(to, x);
        ca += cnt_0[to];
        cb += cnt_1[to];
    }
    ans += 2LL * ll(deep[x]) * ll(min(ca, cb));
    cnt_0[x] = ca - min(ca, cb);
    cnt_1[x] = cb - min(ca, cb);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    deep[0] = 2e9;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }


    vector <int> v1, v0;

    for(int i = 1; i <= n; i++){
        if(b[i] != c[i]){
            if(!b[i]){
                v0.p_b(i);
                cnt_0[i]++;
            }
            else{
                v1.p_b(i);
                cnt_1[i]++;
            }
        }
    }

    if(sz(v0) != sz(v1))vout(-1);

    go(1ll);

    cout << ans << "\n";

    return 0;
}