#include<bits/stdc++.h>
using namespace std;
const int N=12e6+9,inf=1e9;
priority_queue<pair<int,int>>q;
int s[N],t[N],lc[N],rc[N],u,v,id,rt;
inline void up(int x){s[x]=max(s[lc[x]],s[rc[x]])+t[x];}
void upd(int&k=rt,int l=0,int r=inf){
	if(!k)k=++id;
	if(l==r){s[k]=v;return;}
	int m=l+r>>1;
	u>m?upd(rc[k],m+1,r):upd(lc[k],l,m),up(k);
}
void add(int k=rt,int l=0,int r=inf){
	if(!k)return;
	if(u<=l&&r<=v){++s[k],++t[k];return;}
	int m=l+r>>1;
	if(u<=m)add(lc[k],l,m);
	if(m<v)add(rc[k],m+1,r);
	up(k);
}
int qry(int k=rt,int l=0,int r=inf){
	if(!k)return 0;
	if(u<=l&&r<=v)return s[k];
	int m=l+r>>1;
	if(u<=m)return t[k]+(m<v?max(qry(lc[k],l,m),qry(rc[k],m+1,r)):qry(lc[k],l,m));
	return t[k]+qry(rc[k],m+1,r);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,r,i,j,k,o,l=-1;
	for(cin>>n>>r;n--;)if(cin>>i>>j,j>=0)i=max(i,0),q.push({-j,-i}),q.push({-i,1});
	while(q.size()){
		i=-q.top().second,j=-q.top().first,q.pop();
		if(i>=0)u=i,v=j,add();else if(j>l){
			u=v=l,k=l<0?0:qry(),u=0,v=j-r,o=v<0?0:qry();
			if(i==-1||k<o)if(l=u=j,v=o,upd(),j+r<=inf)q.push({-j-r,2});
		}
	}
	cout<<s[rt];
	return 0;
}