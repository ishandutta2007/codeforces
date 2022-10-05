#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
set<int>s[N];
int fa[N];
basic_string<int>g[N];
void dfs(int x,int y){
	fa[x]=y;
	for(int i:g[x])if(i^y){
		dfs(i,x);
		s[x].insert(i);
	}
}
int a[N];
set<pair<int,int>>st;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,k,i,j,x,y,lf=0,sum=0;
	long long ans;
	cin>>n>>k;
	for(i=1;i<n;++i){
		cin>>x>>y;
		g[x]+=y,g[y]+=x;
	}
	dfs(1,0);
	for(i=1;i<=n;++i)if(s[i].empty())++lf;
	if(k>=lf){
		if(k<=n/2)ans=k*1ll*(n-k);
		else if(lf>=n/2)ans=lf*1ll*(n-lf);
		else ans=(n/2)*1ll*(n-n/2);
		cout<<ans;return 0;
	}
	for(i=1;i<=n;++i)if(s[i].empty()){
		a[i]=1,st.insert({1,i});
		j=i;
		while(s[fa[j]].size()==1){
			x=*s[fa[j]].begin();
			if(!st.count({a[x],x}))break;
			st.erase({a[x],x});
			a[fa[j]]=a[x]+1;
			st.insert({a[fa[j]],fa[j]});
			j=fa[j];
		}
	}
	for(i=1;i<=lf-k;++i){
		j=st.begin()->second,st.erase(st.begin());
		sum+=a[j];
		s[fa[j]].erase(j);
		while(s[fa[j]].size()==1){
			x=*s[fa[j]].begin();
			if(!st.count({a[x],x}))break;
			st.erase({a[x],x});
			a[fa[j]]=a[x]+1;
			st.insert({a[fa[j]],fa[j]});
			j=fa[j];
		}
	}
	if(sum<=n/2)ans=sum*1ll*(n-sum);
	else ans=(n/2)*1ll*(n-n/2);
	cout<<(n-k)*1ll*k-ans;
	return 0;
}