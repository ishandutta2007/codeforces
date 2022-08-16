#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;

ll a[200005],l[200005],r[200005];
vector <ll> v[200005];
set <pair<ll,ll>> s;
vector <ll> ans;
ll t,n,u,ct,q,k;
pair <ll,ll> p;

int main(){
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>l[i];
		cin>>r[i];
		v[l[i]].push_back(i);
		v[r[i]+1].push_back(-i);
	}

	for(int i = 1;i<200001;i++){
		for(auto it : v[i]){
			//cout<<it;
			if(it > 0) s.insert({r[it],it});
			else s.erase({r[-it],-it});
		}
		t = s.size(); 
		while(t > k){
			auto it = s.end();
			it--;
			ans.push_back((*it).second);
			s.erase(it);
			t--;
		}
	}
	cout<<ans.size()<<endl;
	t = ans.size();
	for(int i = 0; i<t; i++)cout<<ans[i]<<" ";
	cout<<endl;
}