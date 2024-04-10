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
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct fenwick_tree{
    vector <T> t;
    fenwick_tree(int n){
        t.resize(n + 1);
        fill(t.begin(), t.end(), 0);
    }
    
    T get(int l, int r){
        return f(r) - f(l - 1);
    }
    
    void update(int pos, T val){
        u(pos, val);
    }

private:
    T f(int pos){
        T res = 0;
        for(int i = pos; i > 0; i -= i & -i) res += t[i];
        return res;
    }
    void u(int pos, T val){
        for(int i = pos; i < (int)t.size(); i += i & -i) t[i] += val;
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //  cin >> t;
    #endif    
    
    ll n, m, q;
    cin >> n >> m >> q;

    fenwick_tree<ll> t(n * m);

    char a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
                t.update(j * n + i + 1, 1);                
            }
        }


    while (q--) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        if (a[x][y] == '*') {
            t.update(y * n + x + 1, -1);
            a[x][y] = '.';
        }else {
            t.update(y * n + x + 1, 1);
            a[x][y] = '*';
        }
        ll ans = 0, c = t.get(1, n * m);
        if (c) {
            ans = c - t.get(1, c);
        }
        cout << ans << "\n";
    }

    return 0;
}