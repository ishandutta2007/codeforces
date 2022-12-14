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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void main_solve(){
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < sz(a); i++){
        set <char> s;
        bool f = 0;
        swap(c[i], b[i]);
        if(a[i] == b[i])f = 1;
        swap(c[i], b[i]);
        swap(c[i], a[i]);
        if(a[i] == b[i])f = 1;
        if(!f)fout("NO");
    }
    fout("YES");
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
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #endif // LOCAL



    return 0;
}