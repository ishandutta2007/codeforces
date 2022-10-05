#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
mt19937 rd(9);
struct T{
	int l,r,d,i,v,a,tv,ta;
}s[N];
struct P{
	int c,q;
}p[N];
int n,ans[N],k,r,u,x,y,z,i;
void add(int x,int v,int a){s[x].v+=v,s[x].tv+=v,s[x].a+=a,s[x].ta+=a;}
void dn(int x){
	if(s[x].l)add(s[x].l,s[x].tv,s[x].ta);
	if(s[x].r)add(s[x].r,s[x].tv,s[x].ta);
	s[x].tv=s[x].ta=0;
}
void sp(int x,int&p,int&q){
	if(!x){p=q=0;return;}
	if(dn(x),s[x].v<=u)p=x,sp(s[x].r,s[p].r,q);else q=x,sp(s[x].l,p,s[q].l);
}
int mg(int x,int y){
	if(!x||!y)return x|y;
	if(s[x].d<s[y].d)return dn(x),s[x].r=mg(s[x].r,y),x;
	return dn(y),s[y].l=mg(x,s[y].l),y;
}
void ins(int x){u=s[x].v,sp(r,r,z),r=mg(mg(r,x),z);}
void dfs(int x){if(x)dn(x),dfs(s[x].l),dfs(s[x].r),s[x].l=s[x].r=0,ins(x);}
void cal(int x){if(x)dn(x),cal(s[x].l),cal(s[x].r),ans[s[x].i]=s[x].a;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(i=1;i<=n;++i)cin>>p[i].c>>p[i].q;
	cin>>k;
	for(i=1;i<=k;++i)s[i].d=rd(),s[i].i=i,cin>>s[i].v,ins(i);
	sort(p+1,p+n+1,[](P x,P y){return x.q>y.q||(x.q==y.q&&x.c<y.c);});
	for(i=1;i<=n;++i){
		u=p[i].c-1,sp(r,r,x),add(x,-p[i].c,1);
		sp(x,x,y),dfs(x),r=mg(r,y);
	}
	for(cal(r),i=1;i<=k;++i)cout<<ans[i]<<' ';
}