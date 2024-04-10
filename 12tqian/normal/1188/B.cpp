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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

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
const int MAX = 3e5 + 5;
ll n, p;
ll four(ll x){
    ll val = (x*x)%p;
    return (val*val)%p;
}
ll a [MAX];
ll b[MAX];
map<int, vi> m;
map<int, int> um;
int main(){
    fast_io();
    int k;
    cin >> n >> p >> k;
    f0r(i, n) cin >> a[i];
    f0r(i, n){
        b[i] = four(a[i]) - k*a[i];
        b[i] %= p;
        b[i] = (b[i] +p)%p;
    }
    f0r(i, n){
        m[(int) a[i]].eb(b[i]);
    }
    ll ans = 0;
    for(auto x: m){
        ll val = x.f;
        ll num = sz(x.s);
        ll tmp = (val)*val;
        tmp%= p;
        tmp *= val;
        tmp %= p;
        tmp *= 4;
        tmp%= p;
        if(tmp == k){
            ans += (num*(num-1))/2;
        }
        for(ll i : x.s){
            ans += um[i];
        }
        for(ll i: x.s){
            um[i]++;
        }
    }
    cout << ans << endl;
    return 0;
}