#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;

int Main(){
    ll n,x;
    cin >> n >> x;
    vector <int> a;
    ll sum=0;
    for (int i=0;i<n;i++){
        ll c;
        cin >> c;
        a.pb(c);
        sum+=c;
    }
    sort(a.begin(),a.end());
    if (sum==x) kill("NO");
    cout << "YES" << endl;
    sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i];
        if (sum==x){
            swap(a[i],a[n-1]);
            break;
        }
    }
    for (auto u : a) cout << u << " ";
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) {
        Main();
    }
}