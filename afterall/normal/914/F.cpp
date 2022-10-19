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
const int N=1e5+100;
bitset <N> dp[26],ans;
string s;
int32_t main(){
    sync;
    cin >> s;
    for (int i=0;i<s.size();i++){
        dp[s[i]-'a'][i]=1;
    }
    ll q;
    cin >> q;
  //  ans=dp[0];
    while(q--){
        ll t;
        cin >> t;
        if (t==1){
            ll id;
            char c;
            cin >> id >> c;
            id--;
            dp[s[id]-'a'][id]=0;
            s[id]=c;
            dp[s[id]-'a'][id]=1;
        }
        else{
            ll l,r;
            cin >> l >> r;
            string c;
            cin >> c;
            l--,r--;
            ans=dp[c[0]-'a'];
           // cout << "KIR" << c[0] << endl;
            for (int i=1;i<c.size();i++){
                ans=(ans<<1)&dp[c[i]-'a'];
            }
            ans=(ans>>(l+c.size()-1));
            ans=(ans<<(l+c.size()-1+N-1-r));
            cout << ans.count() << endl;
        }
    }
}