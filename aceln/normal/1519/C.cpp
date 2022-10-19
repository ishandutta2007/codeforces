#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int a[maxn],b[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<vector<ll> > v(n,vector<ll>(0));
        ll anss=0;
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) cin>>b[i],anss+=b[i];

        for (int i=0;i<n;i++) v[a[i]-1].pb(b[i]);
        sort(all(v),[&](vector<ll> aa,vector<ll> bb) {
            return sz(aa) > sz(bb);
        });

        for (int i=0;i<n;i++){
            sort(all(v[i]));
            for (int j=1;j<sz(v[i]);j++) v[i][j]+=v[i][j-1];
        }

        int B=sqrt(n);
        for (int i=1;i<=n;i++) {
            if (i<=B) {
                ll ans=anss;
                for (int j=0;j<n;j++)  {
                    ans-= (sz(v[j])%i==0 ? 0LL : v[j][sz(v[j])%i - 1]);
                }
                cout<<ans<<' ';
            }
            else {
                ll ans = 0;
                for (int j=0;j<min(B+3,n);j++)  {
                    if (sz(v[j])==0) continue;
                    //cout<<i<<' '<<j<<endl;
                    ans += v[j][sz(v[j])-1];
                    //cout<<i<<' '<<j<<endl;
                    ans-= (sz(v[j])%i==0 ? 0LL : v[j][sz(v[j])%i - 1]);
                }
                cout<<ans<<' ';
            }

        }
        cout<<'\n';
    }
}