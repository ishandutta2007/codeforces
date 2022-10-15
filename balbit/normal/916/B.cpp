#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i = n-1; i>=0; i--)
#define pii pair<int, int>
#define f first
#define s second
#define SZ(x) (int)(x.size())
#define ALL(x) x.begin(),x.end()
#define MN(a,b) a = min(a, (__typeof__(a))(b))
#define MX(a,b) a = max(a, (__typeof__(a))(b))
#ifdef BALBIT
#define bug(...) fprintf(stderr,"Line %d (%s) = ",__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template <typename T> void _do(T &&x) {cerr<<x<<endl;}
template <typename T, typename ... S> void _do(T&&x, S && ... y) {cerr<<x<<", "; _do(y...);}
#define IOS() 
#else
#define bug(...)
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#endif


ll gcd(ll a, ll b){
    if (a%b==0) return b;
    return gcd(b, a%b);
}

const int maxn = 2e5+5;
#define int ll

signed main(){
    IOS();
    vector<ll> hv(128);
    int n; cin>>n;
    int k; cin>>k;
    int B = 64;
    REP(i,64) {
        if (n & (1ll<<i)){
            hv[B+i]++; 
            k--;
            bug(k);
        }
    }
    bug(k);
    if (k<0) {
        cout<<"No\n"; return 0;
    }
    RREP(i,128){
        if (hv[i] == 0) continue;
        if (hv[i] <= k){
            k -= hv[i]; hv[i-1] += hv[i] * 2; hv[i]=0;
        }else{
            break;
        }
        bug(i,k);
    }
    int it = -1000;
    if (k){
        REP(i, 128){
            if (hv[i]) {
                it = i; hv[i]--; break;
            }
        }
    }
    
    

    cout<<"Yes\n";
    RREP(i,128){
        REP(j, hv[i]) {
            cout<<i-B<<' ';
        }
    }
    if (it!=-1000){
        REP(i, k){
            cout<<it-i-1-64<<' ';
        }
        cout<<it-k+1-1-64<<' ';
    }
}