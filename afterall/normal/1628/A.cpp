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
ll a[N];
ll vis[N];
ll cnt[N];
void Main(){
    ll n;
    cin >> n;
    for (int i=0;i<=n;i++){
        vis[i]=0;
        cnt[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector <int> ans;
    for (int i=1;i<=n;i++){
        ll K=-1;
        for (int k=0;k<=n;k++){
            if (cnt[k]==0){
                K=k;
                break;
            }
        }
        ans.pb(K);
        if (K==0) {
            continue;
        }
        for (int k=0;k<K;k++) vis[k]=0;
        ll p1=0;
        ll j=i;
        while(j<=n && p1!=K){
            if (a[j]<K && vis[a[j]]==0){
                p1++;
                vis[a[j]]=1;
            }
            cnt[a[j]]--;
            j++;
        }

        i=j-1;
    }
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u << " ";
    }
    cout << endl;
    return ;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}