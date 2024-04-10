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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
int Main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string y="";
    y+=s[0];

    for (int i=1;i<n;i++){
        if (y.back()>=s[i]){
            if (s[i]<y[0]) {
                y+=s[i];
            }
            else break;
        }
        else break;
    }
    string z=y;
    reverse(z.begin(),z.end());
    y+=z;
    kill(y);

    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}