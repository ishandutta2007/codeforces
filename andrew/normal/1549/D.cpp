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
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

long long t[4 * N + 5];

ll gcd(ll a, ll b){
    if(!a || !b){
        return a + b;
    }
    return __gcd(a, b);
}
 
void modify(int v, int tl, int tr, int pos, ll val){
    if(tr == tl){
        t[v] = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm){
        modify(v << 1, tl, tm, pos, val);
    }else{
        modify(v << 1 | 1, tm + 1, tr, pos, val);
    }
    t[v] = gcd(t[v << 1], t[v << 1 | 1]);
}

ll get(int v, int tl, int tr, int l, int r){
    if(l > r)return 0;
    if(tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    return gcd(get(v << 1, tl, tm, l, min(r, tm)), get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve(){
    int n;
    cin >> n;
    vector <ll> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i + 1 < n; i++){
        modify(1, 0, n - 2, i, abs(a[i] - a[i + 1]));
    }

    int ans = 0, l = 0;
    for(int i = 0; i < n - 1; i++){
        while(get(1, 0, n - 2, l, i) == 1){
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans + 1 << "\n";

}

int main(){

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