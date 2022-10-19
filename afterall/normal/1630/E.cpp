#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+10;
int mod=998244353;
int fac[N];
int fm[N];
vector <int> p[N];
int cnt[N];
int T[N];
int ans[N];
int power(int n,int k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
int c2(int n){
    return 1ll * n*(n-1)/2%mod;
}
vector <int> a;
int hal(int n,int id){
    ll z=0;
    for (int i=0;i<a.size();i++){
        z+=c2(a[i]/id);
    }
    z%=mod;
    z=c2(n)-z;
    z+=mod;
    z%=mod;
    ll x=z;
    z=z*power(c2(n),mod-2)%mod*n%mod;
    T[n]=fac[n];
    for (int i=0;i<a.size();i++) T[n]=1ll* T[n]*fm[a[i]/id]%mod;
    z*=T[n];
    z%=mod;
    return z;
}
void Main(){
    int n;
    cin >> n;

    a.clear();
    for (int i=0;i<=n;i++) cnt[i]=0,ans[i]=0,T[i]=0;
    for (int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    int g=0;
    vector <int> b;
    for (int i=1;i<=n;i++){
        if (cnt[i]>0){
            g=__gcd(g,cnt[i]);
            b.pb(cnt[i]);
        }
    }
    a=b;
    vector <int> p;
    for (int i=1;i<=g;i++){
        if (g%i==0) p.pb(i);
    }
    for (auto u : p){
        ans[n/u]=1ll * hal(n/u,u)*u%mod;
    }

        reverse(p.begin(),p.end());
        for (int i=0;i<p.size();i++){
            for (int j=0;j<i;j++){
                if (p[j]%p[i]==0){
                    ans[n/p[i]]-=ans[n/p[j]];
                    if (ans[n/p[i]]<0) ans[n/p[i]]+=mod;
                    
                    T[n/p[i]]-=T[n/p[j]];
                    if (T[n/p[i]]<0) T[n/p[i]]+=mod;
                    
                }
            }
        }
        reverse(p.begin(),p.end());
    
    if (g==n){
        cout << 1 << endl;
        return ;
    }
    ll jav=0;
    ll P=0;
    for (int i=1;i<=n;i++) jav+=1ll * ans[i]*power(i,mod-2)%mod,P+=1ll * T[i]*power(i,mod-2)%mod;
        cout << jav%mod*power(P%mod,mod-2)%mod << endl;


}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    fac[0]=1;
    fm[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    
    while(t--) Main();
}