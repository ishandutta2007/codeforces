//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll M = 998244353;
ll a[N], b[N], c[N];
ll al[N], ar[N];
map<ll, ll> last;
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        last[a[i]]=i;
    }
    bool ok = 1;
    for(ll i = 0;i<m;i++){
        cin >> b[i];
        if(!last.count(b[i])){
            ok= 0;
        }else{
            c[i]=last[b[i]];
        }
    }
    if(!ok) {
        cout<<0;
        return 0;
    }
    stack<pair<ll, ll>> st;
    for(ll i = 0;i<n;i++){
        while(!st.empty()&&st.top().first>=a[i]) st.pop();
        ll lst = (st.empty()?0:st.top().second+1);
        al[i]=lst;
        st.push({a[i], i});
    }
    while(!st.empty()) st.pop();
    for(ll i = n-1;i>=0;i--){
        while(!st.empty()&&st.top().first>=a[i]) st.pop();
        ll lst = (st.empty()?n-1:st.top().second-1);
        ar[i]=lst;
        st.push({a[i], i});
    }
    if(al[c[0]]>0||ar[c[m-1]]<n-1){
        cout<<0;
        return 0;
    }
    ll res=1;
    for(ll i = 1;i<m&&res;i++){
        ll l = ar[c[i-1]], r=al[c[i]];
        ll l1 = c[i-1], r1 = l, l2 = r, r2 = c[i];
        res*=max(0ll, min(r1, r2)-max(l1, l2)+1);
        res%=M;
    }
    cout<<res;
}