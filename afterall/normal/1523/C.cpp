#include <bits/stdc++.h>
/// this time?
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
    vector <int> a;
void print(){
    for (int i=0;i<a.size();i++){
        cout << a[i];
        if (i+1==a.size()) break;
        cout << '.';
    }
    cout << endl;
}
int Main(){
    ll n;
    cin >> n;
    a.clear();
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        if (a.size()==0 || x==1){
            a.pb(x);
            print();
            continue;
        }
       // cout << x << " eirj " << a.back() << endl;
        if (x==a.back()+1){
            a[a.size()-1]++;
            print();
            continue;
        }
        while(a.back()!=x-1) a.pop_back();
        a[a.size()-1]=x;
        print();
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}