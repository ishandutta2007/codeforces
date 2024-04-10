//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 2e5+18;
ll a[N], fl[N], fr[N], fl2[N], fr2[N], sufmin[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i =0;i<n;i++){
			cin >> a[i];
		}
		stack<ll, vector<ll>> st;
		for(ll i = 0;i<n;i++){
			while(!st.empty()&&a[st.top()]>a[i]) st.pop();
			if(st.empty()) fl[i]=-1;
			else fl[i]=st.top();
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(ll i = n-1;i>=0;i--){
			while(!st.empty()&&a[st.top()]<a[i]) st.pop();
			if(st.empty()) fr[i]=-1;
			else fr[i]=st.top();
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(ll i = 0;i<n;i++){
			while(!st.empty()&&a[st.top()]<a[i]) st.pop();
			if(st.empty()) fl2[i]=-1;
			else fl2[i]=st.top();
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(ll i = n-1;i>=0;i--){
			while(!st.empty()&&a[st.top()]>a[i]) st.pop();
			if(st.empty()) fr2[i]=-1;
			else fr2[i]=st.top();
			st.push(i);
		}
		vector<pll> xc;
		for(ll i = 0;i<n;i++){
			if(fl[i]!=-1&&fr[i]!=-1) xc.push_back({fl[i], fr[i]});
			if(fl2[i]!=-1&&fr2[i]!=-1) xc.push_back({fl2[i], fr2[i]});
		}
		sort(xc.begin(), xc.end());
		ll xn = xc.size();
		sufmin[xn]=n;
		for(ll i = xn-1;i>=0;i--) sufmin[i]=min(sufmin[i+1], xc[i].y);
		ll res=0;
		for(ll l = 0, nxc=0;l<n;l++){
			while(nxc<xn&&xc[nxc].x<l) nxc++;
			res+=sufmin[nxc]-l;
		}
		cout<<res<<'\n';
	}
}