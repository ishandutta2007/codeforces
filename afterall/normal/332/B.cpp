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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+10;
int a[N];
int ps[N];
pair <int,int> dp[N];
int32_t main(){
    int n;
    int k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        ps[i]=ps[i-1]+a[i];
    }
    for (int i=k;i<=n;i++){
        dp[i]=dp[i-1];
        if (ps[i]-ps[i-k]>dp[i].F){
            dp[i]={ps[i]-ps[i-k],i};
        }
    }
    int l=k,r=2*k;
    for (int i=2*k;i<=n;i++){
        int ans=ps[i]-ps[i-k]+dp[i-k].F;
        if (ans>ps[r]-ps[r-k]+ps[l]-ps[l-k]){
            l=dp[i-k].S,r=i;
        }
    }
    cout << l-k+1 << " " << r-k+1 << endl;
}