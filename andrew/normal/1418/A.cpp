#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 3000 + 5;
const ll inf = 1e9;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s) {cout << s << endl; exit(0);}

ll dp[N][2];

void solve(){
    ll x, y, k;
    cin >> x >> y >> k;
    ll need = y * k + k - 1;
    cout << need / (x - 1) + ((need % (x - 1)) > 0) + k << "\n";
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);    

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){ 
        solve();
    }
  
    return 0;
}