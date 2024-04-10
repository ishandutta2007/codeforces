#include<bits/stdc++.h>
using namespace std;
struct P{int s,a;pair<int,int>w;bool operator<(P x)const{return w<x.w;}}p[500009];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,d,i,s=0;
	for(cin>>n>>d,i=0;i<n;++i)cin>>p[i].s>>p[i].a,p[i].w={max(p[i].s,p[i].a),p[i].s};
	for(sort(p,p+n),i=0;i<n;++i)if(p[i].s>=d)d=max(d,p[i].a),++s;
	cout<<s;
	return 0;
}