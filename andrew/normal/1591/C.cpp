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
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 1e9 + 7;
const int N = 5e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n, k;
    cin >> n >> k;

    vector <int> a(n), l, r;    
    
    while(n--){
        int x;
        cin >> x;
        if(x > 0){
            r.p_b(x);
        }else if(x < 0){
            l.p_b(-x);
        }
    }

    sort(l.rbegin(), l.rend());
    sort(r.rbegin(), r.rend());

    ll ans = 0;

    for(int i = 0; i < l.size(); i += k){
        ans += l[i] * 2;
    }

    for(int i = 0; i < r.size(); i += k){
        ans += r[i] * 2;
    }

    int mx = 0;
    if(l.size()) mx = max(mx, l[0]);
    if(r.size()) mx = max(mx, r[0]);

    ans -= mx;

    cout << ans << "\n";
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