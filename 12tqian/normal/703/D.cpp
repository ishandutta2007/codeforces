#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<ll>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) ll a; scanf("%d", &a)
#define read2(a,b) ll a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) ll a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) ll arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define prll1(a) prllf("%d \n", a)
#define prll2(a, b) prllf("%d %d \n", a, b)
#define prll3(a, b, c) prllf("%d %d %d \n", a, b, c)
#define prll(v) for (ll i : v) { prllf("%d ", i); } prllf("\n")

#define debug prllf("asdf\n");
#define newl prllf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
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
const ll MAX = 1000004; //max number of nodes
int ans [MAX];
int prefix[MAX];
int last [MAX];
vi a;
vector<pii> queries [MAX];
//to build, update each element by value to build in n log n
int bit[MAX];
//To change operation from +, just change + to that operation
//and the - to the inverse
//update the ith elements by x
//comment out the first lines of each function to start BIT at 0 and change query
void update(int i, int x){
    for( ; i<MAX; i += i & -i)
        bit[i] ^= x;
}
//sum to the ith element
int query(int i){
    int sum = 0;
    for( ; i>0; i -= i&-i){
        sum ^= bit[i];
    }
    return sum;
}

int main(){
    fast_io();
    int n;
    cin >> n;

    f0r(i, n){
        ll d;
        cin >> d;
        a.emplace_back(d);
    }
    prefix[0] = 0;
    f0r(i, n){
        prefix[i+1] = prefix[i] ^a[i];
    }
    ll q;
    cin >> q;
    f0r(i, q){
        int l, r;
        cin >> l>> r;
        queries[l].eb(mp(r, i));
    }
    map<int, int> in;
    for(int i =n -1; i>= 0; i--){
        if(in.count(a[i])){
            update(in[a[i]], a[i]);
        }
        in[a[i]] = i+1;
        update(in[a[i]], a[i]);
        for(auto x: queries[i+1]){
            int l = i+ 1;
            int r = x.f;
            int index = x.s;
            ans[index] = prefix[l-1]^prefix[r] ^query(r);
        }
    }
    f0r(i, q){
        cout << ans[i] << endl;
    }
    return 0;
}