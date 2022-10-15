#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i<n; ++i)
#define REP1(i,n) for(int i = 1; i<=n; ++i)

#define SZ(x) (int)(x).size()
#define pb push_back

#define ll long long

// #define BALBIT

#ifdef BALBIT
#define bug(...) cout<<"#"<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template <typename T > void _do(T &&x){cout<<x<<endl;}
template <typename T, typename ...S> void _do(T &&x, S && ...y){cout<<x<<", "; _do(y...);}
#else // BALBIT
#define bug(...)
#endif

#define IOS() ios::sync_with_stdio(0), cin.tie(0)

const int maxn = 1e5+5;
const int BS = 500;
const ll mod = 998244353;
int cnt[maxn/BS+10][maxn*3], shift[maxn/BS+10];
vector<int>last[maxn];
ll dp[maxn], at[maxn]; // cnt[i] corresponds to i + shift[this block]
int re = 1;
int K;

inline void sub(int &a, int b) {
    a = a-b<0?a-b+mod:a-b;
}
inline void add(int &a, int b) {
    a = a+b>=mod?a+b-mod:a+b;
}

void updpt(int x, int dir) { // dir is 1 or -1
    int B = x/BS;
    bug(x, dir, re);
    sub(cnt[B][at[x]+maxn], dp[x]);
    if(dir == 1 && at[x] + shift[B] == K) {
        sub(re, dp[x]);
    }
    at[x] += dir;
    add(cnt[B][at[x]+maxn], dp[x]);
    if(dir == -1 && at[x] + shift[B] == K) {
        add(re, dp[x]);
    }
    bug(re);
}

void updchunk(int B, int dir) {
    if (dir == 1) {
        sub(re, cnt[B][K - shift[B] + maxn]);
        shift[B] += dir;
    }
    else{
        shift[B] += dir;
        add(re, cnt[B][K-shift[B] + maxn]);
    }
}

void chg(int l, int r, int dir) {
    int j=l;
    for( j = l; j%BS != 0 && j <= r; ++j) {
        updpt(j, dir);
    }
    for(; j+BS-1 <= r; j += BS) {
        updchunk(j/BS, dir);
    }
    for(; j<=r; ++j) {
        updpt(j,dir);
    }
}

signed main(){
    IOS();
    int n; cin>>n>>K; //++K;
    REP(i,n) last[i].pb(0);
    cnt[0][0 + maxn] = 1;
    re = 1;
    dp[0]=1;
    REP1(i,n) {

        int a; cin>>a; --a;
        chg(last[a].back(), i-1, 1);
        if (SZ(last[a]) > 1) {
//            assert(0);
            chg(last[a][SZ(last[a])-2], last[a].back()-1, -1);
        }
        dp[i]=re;
        last[a].pb(i);
        at[i] = 0 - shift[i/BS];
        add(cnt[i/BS][at[i]+maxn],dp[i]);
        add(re, dp[i]);
        REP(j,i+1) {
            bug(j, at[j]);
        }
        bug(i, dp[i]);
        //cout<<i<<' '<<re<<' '<<dp[i]<<endl;
//        re+=dp[i];
    }
    cout<<dp[n]<<endl;
}