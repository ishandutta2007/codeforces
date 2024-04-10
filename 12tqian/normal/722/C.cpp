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

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }

#define debug printf("asdf\n");
#define newl printf("\n");
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
vector<ll> a;
vector<ll> ans;
vi order;
const int MAX = 1e5 + 5;
ll p[MAX];
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        ll d;
        cin>> d;
        a.eb(d);
        if(i == 0){
            p[i] = d;
        }
        else{
            p[i] = p[i-1] + d;
        }
    }
    f0r(i, n){
        int d;
        cin >> d;
        d--;
        order.eb(d);
    }
    reverse(all(order));
    set<int, less<int>> s1;
    set<int, greater<int>> s2;
    f0r(i, n){
        s2.insert(i);
        s1.insert(i);
    }
    ll mx = 0;
    f0r(i, n){
        ans.eb(mx);
        int idx = order[i];
        s1.erase(idx);
        s2.erase(idx);
        set<int>::iterator it1= (s1.ub(idx));
        set<int>::iterator it2 = (s2.ub(idx));

        int l, r;
        if(it1 == s1.end()){
            r = n;
        }
        else{
            r = *it1;
        }
        if(it2 == s2.end()){
            l = -1;
        }
        else{
            l = *it2;
        }
        l++;
        r--;
       // cout << l << " sd " << r << endl;;
        mx = max(mx, p[r] - p[l] + a[l]);
    }
    reverse(all(ans));
    for(ll i: ans){
        cout << i << endl;
    }
    return 0;
}