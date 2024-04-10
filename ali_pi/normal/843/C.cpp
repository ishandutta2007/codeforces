#include<bits/stdc++.h>

using namespace std;

#define N 200010

struct Edge{
	int t,nx;
}e[N<<1];

struct Node{
	int x,y,z;
	Node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
}a[N<<1];

int Num,h[N],x,y;
int i,j,k,n,m,p,f[N],s[N],S,Rt,l;
int L;
bool b[N];

inline void Add(int x,int y){
	e[++Num].t=y;e[Num].nx=h[x];h[x]=Num;
}

inline int Max(int x,int y){
	return x<y?y:x;
}

inline void Dfs(int x,int y){
	s[x]=1;
	for(int i=h[x];i;i=e[i].nx)
	if(e[i].t!=y&&!b[e[i].t]){
		Dfs(e[i].t,x);
		s[x]+=s[e[i].t];
		f[x]=Max(f[x],s[e[i].t]);
	}
	f[x]=Max(f[x],S-s[x]);
	if(f[x]<f[Rt])Rt=x;
}

inline void Dfs2(int x,int y){
	if(y!=S){
		a[++l]=Node(S,L,x);
		a[++l]=Node(x,y,k);
		L=x;
	}
	for(int i=h[x];i;i=e[i].nx)
	if(e[i].t!=y)Dfs2(e[i].t,x);
}

inline void Solve(int x,int y){
	S=x;
	for(int i=h[x];i;i=e[i].nx)
	if(e[i].t!=y){
		k=L=e[i].t;
		Dfs2(e[i].t,x);
		a[++l]=Node(x,L,k);
	}
}

int main(){
	cin>>n;
	for(i=1;i<n;i++) 
            scanf("%d%d",&x,&y),Add(x,y),Add(y,x);
	S=f[0]=n;Dfs(1,0);
	Dfs(Rt,0);x=0;
	for(i=1;i<=n;i++)
	if(i!=Rt&&s[i]*2==n)
            x=i;
	if(!x)
            Solve(Rt,0);
        else 
            Solve(Rt,x),Solve(x,Rt);
	cout<<l<<endl;
	for(i=1;i<=l;i++)
            printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
}