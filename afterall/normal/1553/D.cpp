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
int Main(){
    string s;
    string t;
    cin >> s >> t;
  //  reverse(s.begin().s.end());
    //reverse(t.begin(),t.end());
    while(t.size()>0){
        if (s.size()<=0) kill("NO");
        ll x=s.size(),y=t.size();
        if (s[x-1]==t[y-1]){
            s.pop_back();
            t.pop_back();
        }
        else{
            if (s.size()==1) kill("NO");
            s.pop_back();
            s.pop_back();
        }
    }
    kill("YES");

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}