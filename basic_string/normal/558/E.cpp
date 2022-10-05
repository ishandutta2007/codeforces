#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char o[N];
struct T{int l,r,s;}s[N*19];
string z;
int r[N],u,i;
bool f[N],v;
set<int>w;
using it=decltype(w.end());
void upd(int&k,int l,int r){
	if(++s[k=++i].s,l==r)return;
	int m=l+r>>1;
	u>m?upd(s[k].r,m+1,r):upd(s[k].l,l,m);
}
void sp(int k,int&t){
	if(s[k].s==u)return;
	if(s[t=++i].s=s[k].s-u,s[k].s=u,!s[k].l&&!s[k].r)return;
	if(v)swap(s[k].l,s[k].r);
	u>s[s[k].l].s?(u-=s[s[k].l].s,sp(s[k].r,s[t].r)):(s[t].r=s[k].r,s[k].r=0,sp(s[k].l,s[t].l));
	if(v)swap(s[t].l,s[t].r),swap(s[k].l,s[k].r);
}
it sp(int x){
	it i=w.lower_bound(x);
	if(i!=w.end()&&*i==x)return i;
	return --i,u=x-*i,v=f[x]=f[*i],sp(r[*i],r[x]),w.insert(x).first;
}
void mg(int&k,int t){if(k&&t)s[k].s+=s[t].s,mg(s[k].l,s[t].l),mg(s[k].r,s[t].r);else k|=t;}
void qry(int k,int l,int r){
	if(l==r)return void(z.insert(z.end(),s[k].s,l));
	int m=l+r>>1;
	qry(s[k].l,l,m),qry(s[k].r,m+1,r);
}
int main(){
	int n,q,i,j,k;
	it a,b,c;
	for(i=1,scanf("%d%d%s",&n,&q,o+1);i<=n;++i)u=o[i],upd(r[i],'a','z'),w.insert(i);
	for(;q--;f[i]=!k,w.erase(a,b))for(scanf("%d%d%d",&i,&j,&k),b=sp(j+1),a=sp(i),c=++a;c!=b;++c)mg(r[i],r[*c]);
	for(int a:w){
		if(z="",qry(r[a],'a','z'),f[a])reverse(z.begin(),z.end());
		cout<<z;
	}
	return 0;
}