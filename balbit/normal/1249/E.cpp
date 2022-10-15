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
#define debug(...)
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#endif


ll gcd(ll a, ll b){
    if (a%b==0) return b;
    return gcd(b, a%b);
}

const int maxn = 2e5+5;
int a[maxn], b[maxn];
int x[maxn], y[maxn];

int main(){
    IOS();
    int n, c; cin>>n>>c;
    cout<<"0 ";

    REP(i,n-1) cin>>x[i];
    REP(i,n-1) cin>>y[i];
    b[0]=c;
    REP(i,n-1){
        b[i+1] = min(b[i] + y[i], a[i] + y[i] + c);
        a[i+1] = min(a[i] + x[i], b[i+1]);
        cout<<a[i+1]<<' ';
    }
}