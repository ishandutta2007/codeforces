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
vi a;
template<class T, int SZ> struct ORQ {
    T stor[SZ][32-__builtin_clz(SZ)];

    T comb(T a, T b) {
        return (a|b);
    }

    void build(vector<T>& x) {
        for(int i = 0; i<x.size(); i++){
            stor[i][0] = x[i];
        }
        for(int j = 1; j<32 - __builtin_clz(SZ); j++){
            for(int i = 0; i< SZ - (1<<(j-1)); i++){
                stor[i][j] = comb(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
            }
        }
    }

    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};
template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];

    T comb(T a, T b) {
        return max(a,b);
    }

    void build(vector<T>& x) {
        for(int i = 0; i<x.size(); i++){
            stor[i][0] = x[i];
        }
        for(int j = 1; j<32 - __builtin_clz(SZ); j++){
            for(int i = 0; i< SZ - (1<<(j-1)); i++){
                stor[i][j] = comb(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
            }
        }
    }

    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};
RMQ<int, (1<<18)> rmq;
ORQ<int, (1<<18)> orq;




int bin(int left, int l, int r, int x){
    while(abs(l - r) >1){
        int m = (l + r)/2;
        if(orq.query(left, m)>x){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    int tmp = min(l, r);
    r = max(l, r);
    l = tmp;
    if(orq.query(left, l)>x){
        return l;
    }
    if(orq.query(left, r)> x){
        return r;
    }
    return -1;
}
int maxSearch(int left, int l, int r, int x){
    while(abs(l - r) > 1){
        int m = (l + r)/2;
        if (rmq.query(left, m) < x){
            l = m;
        }
        else{
            r = m- 1;
        }
    }
    int tmp = min(l, r);
    r = max(l, r);
    l = tmp;
    if(rmq.query(left, r)< x){
        return r;
    }
    if(rmq.query(left, l)< x){
        return l;
    }
    return -1;
}
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        int ai;
        cin >> ai;
        a.eb(ai);
    }
    rmq.build(a);
    orq.build(a);
    ll ans = 0;
    f0r(i, n){
        int cur = a[i];
        int nxt = bin(i, i, n-1, cur);
        int prev = i;
        while(nxt != -1){
            assert(orq.query(i, prev) == orq.query(i, nxt - 1));
            cur = orq.query(i, nxt-1);
            int idx = maxSearch(i, prev, nxt-1, cur);
           // cout << i << " " << prev << " " << nxt << " " <<  idx << " " << cur  << endl;

            if(idx != -1 && rmq.query(i, idx)<orq.query(i, idx)){
              //  assert(rmq.query(i, idx)<orq.query(i, idx));
                ans += (idx - prev +1);
                if(prev == i){
                    ans -= 1;
                }

            }
            prev = nxt;
            nxt = bin(i, i, n-1, orq.query(i, nxt));
        }
        cur = orq.query(i, n-1);
        assert(orq.query(i, prev) == orq.query(i, n - 1));
        int idx = maxSearch(i, prev, n-1, cur);
       // cout << i << " " << prev << " " << n-1 << " " <<  idx << " " << cur <<  endl;
        if(idx != -1 &&rmq.query(i, idx)<orq.query(i, idx)){
           // assert();
            ans += (idx - prev + 1);
            if(prev == i){
                ans -= 1;
            }
        }
        //cout << ans << endl;

    }
    cout <<  ans << endl;
    return 0;
}