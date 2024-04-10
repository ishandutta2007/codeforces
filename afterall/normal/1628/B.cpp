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
map <string,int> mp;
string s[N];
int Main(){
    mp.clear();
    ll n;
    cin >> n;
    ll p1=0;
    for (int i=1;i<=n;i++){
        cin >> s[i];
        mp[s[i]]=1;
        if (s[i][0]==s[i].back()) p1=1;
        if (s[i].size()==1) p1=1;
        if (s[i].size()==2){
            string y=s[i];
            reverse(y.begin(),y.end());
            if (mp[y]) p1=1;
            for (char c='a';c<='z';c++){
                string t=y+c;
                if (mp[t]) p1=1;
            }
        }
        if (s[i].size()==3){
            string y=s[i];
            reverse(y.begin(),y.end());
            if (mp[y]) p1=1;
            y.pop_back();
            if (mp[y]) p1=1;
        }
    }
    if (p1) kill("YES");
    kill("NO");

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}