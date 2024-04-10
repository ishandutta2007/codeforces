#include<bits/stdc++.h>
using namespace std;
queue<int>q[2];
unordered_map<int,int>f[2],w[2];
unordered_set<int>s[2];
int a0[99],a1[99];
int qp(int a,int b,int p){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;
	return r;
}
int main(){
	int j,k,l,o,u,v,p,t0=0,t1=0;
	bool i;
	cin>>u>>v>>p;
	q[0].push(u),s[0].insert(u),q[1].push(v),s[1].insert(v);
	while(1){
		i=s[0].size()>s[1].size(),j=q[i].front(),q[i].pop();
		for(k=1;k<4;++k){
			l=((k==1?j+1:(k==2?j-1:qp(j,p-2,p)))+p)%p;
			if(s[i].count(l))continue;
			f[i][l]=j,w[i][l]=k,q[i].push(l),s[i].insert(l);
			if(s[!i].count(l))goto gg;
		}
	}
	gg:;
	for(j=l;j!=u;j=f[0][j])a0[++t0]=w[0][j];
	for(;l!=v;l=f[1][l])a1[++t1]=w[1][l];
	cout<<t0+t1<<'\n';
	for(;t0;--t0)cout<<a0[t0]<<' ';
	for(j=1;j<=t1;++j)if(a1[j]==1)cout<<"2 ";else if(a1[j]==2)cout<<"1 ";else cout<<"3 ";
	return 0;
}