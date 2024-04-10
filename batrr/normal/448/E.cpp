// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7,LOG=18;
ll x,k;
vector<ll>p;
vector<int> ans,g[10000];
vector<int> binpow(int k){
	vector<int>res,f(p.size(),-1),tmp;
	if(k==0){
		res.pb(p.size()-1);
		return res;
	}
	tmp=binpow(k/2);
	for(int i=0;i<tmp.size();i++)
		if( f[tmp[i]]==-1 )
			f[tmp[i]]=i;
	
	for(int i=0;i<tmp.size();i++){
		for(int j=0;j<g[tmp[i]].size();j++){
			int x=g[tmp[i]][j];
			int l,r=f[x];                              
			if(x==0)
				l=0;
			else
				l=f[x-1]+1;
	
			while(l<=r){
       	 		if(res.size()<1e5)
       	 			res.pb(tmp[l]);
       	 		l++;
        	}
		}
	}		

	if(k&1){
		tmp=res;
		res.clear();
		for(int i=0;i<tmp.size();i++){
			ll v=tmp[i];
			for(int j=0;j<g[v].size();j++)
				if(res.size()<1e5)
        			res.pb(g[v][j]);
		}			
	}

	return res;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif                                     
	cin>>x>>k;   
	k=min(k,(ll)1e5);
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			p.pb(i);
			if(i*i!=x)
				p.pb(x/i);
		}
	}
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++)
		for(int j=0;j<p.size();j++)
			if(p[i]%p[j]==0)
				g[i].pb(j);
	ans=binpow(k);
	for(int i=0;i<ans.size();i++)
		cout<<p[ans[i]]<<" ";
}