#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define resz resize
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
struct use{
    int a[26];
    use(){
        f0r(i, 26)a[i] = 0;
    }
};
vector<use> v;

const int MAX = 1e5 + 5;
use st[MAX];
 struct DSU{
 //   int par[SZ], sz[SZ];
    vi par;
    vi sz;
    void init(int n){
        f0r(i, n){
            par.eb(i);
            sz.eb(1);
        }
    }
    int get(int x){
        if(par[x] != x){
            par[x] = get(par[x]);
        }
        return par[x];
    }
    bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x == y){
            return false;
        }
        if(sz[x] < sz[y]){
            swap(x, y);
        }
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
};
use beg[MAX];
void add(use x, int i){
    f0r(j, 26){
        ckmax(beg[i].a[j], x.a[j]);
    }
}
int main(){
    fast_io;
    int n;
    cin >> n;
    f0r(i, n){
        string s;
        cin >> s;
        use temp;
        f0r(j, sz(s)){
          //  if(i == 1) cout << s[j] - 'a' << "adsfasdfasd" << endl;
            temp.a[s[j] - 'a'] = 1;
        }
        v.eb(temp);
    }
        f0r(j, n){
            f0r(k, 26){
              //  cout << v[j].a[k] << " ";
                if(v[j].a[k] == 1){
                    add(v[j], k);
                    break;
                }
            }
          //  cout << endl;

        }
      //  cout << "adfasd" << endl;
  /* f0r(i, 26){
        f0r(j, 26){
            cout << beg[i].a[j] << " ";
        }
        cout << endl;
    }*/
    DSU d;
    d.init(26);
    f0r(i, 26){
        f1r(j, i+1, 26){
            f0r(k, 26){
                if(beg[i].a[k] + beg[j].a[k] == 2){
                    d.unite(i, j);
                    f0r(l, 26){
                        ckmax(beg[i].a[k], beg[j].a[k]);
                        ckmax(beg[j].a[k], beg[i].a[k]);
                    }
                    break;
                }
            }
        }
    }
    set<int> fin;
    f0r(i, 26) {
        int x = d.get(i);
        bool ok = false;
        f0r(j, 26){
            if(beg[x].a[j] == 1){
                ok = true;
                break;
            }
        }
        if(ok)fin.insert(d.get(i));
    }
    cout << sz(fin) << endl;
    return 0;
}