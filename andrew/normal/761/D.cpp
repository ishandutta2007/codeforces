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

    ll n, le, ri;
    cin >> n >> le >> ri;

    vector <ll> a(n + 1), b(n + 1);

    vector <pll> p(n + 1);

    ll mx = 1e18;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++){
        cin >> p[i].fi;
        p[i].se = i;
    }

    sort(p.begin() + 1, p.end());

    for(int i = 1; i <= n; i++){
        ll pos = p[i].se;
        if(a[pos] - ri >= mx)vout(-1);
        ll l = le, r = ri;
        ll val = a[pos] - le;

        val = min(val, mx - 1);
        b[pos] = a[pos] - val;
        mx = val;

    }
    for(int i = 1; i <= n; i++)cout << b[i] << " ";
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}