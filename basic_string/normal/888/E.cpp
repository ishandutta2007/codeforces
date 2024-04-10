#include<bits/stdc++.h>
using namespace std;
int n,m,p,c[39];
basic_string<int>a,b;
void dfs1(int x,int y){
	if(x==m)return void(a+=y);
	dfs1(x+1,y),dfs1(x+1,(y+c[x])%p);
}
void dfs2(int x,int y){
	if(x==n)return void(b+=y);
	dfs2(x+1,y),dfs2(x+1,(y+c[x])%p);
}
int main(){
	int i,l,s=0;
	scanf("%d%d",&n,&p),m=n/2;
	for(i=0;i<n;++i)scanf("%d",c+i);
	dfs1(0,0),dfs2(m,0);
	sort(a.begin(),a.end()),sort(b.begin(),b.end()),l=b.size()-1;
	for(auto i:a){
		while(l&&i+b[l]>=p)--l;
		s=max(s,max((i+b[l])%p,(i+b.back())%p));
	}
	printf("%d",s);
	return 0;
}