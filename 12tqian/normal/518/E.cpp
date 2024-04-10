#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const double PI = 4 * atan(1);

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

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
const int INF  = 1e9 + 7;
const int MAX = 1e5 + 5;
vi a;
int res [MAX];
int main(){
    fast_io();
    int k, n;
    cin >> n >> k;
    ll ans = 0;
    f0r(i, n){
        string s;
        cin >> s;
        if(s[0] == '?'){
            a.eb(2*INF);
        }
        else{
            a.eb(stoi(s));
            res[i] = stoi(s);
        }
    }
    f0r(i, k){
        int cur = i;
        vpi use;
        use.eb(mp(-2*INF, -1));
        while(cur<n){
            use.eb(mp(a[cur], cur));
            cur += k;
        }
        use.eb(mp(2*(INF + 1), -1));
        int run = 0;
        ll l = use[0].f;
        int id = 0;
        ll r = use[0].f;
      //  cout << use << endl;
        f1r(j,1,  sz(use)){
            if(use[j].f == 2*INF){
                run++;
            }
            else{
                r = use[j].f;
                if(r-l - 1< run){
                   // cout << l << " " << r << " " << run << endl;
                    cout << "Incorrect sequence" << endl;
                    return 0;
                }
                /// run numbers between l and r
                if(l>=0){
                    int add = 1;
                    f1r(it, id+1, j){
                        res [use[it].s] =  (l + add);
                        add++;
                    }
                }
                else if(r<=0){
                    int add = -1;
                    for(int it = j-1; it>= id+1; it--){
                        res[use[it].s] = r + add;
                        add--;
                    }
                }
                else{
                    int lo = -1;
                    int hi = 1;
                    set<int> s;
                    if(run == 0) {

                        run = 0;
                        l = use[j].f;
                        id = j;
                        continue;
                    }
                    s.insert(0);
                    while(sz(s) < run){
                        if(lo == l){
                            s.insert(hi);
                            hi++;
                            continue;
                        }
                        if(hi == r){
                            s.insert(lo);
                            lo--;
                            continue;
                        }
                        if(abs(lo)>abs(hi)){
                            s.insert(hi);
                            hi++;
                            continue;
                        }
                        else{
                            s.insert(lo);
                            lo--;
                            continue;
                        }

                    }
                    int cnt = id+1;
                   // cout << id + 1 << " " << j-1 << " asdf " << run << endl;
                    for(auto x: s){
                        res[use[cnt].s] = x;
                       // cout << use[cnt].s << " " << x << " actual" << endl;
                        cnt++;
                    }

                }
                run = 0;
                l = use[j].f;
                id = j;
            }

        }
    }
    f0r(i, n){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}