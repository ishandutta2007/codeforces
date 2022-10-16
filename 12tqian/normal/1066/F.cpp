#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
const ll INF = 1e18;
vector<pair<ll, ll>> p;
map<ll, vector<pair<ll, ll>>> levels;
map<ll, pair<pair<ll, ll>, pair<ll, ll>>> bounds;
const int MAX = 2e5 + 5;
ll dp[MAX][2];
map<ll, ll> m;
ll dist(pair<ll, ll> a, pair<ll, ll> b){
    ll ret = abs(a.f - b.f) + abs(a.s - b.s);
   // cout << ret<< " dist" << endl;
    return ret;
    //return abs(a.f - b.f) + abs(a.s - b.s);
}
void pr(pair<ll, ll> a){
    cout << "(" << a.f<< ", " << a.s << ")" << endl;
}
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        int xi, yi;
        cin >> xi >> yi;
        levels[max(xi, yi)].eb(mp(xi, yi));
    }
    int cur = 1;
    for(auto x: levels){
        m[cur] = x.f;
        cur++;
        pair<ll, ll> a = mp(INF, INF);
        pair<ll, ll> b = mp(INF, INF);
        for(auto i: x.s){
            if(a.f - a.s>i.f -i.s) a = i;
            if(b.f - b.s<i.f -i.s) b = i;
            if(a.f>i.f) a = i;

            if(b.s>i.s) b = i;
        }
        bounds[x.f] = mp(a, b);
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    bounds[0] = mp(mp(0, 0), mp(0, 0));
    m[0] = 0;
    cur = 1;
    /*for(auto x: bounds){
        cout << x.f << endl;
        pr(x.s.f);
        pr(x.s.s);
    }*/
    for(auto x: bounds){
        if(x.f == 0) continue;
       // cout << x.f<<" bounds" << endl;
        int bef = m[cur-1];
        int now = x.f;
       // pr(bounds[bef].f);
       // pr(bounds[bef].s);
        dp[cur][0] = dp[cur-1][0] + dist(bounds[bef].f, bounds[now].s) + dist(bounds[now].s, bounds[now].f);
        dp[cur][0] = min(dp[cur][0], dp[cur-1][1] + dist(bounds[bef].s, bounds[now].s) + dist(bounds[now].s, bounds[now].f));
        dp[cur][1] = dp[cur-1][0] + dist(bounds[bef].f, bounds[now].f) + dist(bounds[now].f, bounds[now].s);
        dp[cur][1] = min(dp[cur][1], dp[cur-1][1] + dist(bounds[bef].s, bounds[now].f) + dist(bounds[now].f, bounds[now].s));
        cur++;
    }
//    cout << dp[1][0] << " here"<< endl;
    cur--;
    cout << min(dp[cur][0], dp[cur][1]) << endl;
    return 0;
}