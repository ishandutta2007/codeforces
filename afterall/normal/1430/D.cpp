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
ll Main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set <int> t;
    vector <int> a;
    for (int i=0;i<s.size();i++){
        ll j=i;
        while(j<s.size() && s[i]==s[j]) j++;
        ll k=a.size();
        a.pb(j-i);
        if (j-i>1){
            t.insert(k);
        }
        i=j-1;
    }
    ll ans=0;
    ll cnt=0;
    for (int i=0;i<a.size();i++){
        if (!t.size()) break;
        cnt++;
        ans++;
        ll id=*t.begin();
        a[id]--;
        if (a[id]==1){
            t.erase(id);
        }
        t.erase(i);
    }
    ans+=(a.size()-cnt+1)/2;
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}