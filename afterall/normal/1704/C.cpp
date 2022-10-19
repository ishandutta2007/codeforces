#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
ll a[N];
void Main(){
    ll m,n;
    cin >> m >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    vector <int> b;
    ll ans=n;
    for (int i=2;i<=n;i++){
        b.pb(a[i]-a[i-1]);
    }
    b.pb(m-a[n]+a[1]);
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    ll cnt=0;
    for (int i=0;i<b.size();i++){
        b[i]--;
       // cout << b[i] << endl;
        if (cnt*2>=b[i]){
            ans+=b[i];
            continue;
        }
        if (cnt*2+1==b[i]){
            cnt++;
            ans+=b[i]-1;
            continue;
        }
        ans+=cnt+cnt+1;
        cnt+=2;

    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}