#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n,m,d[N],f[N];
bool b[N];
basic_string<int>g[N];
deque<int>q;
int main(){
	int i,j,s,t;
	scanf("%d%d",&n,&m);
	while(m--)scanf("%d%d",&i,&j),g[j]+=i,++d[i];
	scanf("%d%d",&s,&t),memset(f,9,sizeof f),f[t]=0,q={t};
	while(q.size()){
		if(i=q.front(),q.pop_front(),b[i])continue;
		b[i]=1;
		for(int j:g[i])if(--d[j]){
			if(f[j]>f[i]+1)f[j]=f[i]+1,q.push_back(j);
		}else if(f[j]>f[i])f[j]=f[i],q.push_front(j);
	}
	if(f[s]>N)puts("-1");else printf("%d",f[s]);
	return 0;
}