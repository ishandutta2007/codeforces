#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 30
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,k,T,x,y,cnt,t[N+5],B[N+5],ans;vector<int> A[N+5],G[N+5],Id[N+5];map<int,int> F;
I void Make(int &x){!F[x]&&(F[x]=++cnt);x=F[x];}
I void calc(){
	re int i,j,h;scanf("%d",&n);for(i=1;i<=n;i++) A[i].clear();for(i=1;i<=cnt;i++) G[i].clear(),Id[i].clear();F.clear();m=0;cnt=0;
	for(i=1;i<=n;i++){
		scanf("%d",&t[i]);m+=t[i];for(j=1;j<=t[i];j++)scanf("%d",&x),Make(x),A[i].push_back(x); 
	}k=sqrt(m);
	for(i=1;i<=n;i++){
		if(t[i]<k) continue;for(j=0;j<t[i];j++) B[A[i][j]]=1;
		for(j=1;j<=n;j++){if(i==j) continue;
			for(ans=0,h=0;h<t[j];h++) ans+=B[A[j][h]];if(ans>=2){printf("%d %d\n",i,j);for(j=0;j<t[i];j++) B[A[i][j]]=0;return;}
		} 
		for(j=0;j<t[i];j++) B[A[i][j]]=0;
	}
	for(i=1;i<=n;i++){
		if(t[i]>=k) continue;
		for(j=0;j<A[i].size();j++){
			for(h=j+1;h<A[i].size();h++) G[min(A[i][j],A[i][h])].push_back(max(A[i][j],A[i][h])),Id[min(A[i][j],A[i][h])].push_back(i);
		}
	}
	for(i=1;i<=cnt;i++){
		for(j=0;j<G[i].size();j++) {
			if(B[G[i][j]]){printf("%d %d\n",B[G[i][j]],Id[i][j]);for(j=0;j<G[i].size();j++) B[G[i][j]]=0;return;}B[G[i][j]]=Id[i][j];
		}
		for(j=0;j<G[i].size();j++) B[G[i][j]]=0;
	}printf("-1\n");
} 
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--)calc();
}