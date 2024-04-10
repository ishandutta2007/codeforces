#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
long long s[N];
set<int>p;
queue<pair<int,int>>q;
basic_string<int>g[N];
void wk(int x){
	for(int o:g[x]){
		if(!p.count(o)){
			if(x<o)q.push({x,o});else q.push({o,x});
		}
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>s[i];
		for(i=1;i<=n;++i)cin>>j,s[i]-=j,s[i]+=s[i-1];
		for(i=0;i<=n;++i)g[i]={};
		p={}; 
		while(m--)cin>>j>>k,g[j-1]+=k,g[k]+=j-1;
		for(i=0;i<=n;++i)if(s[i])p.insert(i);
		for(i=0;i<=n;++i)if(!s[i])wk(i);
		while(q.size()){
			tie(i,j)=q.front(),q.pop();
			while(1){
				auto o=p.lower_bound(i);
				if(o==p.end()||*o>j)break;
				wk(*o),p.erase(o);
			}
		}
		if(p.size())cout<<"NO\n";else cout<<"YES\n";
	}
}