#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int he[N],to[N],ne[N],d[N],a[N];
int Ne[N],To[N],He[N];
priority_queue<pair<int,int> >q;
bool f[N];
int main(){
	int n,m,i,j,k,t=0,ans=0,ans2=0;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j);
		ne[++t]=he[j],to[t]=i,he[j]=t;
		Ne[t]=He[i],To[t]=j,He[i]=t;
	}
	scanf("%d",&k);
	for(i=1;i<=k;++i)scanf("%d",a+i); 
	memset(d,63,sizeof(d)),d[a[k]]=0,q.push(make_pair(0,a[k]));
	while(!q.empty()){
		i=q.top().second,q.pop();
		if(f[i])continue;
		f[i]=1;
		for(j=he[i];j;j=ne[j]){
			if(d[to[j]]>d[i]+1)d[to[j]]=d[i]+1,q.push(make_pair(-d[to[j]],to[j]));
		}
	}
	for(i=1;i<k;++i){
		for(j=He[a[i]];j;j=Ne[j]){
			if(To[j]==a[i+1])continue;
			if(d[To[j]]<=d[a[i+1]]){
				++ans;
				break;
			}
		}
		for(j=He[a[i]];j;j=Ne[j]){
			if(To[j]==a[i+1])continue;
			if(d[To[j]]<d[a[i+1]]){
				++ans2;
				break;
			}
		}
	}
	printf("%d %d",ans2,ans);
	return 0;
}//