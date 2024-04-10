#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll x,w;
multiset<ll>st;
bool fl;
void dfs(ll w){
	if(st.count(w)){
		st.erase(st.find(w));
		return;
	}
	if(w==1){
		fl=1;
		return;
	}
	if(fl)return;
	ll w2=w/2;
	dfs(w2),dfs(w-w2);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;w=0;st.clear();fl=0;
		for(i=1;i<=n;++i)cin>>x,w+=x,st.insert(x);
		dfs(w);
		
		if(fl)cout<<"NO\n";
		else cout<<"YES\n";
	}
}