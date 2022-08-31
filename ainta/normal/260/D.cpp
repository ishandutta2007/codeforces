#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,heap[2][100001],w[100001],top[2],t,m;
struct CMP{
	bool operator()(int p,int q){
		return w[p]>w[q];
	}
};
int main()
{
	int a;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&w[i]);
		heap[a][top[a]++]=i;
	}
	make_heap(heap[0],heap[0]+top[0],CMP());
	make_heap(heap[1],heap[1]+top[1],CMP());
	for(i=0;i<n-1;i++){
		t=0,m=w[heap[0][0]];if(m>w[heap[1][0]])t=1,m=w[heap[1][0]];
		if(!top[t])t=1-t;
		printf("%d %d %d\n",heap[t][0],heap[1-t][max(0,top[1-t]-1)],m);
		pop_heap(heap[t],heap[t]+top[t]--,CMP());
		if(top[1-t]){
			w[heap[1-t][top[1-t]-1]]-=m;
			push_heap(heap[1-t],heap[1-t]+top[1-t],CMP());}
	}
}