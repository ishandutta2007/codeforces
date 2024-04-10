#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const long double PI = 4 * atan((long double) 1);

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int ALPH = 26;
ll val [ALPH];
ll cnt (string s){
    f0r(i, ALPH) val[i] = 0;
    vi a;
    int n = sz(s);
    f0r(i, n) a.eb(s[i] - 'a');
    ll res = 0;
    f0r(i, n){
        val[a[i]]++;
        f0r(j, a[i]){
            res += val[j];
        }
    }
    return res;
}
int main(){
    fast_io();
    int q;
    cin >> q;
    while(q--){
        int n;
        string s, t;
        cin >> n >> s >> t;

        f0r(i, ALPH) val[i] = 0;
        f0r(i, n) val[s[i] - 'a']++;
        f0r(i, n) val[t[i] - 'a']--;
        bool ok = true;
        f0r(i, ALPH){
            if(val[i] != 0){
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout << "NO" << endl;
            continue;
        }
        f0r(i, ALPH) val[i] = 0;
        f0r(i, n) val[s[i] - 'a']++;
        ok = false;
        f0r(i, ALPH) if(val[i]>1){
            cout << "YES" << endl;
            ok = true;
            break;
        }
        if(ok) continue;
        ll x = cnt(s);
        ll y = cnt(t);
        if(x%2 != y%2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}