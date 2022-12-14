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
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e6 + 20;
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int last[N];

void pre_calc(){
    for(int i = 2; i < N; i++){
        if(!last[i]){
            last[i] = i;
            for(ll j = (ll)i * ll(i); j < N; j += i){
                last[j] = i;
            }
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    vector <vector <int>> b(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i % q].p_b(a[i]);
    }

    ll ans = 0;

    for(int i = 0; i < q; i++)if(!b[i].empty()){
        int m = b[i].size();
        vector <ll> le(m), ri(m);
        int s = 0;
        for(int j = 0; j < m; j++){            
            le[j] = s;
            s = (b[i][j] == 1 ? s + 1 : 0);
        }        
        s = 0;
        for(int j = m - 1; j >= 0; j--){
            ri[j] = s;
            s = (b[i][j] == 1 ? s + 1 : 0);
        }

        for(int j = 0; j < m; j++){
            if(last[b[i][j]] == b[i][j]){
                ans += le[j] * ri[j];
                ans += ri[j];
                ans += le[j];
            }
        }
    }

    cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre_calc();

    int t;
    cin >> t;    

    while(t--){
        solve();
    }
    
    return 0;
}