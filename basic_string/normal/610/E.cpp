#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,q,o,i,j,u,v,w,c[11],a[11][11];
char s[N],_;
struct T{
	int l,r,s[11][11],t;
}t[N*4];
void mg(T&k,T&a,T&b){
	for(int i=0;i<o;++i)for(int j=0;j<o;++j)k.s[i][j]=a.s[i][j]+b.s[i][j];
	k.l=a.l,k.r=b.r,++k.s[a.r][b.l];
}
void bd(int k,int l,int r){
	if(t[k].t=-1,l==r){t[k].l=t[k].r=s[l]-'a';return;}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),mg(t[k],t[k*2],t[k*2+1]);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		t[k].l=t[k].r=t[k].t=w,memset(t[k].s,0,sizeof t[k].s),t[k].s[w][w]=r-l;
		return;
	}
	int m=l+r>>1,a=k*2,b=k*2+1;
	if(~t[k].t){
		int w=t[k].t;
		t[a].l=t[a].r=t[a].t=w,memset(t[a].s,0,sizeof t[a].s),t[a].s[w][w]=m-l;
		t[b].l=t[b].r=t[b].t=w,memset(t[b].s,0,sizeof t[b].s),t[b].s[w][w]=r-m-1;
		t[k].t=-1;
	}
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	mg(t[k],t[a],t[b]);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q>>o>>(s+1),bd(1,1,n);
	while(q--)if(cin>>i,i==1)cin>>u>>v>>_,w=_-'a',upd(1,1,n);else{
		cin>>s;
		for(i=0;i<o;++i)c[s[i]-'a']=i;
		for(i=0,w=1;i<o;++i)for(j=0;j<o;++j)if(c[i]>=c[j])w+=t[1].s[i][j];
		cout<<w<<'\n';
	}
	return 0;
}