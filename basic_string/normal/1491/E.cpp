#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
basic_string<int>g[N];
int fb[39],mk[39][N],id;
int r,u,n,o,o2,_,sz[N],p1,p2,f1,f2;
void gr(int x,int y){
	sz[x]=1;
	int mx=0;
	for(int i:g[x])if(mk[o][i]==_&&i!=y)gr(i,x),sz[x]+=sz[i],mx=max(mx,sz[i]);
	mx=max(mx,n-sz[x]);
	if(mx<u)u=mx,r=x;
}
void gh(int x,int y){
	sz[x]=1;
	for(int i:g[x])if(mk[o][i]==_&&i!=y)gh(i,x),sz[x]+=sz[i];
	if(sz[x]==fb[o-2])p1=x,f1=y;
}
void cv(int x,int y){
	mk[o2][x]=id;
	for(int i:g[x])if(mk[o][i]==_&&i!=y)cv(i,x);
}
bool work(int x,int o){
	if(o<=3)return 1;
	u=N,n=fb[o],::o=o,_=mk[o][x],gr(x,0),p1=p2=0,gh(r,0);
	int p1=::p1,f1=::f1;
	if(p1){
		o2=o-2,++id,::o=o,_=mk[o][x],cv(p1,f1);
		if(work(p1,o-2)){
			o2=o-1,++id,::o=o,_=mk[o][x],cv(f1,p1);
			if(work(f1,o-1))return 1;
		}
	}
	return 0;
}
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	fb[0]=fb[1]=1;
	for(i=2;i<27;++i)fb[i]=fb[i-1]+fb[i-2];
	for(i=26;i;--i)if(fb[i]==n)break;
	if(!i)return puts("NO"),0;
	if(work(1,i))puts("YES");
	else puts("NO");
	return 0;
}