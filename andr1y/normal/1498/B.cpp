// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll inf = 0x3fff3fff3fff3fff;
ll a[N], fr[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, w;
        cin >> n >> w;
        multiset<ll> st;
        //multiset<ll, greater<ll>> st2;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            st.insert(a[i]);
            //st2.insert(a[i]);
        }
        ll cnt=0;
        while(!st.empty()){
            cnt++;
            ll free = w;
            while(true){
                auto it = st.upper_bound(free);
                if(it==st.begin()) break;
                it=prev(it);
                free-=*it;
                //st2.erase(st2.find(*it));
                st.erase(it);
            }
        }
        cout<<cnt<<'\n';
    }
}