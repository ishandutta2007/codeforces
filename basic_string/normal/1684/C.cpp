#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
vector<vector<int>>a2;
vector<int>a;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,l,u,v,w,u2=0,v2=0;
	bool fl;
	for(cin>>T;T--;){
		cin>>n>>m;fl=0;u2=v2=0;a2={},a={};
		for(i=1;i<=n;++i){
			a.resize(m+1);
			for(j=1;j<=m;++j)cin>>a[j];
			u=v=w=0;
			for(j=1;j<m;++j)if(a[j]>a[j+1]){
				if(!u)u=j;
				else if(!v)v=j;
				else fl=1;
			}
			if(u){
				if(!v)v=u+1;
				else v=v+1;
				while(v+1<=m&&a[v]==a[v+1])++v;
				while(u>1&&a[u]==a[u-1])--u;
				swap(a[u],a[v]);
				if(!is_sorted(begin(a)+1,begin(a)+m+1))fl=1;
				if(u2){
					if(u2!=u||v2!=v)fl=1;
				}else u2=u,v2=v;
				swap(a[u],a[v]);
			}
			a2.push_back(a);
		}
		if(!fl){
			for(auto o:a2){
				swap(o[u2],o[v2]);
				if(!is_sorted(begin(o)+1,begin(o)+m+1))fl=1;
			}
		}
		if(fl)cout<<-1<<'\n';
		else if(u2)cout<<u2<<' '<<v2<<'\n';
		else cout<<1<<' '<<1<<'\n';
	}
}/*
1 2 4 3 5 6
1 5 3 4 2 6
1 2 3 4 5 6*/