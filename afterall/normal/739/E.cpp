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
const int N=2e3+100;
ld p[N];
ld u[N];
ld val[N];
bool W[N];
ld E[N];
int32_t main(){
    sync;
    ll n,a,b;
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++){
        cin >> p[i];
    }
    for (int i=1;i<=n;i++){
        cin >> u[i];
    }
    ld l=0,r=2;
    vector <pair <ld,ll> > c;
    for (int tt=0;tt<100;tt++){
        c.clear();
        ld mid=(l+r)/(ld)2;
        for (int i=1;i<=n;i++){
            val[i]=max(1.-(1.-p[i])*(1.-u[i])-mid,u[i]);
            if (val[i]!=u[i]) W[i]=1;
            else W[i]=0;
            E[i]=max((ld)0,p[i]-mid);
        }
        for (int i=1;i<=n;i++){
            c.pb({val[i]-E[i],i});
        }
        sort(c.begin(),c.end());
        reverse(c.begin(),c.end());
        ll cnt=0;
        for (int i=0;i<b;i++){
            if (W[c[i].S]) cnt++;
        }
        for (int i=b;i<n;i++){
            if (E[c[i].S]!=0.){
                cnt++;
            }
        }
        if (cnt<=a) r=mid;
        else l=mid;
    }
    ld ans=0;
    for (int i=0;i<b;i++) ans+=val[c[i].S];
    for (int i=b;i<n;i++) ans+=E[c[i].S];
    ans+=r*a;
    cout << fixed << setprecision(10) << ans << endl;
}