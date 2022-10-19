#include<bits/stdc++.h>
using namespace std;
int n,m,res=0x3f3f3f3f;
struct Matrix{
	bitset<160>a[160];
	bitset<160>&operator[](const int&x){return a[x];}
	Matrix(){for(int i=1;i<=n;i++)a[i].reset();} 
	friend Matrix operator*(Matrix&u,Matrix&v){
		Matrix w;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(u[i].test(k))w[i]|=v[k];
		return w;
	}
	void ksm(Matrix&u,int v){
		Matrix w=u;
		for(;v;v>>=1,w=w*w)if(v&1)(*this)=(*this)*w;
	}
	void print(){for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d",a[i].test(j));}
}F,G;
struct node{
	int x,y,z;
	friend bool operator<(const node&u,const node&v){return u.z<v.z;}
	void read(){scanf("%d%d%d",&x,&y,&z);}
}e[200];
int dep[200];
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)e[i].read();
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)F[i].set(i);
	for(int i=1;i<=m;i++){
		F.ksm(G,e[i].z-e[i-1].z);
//		F.print();
		G[e[i].x].set(e[i].y);
		memset(dep,-1,sizeof(dep));
		for(int j=1;j<=n;j++)if(F[1].test(j))dep[j]=0,q.push(j);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int y=1;y<=n;y++)if(G[x].test(y)&&dep[y]==-1)q.push(y),dep[y]=dep[x]+1;
		}
		if(dep[n]!=-1)res=min(res,dep[n]+e[i].z);
	}
	if(res==0x3f3f3f3f)puts("Impossible");else printf("%d\n",res);
	return 0;
}