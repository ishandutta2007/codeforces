#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
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
struct node {
    int val = 0, lazy = 0;
    node* c[2];

    void push(int L, int R) {
        if (!lazy) return;
        val += (R-L+1)*lazy;

        if (c[0]) {
            c[0] = new node(*c[0]);
            c[0]->lazy += lazy;
        }

        if (c[1]) {
            c[1] = new node(*c[1]);
            c[1]->lazy += lazy;
        }

        lazy = 0;
    }

    int query(int low, int high, int L, int R) {
        if (low <= L && R <= high) return val+lazy*(R-L+1);
        if (R < low || high < L) return 0;
        int M = (L+R)/2;
        return lazy*(min(high,R)-max(L,low)+1)+c[0]->query(low,high,L,M)+c[1]->query(low,high,M+1,R);
    }

    void upd(int low, int high, int v, int L, int R) {
        push(L,R);
        if (low <= L && R <= high) {
            lazy = v; push(L,R);
            return;
        }
        if (R < low || high < L) return;

        int M = (L+R)/2;
        c[0] = new node(*c[0]), c[1] = new node(*c[1]);
        c[0]->upd(low,high,v,L,M);
        c[1]->upd(low,high,v,M+1,R);
        val = c[0]->val+c[1]->val;
    }

    void build(vi& arr, int L, int R) {
        if (L == R) {
            if (L < (int)arr.size()) val = arr[L];
            else val = 0;
            return;
        }
        int M = (L+R)/2;
        c[0] = new node();
        c[0]->build(arr,L,M);
        c[1] = new node();
        c[1]->build(arr,M+1,R);
        val = c[0]->val+c[1]->val;
    }
};

template<int SZ> struct pers {
    node* loc[SZ+1]; // stores location of root after ith update
    int nex = 1;

    pers() { loc[0] = new node(); }

    void upd(int low, int high, int val) {
        loc[nex] = new node(*loc[nex-1]);
        loc[nex]->upd(low,high,val,0,SZ-1);
        nex++;
    }
    void build(vi& arr) {
        loc[0]->build(arr,0,SZ-1);
    }
    int query(int ti, int low, int high) {
        return loc[ti]->query(low,high,0,SZ-1);
    }
};
const int MAX = 1e5+5;
pers<MAX> p;
vi a;
vi type[MAX];
int pos[MAX];
vi init;
int main(){
    int n, k;
    cin >> n >> k;
    f0r(i, n){
        int ai;
        cin >> ai;
        a.eb(ai);
        pos[i] = sz(type[a[i]]);
        if(pos[i]<k){
            init.eb(1);
        }
        else{
            init.eb(0);
        }
        type[a[i]].eb(i);
    }
    p.build(init);
    f0r(i, n){
        if(pos[i] + k < sz(type[a[i]])){
            p.upd(type[a[i]][pos[i]+k], type[a[i]][pos[i]+k], 1);
        }
        else{
            p.upd(0, 0, 0);
        }
    }
    int last = 0;
    int q;
    cin >> q;
    f0r(i, q){
        int xi, yi;
        cin >> xi;
        cin >> yi;
        xi = (xi + last)%n;
        yi = (yi + last)%n;
        if(xi> yi){
            swap(xi, yi);
        }
        last = p.query(xi, xi, yi);
        cout << last << endl;

    }
    return 0;
}