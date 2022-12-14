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
const int N = 2e5;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const ll MAX = 1e18 + 1000000;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);

    for(auto &i : a){
        cin >> i;
    }

    cout << n * 3 << "\n";
    for(int i = 1; i < n; i += 2){
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "2 " << i << " " << i + 1 << "\n";
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "1 " << i << " " << i + 1 << "\n";
        cout << "2 " << i << " " << i + 1 << "\n";
        cout << "1 " << i << " " << i + 1 << "\n";
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