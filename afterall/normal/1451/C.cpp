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
ll t[27],cnt[27];
int Main(){
    ll n,k;
    cin >> n >> k;
    string a,b;
    cin >> a >> b;
    memset(t,0,sizeof t);
    memset(cnt,0,sizeof cnt);
    for (int i=0;i<n;i++){
        t[a[i]-'a']++;
        cnt[b[i]-'a']++;
    }
    for (int i=0;i<26;i++){
        if (i) t[i]+=t[i-1],cnt[i]+=cnt[i-1];
        if (t[i]<cnt[i] || (t[i]-cnt[i])%k!=0) kill("NO");
    }
    kill("YES");
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}