#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, d;
    cin >> n >> d;

    vector <pll> a(n + 1);
    vector <ll> pref(n + 1);

    ll ans = 0;

    for(int i = 1; i <= n; i++)cin >> a[i].fi >> a[i].se;

    sort(a.begin() + 1, a.end());

    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + a[i].se;

    for(int i = 1; i <= n; i++){
        ll l = i, r = n;
        while(l < r){
            ll c = (l + r) >> 1;
            if(c == l)c++;
            if(a[c].fi - a[i].fi >= d)r = c - 1; else l = c;
        }
        ans = max(ans, pref[l] - pref[i - 1]);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}