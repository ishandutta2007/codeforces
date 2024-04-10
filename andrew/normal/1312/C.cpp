#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
const ll N = 1500;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll zapros;
ll fufel[MAXN];

void solve(){
    ll n, k;
    cin >> n >> k;
    ++zapros;
    ll step, val, x;
    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];


    step = val = 1;

    ll con = 1e18;

    while(con / val >= k){
        val *= k;
        step++;
    }

    while(step){
        for(int i = 1; i <= n; i++){
            if(a[i] >= val){
                a[i] -= val;
                break;
            }
        }
        step--;
        val /= k;
    }
    if(*max_element(all(a)) > 0)fout("NO");
    fout("YES");
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

    while(t--){
        solve();
    }

    return 0;
}