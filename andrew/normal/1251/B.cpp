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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void sol(){

    vector <int> cnt(2);

    ll n;
    cin >> n;

    vector <ll> a, b;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(sz(s) % 2)b.p_b(sz(s));
        else a.p_b(sz(s));
        for(auto i : s)cnt[i - '0']++;
    }

    ll ans = 0;

    sort(all(a));
    sort(all(b));

    vector <ll> c = a;

    for(int i = 0; i <= sz(b); i++){
        sort(all(c));

        for(int j = 0; j <= min(cnt[0], sz(b)); j++)if(cnt[1] >= i - j){
            ll ra = cnt[0] - j, rb = cnt[1] - (i - j), sum = 2 * (ra / 2 + rb / 2);
            ll sc = 0;
            for(auto kek : c){
                if(sum >= kek){
                    sum -= kek;
                    sc++;
                }
            }
            ans = max(ans, sc);
        }


        if(i < sz(b))c.p_b(b[i] - 1);
    }

    cout << ans << "\n";

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
        sol();
    }

    return 0;
}