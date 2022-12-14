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
const int N = 2e5;
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i + 2 < n; i++){
        if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
            ans++;
        }
    }

    while(q--){
        int pos;
        char val;
        cin >> pos >> val;
        pos--;
        for(int i = max(0, pos - 3); i + 2 < n && i + 2 < pos + 10; i++){
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
                ans--;
            }   
        }
        s[pos] = val;

        for(int i = max(0, pos - 3); i + 2 < n && i + 2 < pos + 10; i++){
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
                ans++;
            }   
        }
        cout << ans << '\n';
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    //cin >> t;
    t = 1;

    while(t--){
        solve();
    }
    
    return 0;
}