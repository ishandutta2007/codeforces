/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,d[1010],dsu[1010],sz[1010],p[1010],r[1010];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){
	// printf("merge:%d,%d\n",x,y);
	x=find(x),y=find(y);
	if(x==y)return;
	dsu[x]=y,sz[y]+=sz[x],d[y]+=d[x];
}
int query(int x){
	printf("? %d\n",x),fflush(stdout);
	scanf("%d",&x);
	return x;
}
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]),r[i]=d[i],dsu[i]=p[i]=i,sz[i]=1;
	sort(p+1,p+n+1,[](const int&u,const int&v){return d[u]>d[v];});
	for(int i=1;i<=n;i++){
		// printf("%d %d %d %d\n",p[i],find(p[i]),sz[find(p[i])],d[find(p[i])]);
		while(d[find(p[i])]>sz[find(p[i])]*sz[find(p[i])]&&r[p[i]]){
			r[p[i]]--;
			int j=query(p[i]);
			merge(p[i],j);
		}
	}
	putchar('!');for(int i=1;i<=n;i++)printf(" %d",find(i));puts(""),fflush(stdout);
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}