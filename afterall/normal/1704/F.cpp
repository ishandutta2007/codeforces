#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int M=2e2+100,N=5e5+100;
ll g[N];
ll vis[M];
void Main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans=0;
    ll cntb=0,cntr=0,cnt=0;
    for (int i=0;i<n-1;i++){
        if (s[i]==s[i+1]) continue;
        ll j=i+1;
        while(j<n && s[j]!=s[j-1]){
            j++;
        }
        ans ^= g[j-i];
        i=j-1;
    }
    for (int i=0;i<n;i++){
        if (s[i]=='B') cntb++;
        else cntr++;
        if (i>0) if (s[i]!=s[i-1]) cnt++;
    }
    if (cntb>cntr){
        cout << "Bob" << endl;return;
    }
    if (cntr>cntb){
        cout << "Alice" << endl;return;
    }
    if (ans){
        cout << "Alice" << endl;
    }
    else {
        cout << "Bob" << endl;
    }
}
int32_t main(){
    sync;
    g[0]=0;
    g[1]=0;
    g[2]=1;
    for (int i=1;i<M;i++){
        memset(vis,0,sizeof vis);
        for (int j=0;j<=i-2;j++){
            vis[g[j] ^ g[i-j-2]]=1;
        }
        for (int j=0;j<N;j++){
            if (vis[j]==0){
                g[i]=j;
                break;
            }
        }
    }
    for (int i=M;i<N;i++){
        g[i]=g[i-34];
    }
    ll t=1;
    cin >> t;
    while(t--) Main();
}