#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
map<string,int>Map;
map<pair<int,pair<int,int> >,int>Map2;
pair<int,pair<int,int> > tp;
vector<int>Z[100001];
vector<int>E[100001];
int n,Q,i,C[100001],c,st[100001],st2[100001],b[100001],P[100001],top,ren[100001],c2,Dep[100001],R,rev_ren[100001];
bool v[100001];
struct B{
	int x,dep,a;
}O;
char p[25];
string str;
void DFS(int x){
	top=0;
	int t;
	Z[0].push_back(x);
	st[++top]=x,st2[top]=0;ren[x]=++c2;
	while(top){
		t=st[top];
		while(top&&st2[top]==E[t].size()){
			b[ren[st[top]]]=c2;
			top--;
			t=st[top];
		}
		if(!top)break;
		st[1+top]=E[t][st2[top]],st2[top]++;
		st2[++top]=0,ren[st[top]]=++c2;
		Dep[st[top]]=Dep[t]+1;
		Z[Dep[st[top]]].push_back(c2);
	}
}
int BS(int a,int dep,bool l){
	int b=0,e=Z[dep].size()-1,m,t=e+1;
	if(l)t=-1;
	while(b<=e){
		m=(b+e+1)/2;
		if(l){
			if(Z[dep][m]<=a)t=m,b=m+1;
			else e=m-1;
		}
		else{
			if(Z[dep][m]>=a)t=m,e=m-1;
			else b=m+1;
		}
	}
	return t;
}
int main()
{
	int f,l,j,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",p);
		str=p;
		if(Map[str]==0){
			Map[str]=++c;
		}
		C[i]=Map[str];
		scanf("%d",&P[i]);
		E[P[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		if(P[i]==i||P[i]==0){
			DFS(i);
		}
	}
	for(i=1;i<=n;i++)rev_ren[ren[i]]=i;
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		scanf("%d%d",&O.x,&O.dep);
		O.dep+=Dep[O.x];
		if(O.dep>n||Z[O.dep].size()==0){printf("0\n");continue;}
		tp.first=O.dep;f=tp.second.first=BS(ren[O.x],O.dep,0),l=tp.second.second=BS(b[ren[O.x]],O.dep,1);
		if(f>l){printf("0\n");continue;}
		if(Map2[tp])R=Map2[tp]-1;
		else{
			R=0;
			for(j=f;j<=l;j++){
				t=C[rev_ren[Z[O.dep][j]]];
				if(!v[t])v[t]=1,R++;
			}
			for(j=f;j<=l;j++)v[C[rev_ren[Z[O.dep][j]]]]=0;
			Map2[tp]=R+1;
		}
		printf("%d\n",R);
	}
	return 0;
}