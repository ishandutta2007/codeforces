#include<bits/stdc++.h>
using namespace std;
struct T{
	int l,r,t,v,d;
}s[300009];
int u;
void add(int x,int y){s[x].t+=y,s[x].v+=y;}
void dn(int x){if(s[x].t)add(s[x].l,s[x].t),add(s[x].r,s[x].t),s[x].t=0;}
void sp(int x,int&p,int&q){
	if(!x){p=q=0;return;}
	if(dn(x),s[x].v<=u)p=x,sp(s[x].r,s[p].r,q);
	else q=x,sp(s[x].l,p,s[q].l);
}
int mg(int x,int y){
	if(!x||!y)return x|y;
	if(s[x].d<s[y].d)return dn(x),s[x].r=mg(s[x].r,y),x;
	return dn(y),s[y].l=mg(x,s[y].l),y;
}
void del(int&x){if(s[x].l)del(s[x].l);else x=s[x].r;}
mt19937 rd(9);
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,l,r,x=0,y,z,i,w;
	for(cin>>n,w=n,i=1;i<=n;++i){
		cin>>l>>r;
		if(u=r-1,sp(x,x,z),z)del(z),--w;
		u=l-1,sp(x,x,y),add(y,1);
		s[i]={0,0,0,l,(int)rd()},x=mg(mg(x,i),mg(y,z));
	}
	cout<<w;
}