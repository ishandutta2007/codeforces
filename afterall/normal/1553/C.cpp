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
ll predict(string s){
    ll x=0,y=0;
    for (int i=0;i<s.size();i++){
        if (i%2==0){
            if (s[i]=='1') x++;
        }
        if (i%2==1){
            if (s[i]=='1') y++;
        }
        ll hady=y;
        ll hadx=x;
        ll z=10-i-1;
        if (i%2==0){
            hady+=(z+1)/2;
            hadx+=(z/2);
        }
        else{
            hady+=(z)/2;
            hadx+=(z+1)/2;
        }
        if (hadx<y || hady<x) return i+1;
    }
    return 10;
}
int Main(){
    string s;
    cin >> s;
    string t=s;
    for (int i=0;i<s.size();i+=2){
        if (t[i]=='?') t[i]='1';
    }
    ll ans=predict(t);
    t=s;
    for (int i=1;i<s.size();i+=2){
        if (t[i]=='?') t[i]='1';
    }
    ans=min(ans,predict(t));
    kill(ans);

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}