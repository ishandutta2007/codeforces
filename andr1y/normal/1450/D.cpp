// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll a[N];
ll e[N], u[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i =0;i<n;i++){
            cin >> a[i];
            u[i]=0;
        }
        u[n]=0;
        stack<pll> st;
        for(ll i=0;i<n;i++){
            while(!st.empty()&&st.top().x>=a[i]) st.pop();
            ll kx = (st.empty()?0:st.top().y+1);
            st.push({a[i], i});
            e[i]=i-kx+1;
        }
        while(!st.empty()) st.pop();
        for(ll i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().x>=a[i]) st.pop();
            ll kx = (st.empty()?n-1:st.top().y-1);
            st.push({a[i], i});
            e[i]+=kx-i;
        }
        for(ll i =0;i<n;i++) u[a[i]]=max(u[a[i]], e[i]);
        multiset<ll> lft;
        multiset<ll, greater<ll>> rgh;
        for(ll i = 1;i<=n;i++){
            lft.insert(u[i]);
        }
        string res="";
        for(ll k = 1;k<=n;k++){
            bool v1 = *(lft.begin())>=k;
            bool v2 = *(rgh.begin())<k;
            if(v1&&v2) res+='1';
            else res+='0';
            lft.erase(lft.find(u[n-k+1]));
            rgh.insert(u[n-k+1]);
        }
        cout<<res<<'\n';
    }
}