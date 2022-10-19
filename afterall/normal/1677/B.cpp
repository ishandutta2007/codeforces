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
const int N=1e6+100;
ll mod=998244353;
ll a[N];
ll b[N];
ll c[N];
void Main(){
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i=1;i<=n*m;i++) c[i]=s[i-1]-'0',b[i]=0,a[i]=0;
    deque <int> d;
    ll cnt=0;
    for (int i=1;i<=n*m;i++){
        if (d.size()<m){
            d.push_front(c[i]);
            cnt+=c[i];
        }
        else{
            ll z=max(d.back(),c[i]);
            d.push_front(z);
            cnt-=d.back();
            d.pop_back();
            cnt+=z;
        }
        a[i]=cnt;
    }
    ll id=-1;
    for (int i=1;i<=n*m;i++){
        if (c[i]==1){
            id=i;
            break;
        }
        b[i]++;
    }
    if (id!=-1){
        ll cnt=0;
        for (int i=id+1;i<=n*m;i++){
            if (c[i]==0){
                cnt++;
            }
            else cnt=0;
            //cout << cnt  << " " << a[i] << endl;
            if (cnt>=m) b[i]++;
        }
    }
    for (int i=m;i<=n*m;i++) b[i]+=b[i-m];
    for (int i=1;i<=n*m;i++){
        ll ans=a[i]-b[i];
        ans+=(i+m-1)/m;
        cout << ans << " ";
    }
    cout << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
/*
1
2 2
1100
*/