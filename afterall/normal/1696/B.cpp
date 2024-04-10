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
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
ll a[N];
void Main(){
    ll n;
    cin >> n;
    ll cnt=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]==0) cnt++;
    }
    a[n+1]=0;
    if (cnt==n){
        cout << 0 << endl;
        return ;
    }
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            cnt--;
        }
        else break;
    }
    for (int i=n;i;i--){
        if (a[i]==0) cnt--;
        else break;
    }
    if (cnt==0){
        cout << 1 << endl;
        return ;
    }
    cout << 2 << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}