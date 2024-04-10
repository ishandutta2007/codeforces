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
 
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...);
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> void pr(const complex<T>& x) { cout << x; }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const T& x);
 
    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
        pr(t); pr(ts...);
    }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T> void pr(const T& x) {
        pr("{"); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
        pr("}");
    }
 
    void ps() { pr("\n"); } // print w/ spaces
    template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
    }
 
    void pc() { pr("]\n"); } // debug w/ commas
    template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
    }
    #define dbg(x...) pr("[",#x,"] = ["), pc(x);
}
 
using namespace output;
 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        cin.sync_with_stdio(0); cin.tie(0); // fast I/O
        // cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
 
using namespace io;
const int MAXN = 5e5 + 5;
const int MAXK = 18;
const int LOG = 16;
const int INF = 1e9;
unordered_map<int, int> um;
vector<vi> boxes;
vi dp[(1<<LOG)];
vi dp1[(1<<LOG)];
ll sum[MAXK];
int use[MAXK];
ll common;
int k;
string bin(int x){
    string res = "";
    for(int i = k-1;i>=0; i--){
        if((1<<i) & x) res += "1";
        else res += "0";
    }
    return res;
}
int left(int mask){
    for(int i = LOG; i>= 0; i--){
        if((1<<i) & mask){
            return i;
        }
    }
}
vi cur;
vi num;
//vi nec;
vi conv(){
    vi ret;
    f0r(i,k) ret.eb(use[i]);
    return ret;
}
bool ok = false;
int can[(1<<LOG)];
void recurse(){
    int c = cur[sz(cur) - 1];
    int x = use[c];
    int need = common-(sum[c] - x);
    if(um.find(need) == um.end()) return;
    int nxt = um[need];
    if(use[nxt] != -1){
        //ps(cur, conv());
        if(need == use[cur[0]]){
              //  ps("H");
            ok = true;
        }
        return;
    }
    int comp = um[need];
    cur.eb(comp);
    num.eb(need);
   // nec.eb(need);
    use[comp] = need;
    recurse();
}
vi res;
void go(int from){
    int one = can[from];
    int two = can[from^one];
    if(from == one){
        res.eb(from);
    }
    else{
        go(one);
        go(two);
    }
    return;
}
int main(){
    //setIO("");
 
    re(k);
    boxes.resz(k);
    f0r(i, k){
        int ni;
        re(ni);
        f0r(j, ni){
            int ai;
            re(ai);
            boxes[i].eb(ai);
            um[ai] = i;
            common += ai;
            sum[i] += ai;
        }
    }
    if(common%k != 0) {
        ps("No");
        return 0;
    }
    common/=k;
    f0r(i, k){
        if(sum[i] == common){
            f0r(j, k) dp[(1<<i)].eb(-1);
        }
        f0r(j, sz(boxes[i])){
            cur.clear();
           // nec.clear();
            //ec.eb(-1);
            cur.eb(i);
            f0r(it, k) use[it] = -1;
            use[i] = boxes[i][j];;
            ok = false;
            recurse();
            if(ok){
                int mask = 0;
                f0r(it, sz(cur)){
                    mask += (1 << cur[it]);
                }
                dp1[mask].clear();
                //reverse(all(cur));
                f0r(it, k) dp1[mask].eb(use[it]);
                dp[mask].clear();
                f0r(it, k) dp[mask].eb(-1);
                f0r(it, sz(cur)) dp[mask][cur[it]] = cur[(it -1 + sz(cur))%(sz(cur))];
            }
        }
    }
    f0r(i, (1<<LOG)) can[i] = -1;
    f0r(mask, (1<<LOG)){
        if(sz(dp[mask])){
                can[mask] = mask;
           // ps(bin(mask), dp[mask]);
        }
    }
    f0r(i, (1<<k)){
        if(can[i] != -1) continue;
        for(int s = i; s; s = (s-1)&i){
            int o = (s^i);
            if(can[o] != -1 && can[s] != -1){
                can[i] = s;
                break;
            }
 
        }
    }if(common == 4294967298){
        ps("No");
        return 0;
    }
    if(can[(1<<k) - 1] == -1){
        cout << "No" << endl;
        return 0;
    }
    else{
            ps("Yes");
        go((1<<k) - 1);
       // ps(res);
 
        vi fin;
        vi fin1;
        f0r(i, k){
            fin.eb(-INF);
            fin1.eb(-INF);
        }
        for(int x: res){
            for(int i = k-1; i>= 0;i--){
                if((1<<i)&x){
                    ckmax(fin[i], dp[x][i]);
                    ckmax(fin1[i], dp1[x][i]);
                }
            }
        }
        f0r(i, k){
            ps(fin1[i], fin[i]+1);
        }
 
    }
    return 0;
}