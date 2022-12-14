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
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(auto &i : a)cin >> i;
    sort(all(a));
    int s = 0;
    bool good = 1;
    for(auto i : a){
        s += i;
        if(s == 0)good = 0;
    }
    if(good){
        cout << "YES\n";
        for(auto i : a)cout << i << " ";
        cout << "\n";
        return;
    }
    reverse(all(a));
    s = 0;
    good = 1;
    for(auto i : a){
        s += i;
        if(s == 0)good = 0;
    }
    if(good){
        cout << "YES\n";
        for(auto i : a)cout << i << " ";
        cout << "\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}