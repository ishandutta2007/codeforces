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
int n;
ll diff(vector<ll> x){
    ll mn = 1e9;
    ll mx = 0;
    f0r(i, n){
        mn = min((ll)x[i], mn);
        mx = max((ll)x[i], mx);
    }
    return mx - mn;
}
int main(){
    fast_io();
    cin >> n;
    vector<ll> a;
    vector<ll> c;
    f0r(i, 2*n){
        ll ai;
        cin >> ai;
        c.eb(ai);
    }
    vector<ll> b;
    sort(all(c));
    f0r(i, n){
        a.eb(c[i]);
    }
    f1r(i, n, 2*n){
        b.eb(c[i]);
    }
    ll ans = diff(a)*diff(b);
    f1r(i, 1, n){
        ll x = (c[2*n-1]- c[0]);
        x = x* (c[i + n-1] - c[i]);
        ans = min(ans, x);
    }
    cout << ans << endl;

    return 0;
}