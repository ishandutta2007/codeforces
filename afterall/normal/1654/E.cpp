#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=1e5+100,sq=350;
int a[N];
int A[N];

map <int,int> mp[N];
ll X=0;
int solve(ll n){
    X++;
    for (int i=1;i<=n;i++) A[i]=a[i];
    ll ans=1;

    for (int i=1;i<=sq;i++){
        for (int j=1;j<=n;j++){
            a[j]-=j;
        }
        vector <int> b;
        for (int i=1;i<=n;i++){
            b.pb(a[i]);
        }
        sort(b.begin(),b.end());
        for (int j=0;j<n;j++){
            ll k=j;
            while(k<n && b[j]==b[k]) k++;
            ans=max(ans,k-j);
            j=k-1;
        }
    }
if (X==1){
    for (int i=1;i<=n;i++) a[i]=A[i];

        for (int i=1;i<=n;i++) mp[i].clear();
        for (int i=n;i;i--){
            for (int j=i+1;j<=min(n,i+sq);j++){
                if ((a[j]-a[i])%(j-i)==0){
                    ll z=(a[j]-a[i])/(j-i);
                    if (abs(z)<sq-10) continue;
                   
                        mp[i][z]=max(mp[i][z],max((ll)2,mp[j][z]+1));
                   // }
                  //  else mp[i][z]=2;
                    ans=max(ans,mp[i][z]);
                }
            }
        }
    }
    return ans;
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector <int> b;
    for (int i=1;i<=n;i++){
        b.pb(a[i]);
    }
    int ans=0;
    sort(b.begin(),b.end());
    for (int j=0;j<n;j++){
        ll k=j;
        while(k<n && b[j]==b[k]) k++;
        ans=max(ans,k-j);
        j=k-1;
    }
    ans=max(ans,solve(n));
  //  cout << ans << endl;
    reverse(a+1,a+n+1);
    ans=max(ans,solve(n));
    cout << n-ans << endl;
}