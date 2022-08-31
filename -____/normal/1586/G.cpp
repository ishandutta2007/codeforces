#include<bits/stdc++.h>
using namespace std;
const int N = 444444;
const int M = N<<5;
const int MO = 1e9+7;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int n,m,a[N],b[N],c[N],d[N],f[N],g[N];
pair<int,int> p[N];
int tot,t[M],ls[M],rs[M],rt[N];
void modify(int &k,int kk,int x,int y,int l=1,int r=n*2){
	if(!k){
		k=++tot;
		t[k]=t[kk];
	}
	ad(t[k],y);
	if(l==r)
		return;
	int h=l+r>>1;
	if(x<=h)
		modify(ls[k],ls[kk],x,y,l,h),rs[k]=rs[kk];
	else
		modify(rs[k],rs[kk],x,y,h+1,r),ls[k]=ls[kk];
}
int query(int k,int L,int R,int l=1,int r=n*2){
	if(!k)
		return 0;
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1,o=0;
	if(L<=h)
		ad(o,query(ls[k],L,R,l,h));
	if(h<R)
		ad(o,query(rs[k],L,R,h+1,r));
	return o;
}
int s[N];
void modify2(int x,int i){
	x=n*2+1-x;
	while(x<=n*2){
		if(b[s[x]]<b[i])
			s[x]=i;
		x+=x&-x;
	}
}
int query2(int x){
	x=n*2+1-x;
	int i=0;
	while(x){
		if(b[s[x]]>b[i])
			i=s[x];
		x-=x&-x;
	}
	return i;
}
int main(){
	int i,j,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i),a[i]++,b[i]++;
	n++,a[n]=1,b[n]=n*2;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		c[x]=1;
	}
	for(i=1;i<=n;i++)
		p[i]=make_pair(b[i],i);
	sort(p+1,p+n+1);
	y=0;
	for(i=1;i<=n;i++){
		j=p[i].second;
		while(y+1<b[j]){
			rt[y+1]=rt[y];
			y++;
		}
		d[j]=i;
		f[j]=query(rt[b[j]-1],a[j],b[j])+1;
		x=query2(a[j]);
		if(c[j])
			g[j]=1;
		if(x){
			ad(g[j],query(rt[b[x]-1],a[j],n*2));
			ad(g[j],g[x]);
		}//cout<<f[j]<<' '<<g[j]<<endl;
		modify(rt[b[j]],rt[b[j]-1],a[j],f[j]);
		if(c[j])
			modify2(a[j],j);
		y=b[j];
	}
	printf("%d\n",g[n]);
	return 0;
}