#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,i,s[100001],l[100001],c[100001],j,top,D[100001];
bool v[100001];
struct B{
	int a,b;bool operator()(B p,B q){return p.a>q.a;}
}T,heap[500001];
vector <B> V[100001];
struct A{
	int a,b,c;
	bool operator()(A p,A q){
		return p.a<q.a;}}w[200001];
int P(int a,int t){
	int b=0,e=c[a]-1,M;
	while(b<=e){
		M=(b+e+1)/2;
		if(V[a][M].a>t){e=M-1;}
		else if(V[a][M].b<t){b=M+1;}
		else return V[a][M].b+1;
	}
	return t;
}
int main()
{
	int t,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].c);
		w[m+i].a=w[i].b,w[m+i].b=w[i].a,w[m+i].c=w[i].c;}
	m*=2;
	stable_sort(w,w+m,A());
	t=w[0].a;for(i=1;i<m;i++)if(t!=w[i].a)l[t]=i,t=w[i].a,s[t]=i;l[t]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		t=-1;
		for(j=0;j<x;j++){
			scanf("%d",&z);
			if(t==-1){t=y=z;continue;}
			if(t+1==z)t++;
			else{
				T.a=y,T.b=t;
				V[i].push_back(T);
				t=-1;
			}
		}
		if(t!=-1){
			T.a=y,T.b=t;
			V[i].push_back(T);}
		c[i]=V[i].size();
	}
	for(i=1;i<=n;i++)D[i]=1999999999;
	heap[top].a=0,heap[top++].b=1;D[1]=0;
	while(top&&!v[n]){
		while(top&&v[heap[0].b]){pop_heap(heap,heap+top,B());top--;}
		if(!top)break;
		T=heap[0];pop_heap(heap,heap+top,B());top--;
		v[T.b]=true;
		x=T.b;y=P(x,D[x]);
		for(i=s[x];i<l[x];i++){
			if(D[w[i].b]>y+w[i].c){
				D[w[i].b]=y+w[i].c;
				heap[top].a=y+w[i].c,heap[top++].b=w[i].b;
				push_heap(heap,heap+top,B());
			}
		}
	}
	if(!v[n]){printf("-1\n");}
	else printf("%d\n",D[n]);
}