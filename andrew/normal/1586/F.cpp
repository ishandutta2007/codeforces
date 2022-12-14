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

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    ll l = 1;
    vector <ll> st;

    while(l < n){
        st.p_b(l);
        l *= k;
    }

    cout << sz(st) << "\n";

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int p = sz(st) - 1; p >= 0; p--){
                if(i / st[p] != j / st[p]){
                    cout << p + 1 << " ";
                    break;
                }
            }
        }
    }

    cout << "\n";

    return 0;
}