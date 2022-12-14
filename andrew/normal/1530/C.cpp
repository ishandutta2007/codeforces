#include <bits/stdc++.h>

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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1010;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

using namespace std;

void solve(){
    ll n;
    cin >> n;

    vector <ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    ll l = 0, r = 1e12;
    while(l < r){
        ll mid = (l + r) >> 1;
        ll c = (mid + n) - (mid + n) / 4, ost = min(mid, c);
        ll suma = ost * 100, sumb = 0;
        for(int i = 0; i < min(n, c); i++) sumb += b[i];
        for(int i = 0; i < c - ost; i++) suma += a[i];
        if(suma >= sumb){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    //t = 1;

    while(t--){
        solve();
    }

    return 0;
}