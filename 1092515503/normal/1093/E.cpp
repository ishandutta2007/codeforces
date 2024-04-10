#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int BBB=1000;
int n,m,BLK[200100],ra[200100],c[200100],d[200100],lp[1000],lim;
vector<pair<int,int> >v;
inline int CALC(int l,int r,int L,int R){
	register int res=0;
	for(auto x:v){
		res-=(x.first>=L)&&(x.first<R)&&(c[x.first]>=l)&&(c[x.first]<r);
		res-=(x.second>=L)&&(x.second<R)&&(c[x.second]>=l)&&(c[x.second]<r);
		swap(c[x.first],c[x.second]);
		res+=(x.first>=L)&&(x.first<R)&&(c[x.first]>=l)&&(c[x.first]<r);
		res+=(x.second>=L)&&(x.second<R)&&(c[x.second]>=l)&&(c[x.second]<r);
	}
	for(int i=v.size()-1;i>=0;i--)swap(c[v[i].first],c[v[i].second]);
	if(BLK[L]==BLK[R]){
		for(register int i=L;i<R;i++)res+=(c[i]>=l&&c[i]<r);
		return res;
	}
	for(register int i=L;i<lp[BLK[L]+1];i++)res+=(c[i]>=l&&c[i]<r);
	for(register int i=lp[BLK[R]];i<R;i++)res+=(c[i]>=l&&c[i]<r);
	for(register int i=BLK[L]+1;i<BLK[R];i++)res+=lower_bound(d+lp[i],d+lp[i+1],r)-lower_bound(d+lp[i],d+lp[i+1],l);
	return res; 
}
void init(){
	for(auto x:v)swap(c[x.first],c[x.second]);
	v.clear();
	for(int i=0;i<n;i++)d[i]=c[i];
	for(int i=0;i<lim;i++)sort(d+lp[i],d+lp[i+1]);
}
inline void read(int &x){
	x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline int read(){
	register int x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
inline void print(int x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
int main(){
	read(n),read(m);
	for(register int i=0;i<n;i++)ra[read()]=i,BLK[i]=i/BBB;
	for(register int i=0;i<n;i++)c[i]=ra[read()];
	lim=BLK[n-1]+1;
	for(register int i=0;i<lim;i++)lp[i]=i*BBB;
	lp[lim]=n,BLK[n]=lim;
	init();
	for(register int i=1,t1,t2,t3,t4,t5;i<=m;i++){
		read(t1);
		if(t1==1)read(t2),read(t3),read(t4),read(t5),t2--,t4--,print(CALC(t2,t3,t4,t5)),putchar('\n');
		else read(t2),read(t3),t2--,t3--,v.push_back(make_pair(t2,t3));
		if(v.size()>=BBB)init();
	}
	return 0;
}