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
const int N = 1010;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

using namespace std;

void solve(){
    string s;
    cin >> s;
    cout << *max_element(all(s)) << "\n";
}

int main() {
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