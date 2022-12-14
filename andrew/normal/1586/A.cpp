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
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n;
    cin >> n;  
    vector <int> a(n);
    ll s = 0;
    for(auto &i : a){
        cin >> i;
        s += i;
    }

    bool f = 0;
    for(int i = 2; i * i <= s; i++)if(s % i == 0){
        f = 1;
        break;
    }
    if(f){
        cout << n << "\n";
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << "\n";
    }else{
        int pos = -1;
        cout << n - 1 << "\n";
        for(int i = 1; i <= n; i++){
            if(a[i - 1] % 2 && pos == -1){
                pos = 1;
            }else{
                cout << i << " ";
            }
        }
        cout << "\n";
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