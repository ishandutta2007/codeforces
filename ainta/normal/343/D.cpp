#include<stdio.h>
#include<vector>
#include<algorithm>
#define SZ 524288
using namespace std;
struct SegTree{
	int Sum,CK;
}ST[1000010];
vector<int>E[500010];
int n,ren[500010],ed[500010],C,top,Q,T1[SZ*2],T2[SZ*2];
bool v[500010];
struct stack{
	int a,b;
}st[500010];
void Ins(int a){
	v[a]=true;
	st[++top].a=a;
	st[top].b=0;
	ren[a]=++C;
}
void DFS(int a){
	Ins(a);
	while(1){
		while(top){
			while(st[top].b!=E[st[top].a].size()){
				if(v[E[st[top].a][st[top].b]])st[top].b++;
				else break;
			}
			if(st[top].b!=E[st[top].a].size())break;
			ed[ren[st[top].a]]=C;
			top--;
		}
		if(!top)break;
		Ins(E[st[top].a][st[top].b]);
		st[top-1].b++;
	}
}
void Add(int a,int b,int c){
	while(a<=b){
		T1[a]=T1[b]=c;
		a=(a+1)>>1,b=(b-1)>>1;
	}
}
void Del(int a,int c){
	while(a){
		T2[a]=c;
		a=a>>1;
	}
}
bool chk(int a,int b){
	int x=a,M1=0,M2=0;
	while(x){
		if(M1<T1[x])M1=T1[x];
		x>>=1;
	}
	while(a<=b){
		if(M2<T2[a])M2=T2[a];
		if(M2<T2[b])M2=T2[b];
		a=(a+1)>>1;
		b=(b-1)>>1;
	}
	return M1>M2;
}
int main()
{
	int i,a,b,c=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1);
	scanf("%d",&Q);
	while(Q--){
		c++;
		scanf("%d%d",&a,&b);
		if(a==1){
			Add(SZ+ren[b],SZ+ed[ren[b]],c);
		}
		if(a==2){
			Del(SZ+ren[b],c);
		}
		if(a==3){
			printf("%d\n",chk(SZ+ren[b],SZ+ed[ren[b]]));
		}
	}
}