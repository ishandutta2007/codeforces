// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], b[N], c[N], arr[N];
vector<ll> ek[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++) cin >> a[i];
        for(ll i = 0;i<n;i++) cin >> b[i];
        for(ll i =0;i<m;i++) cin >> c[i];
        bool ok =0;
        ll kk=0;
        for(ll i = 0;i<n;i++){
            if(b[i]==c[m-1]) ok=1, kk=i;
        }
        arr[m-1]=-1;
        if(!ok){
            cout<<"no\n";
            continue;
        }
        for(ll i=0;i<m;i++) ek[c[i]].push_back(i);
        for(ll i=0;i<n&&ok;i++){
            if(a[i]==b[i]) continue;
            if(ek[b[i]].empty()){
                 ok=0;
                 break;
            }
            arr[ek[b[i]].back()]=i;
            ek[b[i]].pop_back();
        }
        if(!ok){
            for(ll i = 0;i<m;i++) ek[c[i]].clear();
            cout<<"no\n";
            continue;
        }
        cout<<"yes\n";
        if(arr[m-1]==-1) arr[m-1]=kk;
        for(ll i = 0;i<m;i++){
            for(auto j : ek[c[i]])
                arr[j]=arr[m-1];
            ek[c[i]].clear();
        }
        for(ll i = 0;i<m;i++) cout<<arr[i]+1<<' ';
        cout<<'\n';
    }
}