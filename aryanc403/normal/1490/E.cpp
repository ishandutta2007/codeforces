/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 

#define int ll

using namespace std;

const int N = 3e5 +5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

void solve()
{
    int n;
    cin >> n ;
    vector<pii> a(n);
    rep(i , n){
        a[i].ss = i;
        cin >> a[i].ff;
    }

    sort(all(a));
    vector<int>pre(n);

    rep(i , n){
        pre[i] = a[i].ff;
        if(i) pre[i] += pre[i - 1];
    }

    repD(i , n - 1 , 0){
        if(i + 1 < n){
            if(pre[i] < a[i + 1].ff){
                cout << (n - i - 1) << '\n';
                vector<int> v;
                rep(j , n - i - 1){
                    v.pb(a[i + 1 + j].ss + 1);
                    // cout << a[i + 1 + j].ss + 1 << ' ';
                }
                sort(all(v));
                for(int x : v) cout << x << ' ' ;
                return;
            }
        }
    }

    // int r = n, l = n - 1;

    // while(l >= 0){
    //     while(l >= 0 && a[l] == a[r - 1])
    //         --l;
    //     l++;

    //     // [l. r) is range of current values
    // }

    cout << n << '\n';
    rep(i , n) cout << i + 1 << ' ' ;

}   

     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}