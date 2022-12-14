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
const int MAXN = 1123456;
const int M = pw(16);
const long long mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void solve(){
    ll n, h;
    cin >> n >> h;
    vector <ll> a(n);
    for(auto &i : a)cin >> i;
    sort(a.rbegin(), a.rend());
    if(a[0] >= h){
        cout << "1\n";
        return;
    }
    ll x = a[0] + a[1];
    ll ans = h / x;
    h -= ans * x;
    ans *= 2;
    if(h < 1){
        cout << ans << "\n";
        return;
    }
    h -= a[0];
    ans++;
    if(h < 1){
        cout << ans << "\n";
        return;
    }
    h -= a[1];
    ans++;
    if(h < 1){
        cout << ans << "\n";
        return;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}