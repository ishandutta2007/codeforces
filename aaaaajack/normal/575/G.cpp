#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cassert>
#include<algorithm>
#define N 100100
using namespace std;
int rk[N],fr[N],d[N],num[N],in[N],go[N];
vector<int> to[N],len[N],buf;
bool cmp(int a,int b){
	return d[a]<d[b]||d[a]==d[b]&&rk[fr[a]]<rk[fr[b]];
}
int main(){
	int n,m,x,y,z,pr,pn;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&x,&y,&z);
		to[x].push_back(y);
		to[y].push_back(x);
		len[x].push_back(z);
		len[y].push_back(z);
	}
	num[0]=0;
	in[0]=1;
	buf.push_back(0);
	pr=0;
	pn=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		if(num[u]>=pn){
			if(num[u]) sort(buf.begin(),buf.end(),cmp);
			rk[buf[0]]=++pr;
			for(int i=1;i<buf.size();i++){
				if(cmp(buf[i-1],buf[i])) rk[buf[i]]=++pr;
				else rk[buf[i]]=pr;
			}
			pn++;
			buf.clear();
		}
		q.pop();
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i];
			if(!in[v]||num[v]>=num[u]+1){
				num[v]=num[u]+1;
				if(!in[v]){
					fr[v]=u;
					d[v]=len[u][i];
					in[v]=1;
					q.push(v);
					buf.push_back(v);
				}
				else if(len[u][i]<d[v]||len[u][i]==d[v]&&rk[u]<rk[fr[v]]){
					d[v]=len[u][i];
					fr[v]=u;
				}
			}
		}
	}
	memset(in,0,sizeof(in));
	q.push(n-1);
	in[n-1]=1;
	x=n-1;
	while(!q.empty()){
		int u=q.front();
		if(rk[u]<rk[x]) x=u;
		q.pop();
		for(int i=0;i<to[u].size();i++){
			if(!len[u][i]){
				if(!in[to[u][i]]){
					go[to[u][i]]=u;
					in[to[u][i]]=1;
					q.push(to[u][i]);
				}
			}
		}
	}
	vector<int> av,al;
	for(int u=x;u!=n-1;u=go[u]) av.push_back(go[u]);
	reverse(av.begin(),av.end());
	for(int u=x;u;u=fr[u]){
		av.push_back(u);
		al.push_back(d[u]);
	}
	if(al.empty()) printf("0");
	for(int i=0;i<al.size();i++) printf("%d",al[i]);
	printf("\n%d\n0",(int)av.size()+1);
	for(int i=av.size()-1;i>=0;i--) printf(" %d",av[i]);
	printf("\n");
	return 0;
}