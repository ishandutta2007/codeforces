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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
map <int,int> mp;
void Main(){
    ll n;
    cin >> n;
    mp.clear();
    ll ans=0;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        mp[x]++;
        ans+=x;
    }
    queue <int> q;
    q.push(ans);
    ll e=0;
    while(q.size()){
        e++;
        if (e>3*n) {
            cout << "NO" << endl;return;
        }
        ll v=q.front();
        q.pop();
        if (mp[v]>0) {
            mp[v]--;
            continue;
        }
        if (v==1){
            cout << "NO" << endl;
            return ;
        }
        q.push(v/2);
        q.push((v+1)/2);
    }
    cout << "YES" << endl;

    
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}