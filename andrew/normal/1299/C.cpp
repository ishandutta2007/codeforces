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

bool bad(pll a, pll b){
    return (a.fi * b.se > b.fi * a.se);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    vector <pll> st;

    for(int i = 1; i <= n; i++){
        ll sum = a[i], cnt = 1;
        while(!st.empty() && bad(st.back(), {st.back().fi + sum, st.back().se + cnt})){
            sum += st.back().fi;
            cnt += st.back().se;
            st.pop_back();
        }
        st.p_b({sum, cnt});
    }

    for(auto i : st){
        ld ans = ld(i.fi) / ld(i.se);
        int cnt = i.se;
        while(cnt--)cout << fixed << setprecision(9) << ans << "\n";
    }

    return 0;
}