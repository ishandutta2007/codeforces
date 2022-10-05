#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=4e5+3,P=998244353,O=9e6+3;
int he[2][N],to[2][N],ne[2][N],d[N],g[N],q2[N];
long long d2[O];
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
queue<int>q;
int hh[O],tt[O],nn[O],len[O],tot;
void add(int x,int y,int z){
	nn[++tot]=hh[x],tt[tot]=y,len[tot]=z,hh[x]=tot;
}
struct P2{
	int x;
	long long y;
	bool operator<(P2 a)const{return y>a.y;}
};	
#define pq __gnu_pbds::priority_queue<P2,less<P2>,__gnu_pbds::pairing_heap_tag>
pq Q;
pq::point_iterator id[O];
int main(){
	long long l;
	int n,m,i,j,k,s,t1=0,t2=0,tq=0;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j);
		ne[0][++t1]=he[0][i],to[0][t1]=j,he[0][i]=t1;
		ne[1][++t2]=he[1][j],to[1][t2]=i,he[1][j]=t2;
	}
	memset(d,-1,sizeof(d)),q.push(1),q2[++tq]=1,d[1]=0,i=0,s=0,g[1]=0;
	while(d[n]==-1){
		while(!q.empty()){
			j=q.front(),q.pop();
			for(k=he[i][j];k;k=ne[i][k]){
				l=to[i][k];
				if(d[l]==-1)d[l]=s,q.push(l),q2[++tq]=l,g[l]=g[j]+1;
			}
		}
		i^=1,++s;
		for(j=1;j<=tq;++j)q.push(q2[j]);
		tq=0;
	}
	if(d[n]<20){
		for(i=0;i<20;++i){
			j=i&1;
			for(k=1;k<=n;++k)for(l=he[j][k];l;l=ne[j][l]){
				add(k+n*i,to[j][l]+n*i,1);
			}
		}
		for(i=0;i<19;++i)for(k=1;k<=n;++k)add(k+n*i,k+n*(i+1),1<<i);
		memset(d2,63,sizeof(d2)),d2[1]=0,id[1]=Q.push({1,0});
		while(!Q.empty()){
		i=Q.top().x,Q.pop();
		for(j=hh[i];j;j=nn[j])if(d2[k=tt[j]]>(l=len[j]+d2[i])){
			d2[k]=l;
			if(id[k]!=0)Q.modify(id[k],{k,l});
			else id[k]=Q.push({k,l});
		}
		}
		long long k=2e18;
		for(i=0;i<20;++i)k=min(k,d2[n+n*i]);
		printf("%lld",k);
	}
		
	else{
		for(j=0;j<2;++j)
		{
			for(k=1;k<=n;++k)for(l=he[j][k];l;l=ne[j][l]){
				add(k+n*j,to[j][l]+n*j,1);
			}
		}
		for(k=1;k<=n;++k)add(k,k+n,1000000),add(k+n,k,1000000);
		memset(d2,63,sizeof(d2)),d2[1]=0,id[1]=Q.push({1,0});
		while(!Q.empty()){
		i=Q.top().x,Q.pop();
		for(j=hh[i];j;j=nn[j])if(d2[k=tt[j]]>(l=len[j]+d2[i])){
			d2[k]=l;
			if(id[k]!=0)Q.modify(id[k],{k,l});
			else id[k]=Q.push({k,l});
		}
		}
		long long ans=min(d2[n],d2[n*2]),o=1;
		for(int i=1;i<=d[n];++i)o=o*2ll%P,ans=(ans-1000000)%P;
		printf("%lld",((ans+o-1)%P+P)%P);
	}
	return 0;
}