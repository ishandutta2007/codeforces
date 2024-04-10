#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+3;
int n,a,b,c,e0,c00,c11;
ll ans;
char s[N];
int f[N];
deque<int>v;
void dfs(bool op,int e0,int c0,int c00,int c11,ll now){
	ans=max(ans,now);
	if(op){
		if(!c00){
			if(c0)dfs(!op,e0,c0-1,c00,c11+1,now-c);
			else if(e0)dfs(!op,e0-1,c0,c00,c11,now-c);
		}else if(!c11){
			ans=max(ans,now+a);
			if(c0)dfs(!op,e0,c0-1,c00,c11+1,now-c);
		}else{
			dfs(!op,e0,c0+f[c00-1],c00-1,c11,now+a);
		}
	}else{
		if(c11)dfs(!op,e0,c0,c00,c11-1,now+b);
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>a>>b>>c;
		for(i=0;i<=n;++i)f[i]=0;
		cin>>s+1;
		for(i=1;i<=n;++i){
			if(s[i]=='1')goto gg;
		}
		if(n==1)cout<<0<<'\n';
		else cout<<a<<'\n';
		continue;
		gg:;
		e0=c00=c11=0;
		if(s[1]=='0')++e0;
		if(s[n]=='0')++e0;
		for(i=1;i<n;++i){
			if(s[i]=='0'&&s[i+1]=='0')++c00;
			if(s[i]=='1'&&s[i+1]=='1')++c11;
		}
		v.clear();
		k=0;
		for(i=1;i<=n;++i){
			if(s[i]=='0')++k;
			else if(k)v.push_back(k-1),k=0;
		}
		if(k)v.push_back(k-1),k=0;
		if(s[1]=='0')v.pop_front();
		if(s[n]=='0')v.pop_back();
		sort(begin(v),end(v));
		k=0;
		for(auto o:v)k+=o,++f[c00-k];
		dfs(0,e0,f[c00],c00,c11,0);
		dfs(1,e0,f[c00],c00,c11,0);
		cout<<ans<<'\n';ans=0;
	}
	return 0;
}