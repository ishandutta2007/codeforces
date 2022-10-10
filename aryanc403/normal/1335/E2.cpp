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

// #define int ll

using namespace std;

const int N = 2e5 +5 ;
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



int n;
int a[N];
int cnt[N][200];

int mx(int c){
    int ans = 0;
    int l = -1, r = n, cur = 0; 
    while(l < r){

        // cout << l << ' ' << r << ' ' << cur << ' ' << c << '\n';
        rep(i, 200){
            if(i != c){
                // find occurences from [l + 1, r - 1]
                int L = l + 1, R = r - 1;                
                int midcnt = 0;
                if(L <= R){
                    midcnt = cnt[R][i] - (L? cnt[L - 1][i] : 0);
                }

                ans = max(ans, cur + midcnt + cur);
            }
        }

        // update.

        while(l < n){
            l++;
            if(a[l] == c)
                break;
        }

        while(r >= 0){
            --r;
            if(a[r] == c)
                break;
        }

        if(l < r)
            cur++;
        else
            break;

    }

    return ans;
}   

void solve()
{
    cin >> n;

    int res = 0;
    rep(i , n + 1) rep(j , 200) cnt[i][j] = 0;
    rep(i , n){
        cin >> a[i], --a[i];
        cnt[i][a[i]]++;
        if(i)
            rep(j , 200)
                cnt[i][j] += cnt[i-1][j];
    }

    rep(i , 200){
        res = max(res, mx(i));
    }

    cout << res;

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