#include <bits/stdc++.h>

using namespace std;

#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define np(v) next_permutation(v.begin(), v.end())
#define pll pair < long long, long long>
#define all(a) a.begin(), a.end()
#define ull unsigned long long
#define vll vector <long long>
#define pii pair < int, int >
#define sz(a) (int)a.size()
#define sqr(x) ((x) * (x))
#define y1 stupid_cmath
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second

const int inf = (int)1e9 + 100;
const int mod = (int)1e9 + 7;
const double eps = 1e-9;
const int MaxN = 2e5 + 1;
const double pi = acos(-1.0);
ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res *= a,res%=mod;
		a *= a,a%=mod;
		n >>= 1;
	}
	return res;
}
ll n,m,k,x,y,d,maxx,q,cnt,ans;
int p[MaxN], lp[2000010];
pair<int,int> a[2000010];
int main(){
   // ios_base::sync_with_stdio(0), cin.tie(0);
    n=2000000;
    vector<int> pr;
    for(int i=2;i<=n;i++){
        if(lp[i]==0){
            lp[i]=i;
            pr.pb(i);
        }
        for(int j=0;j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n;j++)
            lp[i*pr[j]] = pr[j];
    }
    cin>>n;
    for(ll i=0;i<n;i++)cin>>p[i];
    sort(p,p+n);
    reverse(p, p+n);
    for(ll i=0;i<n;i++){
        x=p[i];
        if(!a[x].f)a[x]=mp(1,1);
        else {
            x--,p[i]--,cnt=1;
            while(lp[x]){
                if(lp[x]==lp[x/lp[x]])cnt++;
                else {
                    if(cnt>a[lp[x]].f)a[lp[x]]=mp(cnt,1);
                    else if(cnt==a[lp[x]].f)a[lp[x]].s++;
                    cnt=1;
                }
                x/=lp[x];
            }
        }
    }
    ans=1;
    for(ll i=2;i<=2e6;i++)
        ans=(ans*binpow(i,a[i].f))%mod;
    for(ll i=0;i<n;i++){
        x=p[i];
        bool ok=true;
        cnt=1;
        while(lp[x]){
                if(lp[x]==lp[x/lp[x]])cnt++;
                else {
                    if(cnt==a[lp[x]].f&&a[lp[x]].s==1){
                        ok=false;
                        break;
                    }
                    cnt=1;
                }
                x/=lp[x];
        }
        if(ok)return cout<<(ans+1)%mod, 0;
    }
    cout<<ans;
}