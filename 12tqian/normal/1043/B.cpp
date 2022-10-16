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
vi a;
vi x;
vi ans;
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        int d;
        cin >> d;
        a.eb(d);
    }
    f0r(i, n){
        if(i == 0){
            x.eb(a[i]);
        }
        else{
            x.eb(a[i] - a[i-1]);
        }
    }
    f1r(k, 1, sz(x)+1){
        bool isTrue = true;
        f0r(i, sz(x)){
            if(i>k-1){
                if(x[i] != x[i-k]){
                    isTrue =false;
                    break;
                }
            }
        }
        if(isTrue){
            ans.eb(k);
        }
    }
    cout << sz(ans) << endl;
    f0r(i, sz(ans)){
        cout << ans[i] << " ";
    }
    return 0;
}