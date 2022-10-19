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
const int N=2e5+100;
int Main(){
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=0;i<n;i++){
        char c;
        cin >> c;
        a.pb(c-'a');
    }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size();i++){
        cout << char(a[i]+'a') ;
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