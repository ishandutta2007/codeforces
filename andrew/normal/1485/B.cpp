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
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

   
    ll n, q, k;
    cin >> n >> q >> k;

    vector <ll> a(n + 1), pref(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    pref[1] = 0;

    for(int i = 2; i < n; i++){
        pref[i] += pref[i - 1] + (a[i + 1] - a[i - 1] - 2);
    }

    while(q--){
        ll l, r;
        cin >> l >> r;
        ll s = 0;
        if(l == r){
            cout << k - 1 << "\n";
        }else{
            if(l + 1 == r){
                cout << a[r] - 2 + (k - a[l] - 1) << "\n";
            }else{
                s = a[l + 1] - 2 + (k - a[r - 1] - 1);
                s += pref[r - 1] - pref[l];
                cout << s << "\n";
            }
        }
    }

    return 0;
}