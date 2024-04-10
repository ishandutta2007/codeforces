#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct A{
	int a,c,k,chk;
}tp;
vector<A>E[200001];
int n,m,i,R[200001],F[200001],Q[200001],h,t;
bool v[200001];
int main()
{
	int a,b,c,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		tp.a=b,tp.c=c,tp.k=i,tp.chk=0;
		E[a].push_back(tp);
		tp.a=a;tp.chk=1;E[b].push_back(tp);
		if(a!=1)F[a]+=c;
		if(b!=1)F[b]+=c;
	}
	for(i=2;i<n;i++)F[i]/=2;
	Q[++t]=1;v[1]=true;
	while(h<t){
		x=Q[++h];
		for(i=0;i<E[x].size();i++){
			y=E[x][i].a;
			if(!v[y]){
				R[E[x][i].k]=E[x][i].chk;
				F[y]-=E[x][i].c;
				if(!F[y]){
					v[y]=true;
					Q[++t]=y;
				}
			}
		}
	}
	for(i=1;i<=m;i++)printf("%d\n",R[i]);
}