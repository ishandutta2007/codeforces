#include <bits/stdc++.h>

//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int N = 1e5 + 3;
const int M = pw(10);
const int inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector <ll> a(m + 1);

    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }

    vector <ll> pref(n + 1);

    for(int i = 1; i < m; i++){
        ll l = a[i], r = a[i + 1];
        if(l != r){
            v[l].p_b(r);
            v[r].p_b(l);
        }
        if(l > r)swap(l, r);
        if(r - l < 2)continue;
        pref[l + 1]++;
        pref[r]--;
    }

    ll Ans = 0;
    for(int i = 1; i < m; i++)Ans += abs(a[i] - a[i + 1]);

    for(int i = 1; i <= n; i++){
        pref[i] += pref[i - 1];
        ll res = Ans - pref[i];
        for(auto j : v[i]){
            res -= abs(i - j);
            res += j - (i < j);
        }
        cout << res << " ";
    }
    cout << "\n";

    return 0;
}