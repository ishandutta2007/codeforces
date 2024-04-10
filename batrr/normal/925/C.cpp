#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                   
#define ld long double                                                                                                           
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5e5+123,MX=1e9,inf=1e9,block=2;
ll n,x;
vector<ll>v[100];
int getb(ll x){
	int res=0;
	while(x!=0)
		x/=2,res++;
	return res;
}
int main(){                                         
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		v[getb(x)].pb(x);      
	}
	vector<ll> ans,tmp;
	for(int b=62;b>=0;b--){
		ll cur=0,j=0;
		for(int i=0;i<v[b].size();i++){
			while( (cur^v[b][i]) <= cur ){
				if(j==ans.size())
					return cout<<"No",0;
				tmp.pb(ans[j]);
				cur^=ans[j];
				j++;
			}
			tmp.pb(v[b][i]);
			cur^=v[b][i];
		}
		while(j<ans.size())
			tmp.pb(ans[j++]);
		
		ans=tmp;
		tmp.clear();
		/*
		for(int j=0;j<ans.size();j++)
			cout<<ans[j]<<" ";
	    cout<<endl;
	    */
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";

}