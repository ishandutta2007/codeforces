#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6 + 1e5;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int p[MAXN], last[MAXN][26];
bool f[MAXN][26];

string s, t;

ll get(ll x) {
    if (x < sz(s)) return s[x];
    return t[x - sz(s)];
}   

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    
        
    cin >> s;

    ll n = sz(s);

    for (int i = 1; i < n; i++) {
        ll j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }

    for (int i = 1; i < n; i++) {
        for (int sm = 0; sm < 26; sm++) {
            last[i][sm] = last[p[i - 1]][sm];            
        }
        last[i][get(i) - 'a'] = i;
    }

    ll q;
    cin >> q;

    while (q--) {        
        cin >> t;        
        for (int i = n; i < sz(s) + sz(t); i++) {
            ll j = p[i - 1];
            while (j >= n && get(i) != get(j)) j = p[j - 1];
            if (j < n) j = last[j][get(i) - 'a'];
            if (get(i) == get(j)) j++;
            p[i] = j;
        }        
        for (int i = n; i < sz(s) + sz(t); i++) {
            cout << p[i] << " ";
        }
        cout << "\n";  
    }


    return 0;
}