#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define ifn(x) if(!(x))
#define fout(x) { cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void main_solve(){
    ll u, v;
    cin >> u >> v;
    if(u == v && u == 0)fout("0\n");
    if(u == v){
        cout << "1\n" << u << "\n";
        return;
    }
    ll delta = v - u;
    if(delta < 0 || (delta & 1))fout(-1);
    vector <ll> vc;
    vc.p_b(u);
    vc.p_b(0);
    vc.p_b(0);
    for(int i = 62; i >= 0; i--)if((delta & pw(i))){
        if((vc[0] & pw(i - 1)) == 0){
            vc[0] |= pw(i - 1);
            vc[1] |= pw(i - 1);
        }else{
            vc[1] |= pw(i - 1);
            vc[2] |= pw(i - 1);
        }
    }
    while(sz(vc) > 1 && vc.back() == 0)vc.pop_back();
    cout << sz(vc) << "\n";
    for(auto i : vc)cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}