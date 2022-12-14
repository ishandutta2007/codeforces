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
// const int N = 3e5;
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
    #endif        

    map <ll, ll> mp;

    ll n, q;
    cin >> n >> q;

    vector <fenwick_tree<ll>> t (30, fenwick_tree<ll> (n));

    vector <ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        ll r;
        if (mp.find(x) == mp.end()) {
            mp[x] = rnd();
        }
        r = mp[x];
        for (int j = 0; j < 30; j++) {
            if ((r & pw(j))) {
                t[j].update(i, 1);
            }
        }
    }
    
    while (q--) {
        ll tp;
        cin >> tp;
        if (tp == 2) {
            ll l, r, k;
            cin >> l >> r >> k;
            if (k == 1) {
                cout << "yes\n";
                continue;
            }
            if ((r - l + 1) % k) {
                cout << "no\n";
                continue;
            }
            string ans = "yes";
            for (int i = 0; i < 30; i++) {
                if (t[i].get(l, r) % k) {
                    ans = "no";
                    break;
                }
            }
            cout << ans << "\n";
        }else {
            ll pos, val;
            cin >> pos >> val;
            ll r = mp[a[pos]];
            for (int j = 0; j < 30; j++) {
                if ((r & pw(j))) {
                    t[j].update(pos, -1);
                }
            }

            a[pos] = val;

            if (mp.find(a[pos]) == mp.end()) {
                mp[a[pos]] = rnd();
            }

            r = mp[a[pos]];
            for (int j = 0; j < 30; j++) {
                if ((r & pw(j))) {
                    t[j].update(pos, 1);
                }
            }
        }
    }



    return 0;
}