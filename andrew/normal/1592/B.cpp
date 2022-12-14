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
const int N = 2e5;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void solve(){
    int n, x;
    cin >> n >> x;
    vector <ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    b = a;
    sort(all(b));
    if(x * 2 <= n){
        cout << "YES\n";
    }else{
        for(int i = 0; i < n; i++){
            if(i < x && (n - 1 - i) < x){
                if(a[i] != b[i]){
                    fout("NO");
                }
            }
        }
        cout << "YES\n";
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