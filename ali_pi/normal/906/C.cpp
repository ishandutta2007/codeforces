#include <bits/stdc++.h>

#define rep(i,s,t) for(int i=s;i<=(t);++i)
using namespace std;

const int N=23,S=1<<N;
int n,m,g[S],f[S],c[S],ans=N,all,sol;

int main(int argc,char *argv[]){
	cin>>n>>m; 
	all=(1<<n)-1;
	if(m==n*(n-1)/2)
	   return cout<<0<<endl,0; 
	rep(i,1,m){ 
	    int u,v; 
	    cin>>u>>v;
	    --u,--v; 
	    g[1<<u]|=(1<<v); 
	    g[1<<v]|=(1<<u); 
	}
	rep(i,0,n-1)g[1<<i]|=1<<i;
	c[0]=0;
	rep(s,1,(1<<n)-1)c[s]=c[s>>1]+(s&1);
	rep(i,0,n-1)f[1<<i]=1;
	rep(s,1,(1<<n)-1)
	if(f[s]){
		rep(j,0,n-1)
		if((s>>j)&1)g[s]|=g[1<<j];	
		rep(j,0,n-1)
		if((g[s]>>j)&1)f[s|(1<<j)]=1;
		    if(g[s]==all)
		       if(c[s]<ans)ans=c[s],sol=s;
	}
	cout<<ans<<endl; 
	rep(i,0,n-1)
	if((sol>>i)&1)
	   cout<<i+1<<" ";
}