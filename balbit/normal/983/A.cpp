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

int main(){
    IOS();
    int T; cin>>T;
    while (T--){
        ll p, q, b; cin>>p>>q>>b;
        ll g = gcd(p,q);
        q/=g;
        ll x = gcd(q,b);
        while (x!=1){
            while (q%x==0) q/=x;
            x = gcd(q,b);
        }
        if (q!=1) cout<<"Infinite"<<endl;
        else cout<<"Finite"<<endl;
    }
}