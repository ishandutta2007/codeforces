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
const int MAXK = 25;
const int MAXN = 1e5+5;
const ll INF = 1e18;
ll dp[MAXK][MAXN];
ll cnt[MAXN];
const int SZ = 1<<20;

Tree loc [MAXN];

ll calc(int l, int r){
    if(l>r) swap(l, r);
    int ret = 0;
    f1r(st, l, r+1){
        f1r(ed, st+1, r+1){
            if(a[st]== a[ed]) ret++;
        }
    }
    return ret;
}
ll same(int i, int l, int r){
    ///finds how many a[i] are in range [l, r]
    return loc[a[i]].order_of_key(r+1) - loc[a[i]].order_of_key(l);
}
ll cur = 0;
int le = -1;
int ri = -1;
void dnc(int k, int l, int r, int lo, int hi) {
    if (l > r) return;
    int m = (l + r) >> 1;
    int best = lo;
    dp[k][m] = 1e18;
    ///make sure the cur is set to calc(lo, m);
    while(ri<m){
        ri++;
        cur += cnt[a[ri]];
        cnt[a[ri]]++;
    }
    while(le>lo){
        le--;
        cur += cnt[a[le]];
        cnt[a[le]]++;
    }
    while(ri>m){
        cnt[a[ri]]--;
        cur -= cnt[a[ri]];
        ri--;
    }
    while(le<lo){
        cnt[a[le]]--;
        cur -= cnt[a[le]];
        le++;
    }
    for(int i = lo; i<= min(m-1, hi); i++){
        cnt[a[le]]--;
        cur -= cnt[a[le]];
        le++;
        if(dp[k-1][i] == INF) continue;
        if(i >  hi){
            continue;
        }
        ll now = cur + dp[k-1][i];

       // now = calc(i+1, m) + dp[k-1][i];
        if (now < dp[k][m]) {
            best = i;
            dp[k][m] = now;
        }
    }
    dnc(k, l, m-1, lo, best);
    dnc(k, m+1, r, best, hi);
}
int main(){
    fast_io();
    int n, k;
    cin >> n >> k;
    f0r(i, n){
        int ai; cin >> ai;
        ai--;
        a.eb(ai);
        loc[ai].insert(i);

    }
    f1r(i, 1, k+1){
        f0r(j, n){
            dp[i][j] = 1e18;
        }
    }
    f0r(i, n){
        cnt[i] = 0;
    }
    cur = 0;
    f0r(i, n){
        cur += cnt[a[i]];
        cnt[a[i]]++;
       // assert(cur == calc(0, i));
        dp[1][i] = cur;
    }
    f1r(i, 2, k+1){
        f0r(i, n){
            cnt[i] = 0;
        }
        cur = 0;
        f0r(i, n){
            cur += cnt[a[i]];
            cnt[a[i]]++;
        }
      //  cout << cur << endl;
        le = 0;
        ri = n-1;
     //   assert(calc(le, ri) == cur);
        dnc(i, 0, n-1, 0, n-1);
    }
    ll ans = 1e18;
    f0r(i, n) cnt[i] = 0;
    cur = 0;
    for(int i = n-1; i>=0; i--){
        if(i+1<n){
            cur += cnt[a[i+1]];
            cnt[a[i+1]]++;
        }
        if(i != n-1){
            ans = min(ans, dp[k-1][i] + cur);
        }
        else{
            ans = min(ans, dp[k][i]);
        }
    }
    cout << ans << endl;
    return 0;
}