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
const int MAX =1e6 + 6;
ll cnt [MAX];
int main(){
    fast_io();
    string s;
    getline(cin, s);
    int n = sz(s);
    f0r(i, n){
        if(i == 0){
            if(s[i] == 'v'){
                cnt[i] = 0;
            }
        }
        else{
            if(s[i] == 'v' && s[i-1] == 'v'){
                cnt[i] = cnt[i-1] + 1;
            }
            else{
                cnt[i] = cnt[i-1];
            }
        }
    }
    ll tot = 0;
    f1r(i,1,  n){
        if(s[i] == 'v' && s[i-1] == 'v'){
            tot += 1;
        }
    }
    ll ans = 0;
    f0r(i, n){
        if(s[i] == 'o'){
            ll x = cnt[i];
            ll y = tot - cnt[i];
            ans += x*y;
        }
    }
    cout << ans << endl;
    return 0;
}