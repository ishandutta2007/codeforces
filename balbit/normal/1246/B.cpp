#include <bits/stdc++.h>
 
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl
 
using namespace std;
 
// #define int ll
 
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
 
 
void GG(){cout<<"No\n"; exit(0);}
 
ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}
 
ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}
 
const int maxn = 1e5+5;
 
 
 
main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    vector<int> ap(100005);
    vector<int> other(100005);
    int n; cin>>n; int k; cin>>k; bool tb = 0; if (k>=33) tb = 1;
    k = min(k,33);
    vector<int> a(n);
    vector<ll> out;
    vector<ll> pl;
    for (ll i=2; i<=10000000000; i++){
        ll mo = pow(i,k);
        if (mo>10000000000) break;
        out.pb(mo);
        if (mo<=100000) pl.pb(mo);
    }
    REP(i,n){
        cin>>a[i];
        RREP(j,SZ(pl)) {
            if (a[i]%pl[j]==0) a[i]/=pl[j];
        }
        // bug(a[i]);
        ap[a[i]]++;
        if (k==3){
            if (other[a[i]]) continue;
            other[a[i]]=1;
            ll tmp = a[i];
            FOR(j,2,1+sqrt(a[i])){
                int nat = 0;
                while (tmp%j==0) tmp/=j, nat++;
                if (nat==1) other[a[i]] *=(ll)j*j;
                if (nat==2) other[a[i]] *=j;
            }
            if (tmp) other[a[i]] *= tmp*tmp;
        }
        // bug(a[i]);
        
    }
    ll re = 0;
    FOR(i,1,100005){
        if (ap[i]==0) continue;
        if (i==1){
            re += (ll)ap[i] * (ap[i]-1) /2; continue;
        }
        if (tb) break;
        if (k>3){
            REP(j,SZ(out)){
                if (out[j]%i==0){
                    ll oth = out[j]/i;
                    if (oth<i) re += (ll)ap[oth] * ap[i];
                    if (oth==i) re += (ll)ap[i] * (ap[i]-1) /2;
                    break;
                }
            }
        }else if (k==2){
            re += (ll)ap[i] * (ap[i]-1) /2;
        }else{
            ll oth = other[i];
            if (oth<i) re += (ll)ap[oth] * ap[i];
            if (oth==i) re += (ll)ap[i] * (ap[i]-1) /2;
        }
        
    }
    cout<<re<<endl;
    
}