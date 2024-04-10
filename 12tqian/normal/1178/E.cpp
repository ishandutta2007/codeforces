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
deque<int> a;
vi res;
int main(){
    fast_io();
    string s;
    getline(cin, s);
    int n = sz(s);
    f0r(i, n){
        a.pb(s[i] - 'a');
    }
    while(sz(a) >= 4){
        if(a[0] == a[sz(a) - 1]){
            res.eb(a[0]);
            a.pop_front();
            a.pop_back();
            continue;
        }
        if(a[0] == a[sz(a) -2]){
            res.eb(a[0]);
            a.pop_front();
            a.pop_back();
            a.pop_back();
            continue;
        }
        if(a[1] == a[sz(a) - 2]){
            res.eb(a[1]);
            a.pop_front();
            a.pop_back();
            a.pop_front();
            a.pop_back();
            continue;
        }
        if(a[1] == a[sz(a) - 1]){
            res.eb(a[1]);
            a.pop_front();
            a.pop_back();
            a.pop_front();
            continue;
        }

    }
    int mid = -1;
    if(sz(a) == 1){
        mid = (a[0]);
    }
    else if(sz(a) == 2){
        if(a[0] == a[1]){
            res.eb(a[0]);
        }
        else{
            mid = a[0];
        }
    }
    else if(sz(a) == 3){
        if(a[0] == a[2]){
            res.eb(a[0]);
            mid = a[1];
        }
        else if(a[1] == a[2]){
            res.eb(a[1]);
        }
        else if(a[0] == a[1]){
            res.eb(a[0]);
        }
        else{
            mid = a[0];
        }
    }
    vi fin;
    for(int x: res){
        fin.eb(x);
    }
    if(mid != -1)
        fin.eb(mid);
    for(int i = sz(res) - 1; i>= 0; i--){
        fin.eb(res[i]);
    }
    if(sz(res)*2 + (mid== -1? 0: 1)>=n/2){
        string ans = "";
        f0r(i, sz(fin)){
            ans += (fin[i]+ 'a');
        }
        cout << ans << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}