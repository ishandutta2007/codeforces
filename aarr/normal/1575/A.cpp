#include <bits/stdc++.h>
/// 500 485 462 A4
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
using namespace std;
const int N=2e5+100;

int Main(){
    vector <pair <string,int> > a;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int i=1;i<m;i+=2){
            ll z=s[i]-'A';
            z=25-z;
            s[i]='A'+z;
        }
        a.pb({s,i});
    }
    sort(a.begin(),a.end());
    for (auto u : a){
        cout << u.S << " ";
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;

    while(t--) Main();
}