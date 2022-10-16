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
const int MAX = 1e5 +5;
ll b[MAX];
ll g[MAX];
vector<ll> girls;
vector<ll> boys;
int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    f0r(i, n) cin>> b[i];
    f0r(i, m) cin >> g[i];
    ll mn = 1e18;
    ll mx = 0;
    f0r(i, n){
        mx = max(b[i], mx);
    }
    f0r(i, m){
        mn  = min(g[i], mn);
    }
    if(mn<mx){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    f0r(i, n){
        ans += (m)*b[i];
    }
    f0r(i,m ) ans += g[i];
    int num = m;
    f0r(i, n) boys.eb(b[i]);
    f0r(i, m) girls.eb(g[i]);
    sort(all(girls));
    sort(all(boys));
    reverse(all(boys));
    while(num>0){
        if(sz(boys) == 0){
            cout << -1 << endl;
            return 0;
        }
        if(mx == mn){
            ans -= m*boys[0];
            break;
        }
        if(num>= m-1){
            ans -= (m-1)*boys[0];
            num -= m-1;
            boys.erase(boys.begin());
        }
        else{
            ans -= num*boys[0];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}