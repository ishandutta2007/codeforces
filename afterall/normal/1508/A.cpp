#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef complex<double> point;
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
    ll n;
    cin >> n;
    vector <char> a,b,c;
    for (int i=0;i<2*n;i++){
        char c;
        cin >> c;
        a.pb(c);
    }
    for (int i=0;i<2*n;i++){
        char c;
        cin >> c;
        b.pb(c);
    }
    for (int i=0;i<2*n;i++){
        char cc;
        cin >> cc;
        c.pb(cc);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    string s="";
    for (int i=0;i<3*n;i++){
        ll t0=0,t1=0;
        if (a.size()==0 || b.size()==0 || c.size()==0) break;
        if (a.back()=='0') t0++;
        else t1++;
        if (b.back()=='0') t0++;
        else t1++;
        if (c.back()=='0') t0++;
        else t1++;
        if (t0>t1){
            s+='0';
            if (a.back()=='0') a.pop_back();
            if (b.back()=='0') b.pop_back();
            if (c.back()=='0') c.pop_back();
        }
        else{
            s+='1';
            if (a.back()=='1') a.pop_back();
            if (b.back()=='1') b.pop_back();
            if (c.back()=='1') c.pop_back();
        }
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    vector <pair <int,vector <char> > > d;
    d.pb({a.size(),a});
    d.pb({b.size(),b});
    d.pb({c.size(),c});
    sort(d.begin(),d.end());
    for (auto u : d[1].S){
        s+=u;
    }
   // cout << "ans ";
    kill(s);
    return 0;
}
int32_t main(){
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}