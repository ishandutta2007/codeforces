#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a[202000],b[202000],l[202000],r[202000],used[202000];

vector<int>G[202000];
int deg[202000],q[202000],he,ta;

struct P{
	int id,st,en;
}p[202000];
bool cp(P p1,P p2){
	return p1.st<p2.st;
}
struct cmp{
	bool operator ()(P p1,P p2){
		return p1.en>p2.en;
	}
};
priority_queue<P,vector<P>,cmp>pq;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if (k>n) return 0*puts("-1");
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		used[a[i]]=1;
		b[i]=a[i];
		if (b[i]){
			l[i]=r[i]=a[i];
		}else{
			l[i]=1;r[i]=k;
		}
	}
	int x,y;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		deg[y]++;
	}
	he=ta=0;
	for (int i=1;i<=n;i++){
		if (!deg[i])
			q[++ta]=i;
	}
	int now;
	for (;he<ta;){
		now=q[++he];
		for (int i=0;i<(int)G[now].size();i++){ 
			y=G[now][i];
			if (!--deg[y])
				q[++ta]=y;
		}
	}
	if (ta<n) return 0*printf("-1");
	
	for (int j=1;j<=n;j++){
		now=q[j];
		for (int i=0;i<(int)G[now].size();i++){ 
			y=G[now][i];
			r[y]=min(r[y],r[now]-1);
		}
	}
	for (int j=n;j>0;j--){
		now=q[j];
		for (int i=0;i<(int)G[now].size();i++){ 
			y=G[now][i];
			l[now]=max(l[now],l[y]+1);
			if (l[now]>r[now]) return 0*printf("-1");
		}
	}
	for (int i=1;i<=n;i++){
		p[i]=(P){i,l[i],r[i]};
	}
	sort(p+1,p+n+1,cp);
	//for (int i=1;i<=n;i++)printf("%d::%d-%d\n",i,l[i],r[i]);
	int pos=0,fl;
	for (int i=1;i<=k;i++){
		while (pos<n&&p[pos+1].st<=i) pq.push(p[++pos]);
		fl=used[i];
		for (;!pq.empty();){
			if (pq.top().en==i||!fl){
				a[pq.top().id]=i;
				pq.pop();
			}else{
				break;
			}
			fl=1;
		}
		if (!fl) return 0*printf("-1");
	}
	//printf("\n(%d)\n",pos);
	//for (int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
	
	for (int j=1;j<=n;j++){
		now=q[j];
		for (int i=0;i<(int)G[now].size();i++){ 
			y=G[now][i];
			a[y]=min(a[y],a[now]-1);
		}
		if (b[now]&&a[now]!=b[now]) return 0*printf("-1");
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
}