#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
const ll mod = 998244353;

int T;
int n;
ll a[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		ll ans=0;
		vector<pair<int,int>> v,nex;
		for(int i=n;i>=1;--i){
			for(int j=0;j<v.size();++j){
				int last=v[j].first;
				int k=(a[i]-1)/last+1;
				ans+=1ll*(k-1)*v[j].second%mod*i%mod;
				ans%=mod;
				nex.push_back({a[i]/k,v[j].second});
			}
			nex.push_back({a[i],1});
			//sort(nex.begin(),nex.end());
			v.clear();
			for(int i=0,r=0;i<nex.size();i=++r){
				while(r+1<nex.size()&&nex[r+1].first==nex[r].first)++r;
				int c=0;
				for(int j=i;j<=r;++j)c+=nex[j].second;
				v.push_back({nex[i].first,c});
			}
			nex.clear();
		}
		cout<<ans<<endl;
	}
}