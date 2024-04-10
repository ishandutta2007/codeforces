#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],c[N],b[N];
basic_string<int>v[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)c[i]=0,v[i]={};
		for(i=1;i<=n;++i){
			cin>>a[i];
			++c[a[i]];
			v[c[a[i]]]+=i;
		}
		for(i=1;;++i){
			if(v[i].empty())break;
			k=v[i].size();
			sort(begin(v[i]),end(v[i]),
			[](int x,int y){return a[x]<a[y];});
			for(j=1;j<k;++j)b[v[i][j-1]]=a[v[i][j]];
			b[v[i][k-1]]=a[v[i][0]];
		}
		for(i=1;i<=n;++i)cout<<b[i]<<' ';
		cout<<'\n';
	}
}/*
1 1 1 2 2 2
2 2 2 1 1 1
1 1 1 2 2 2 3 3
3 3 2 1 1 1 2 2
2 2  2 3 3 1 1 1*/