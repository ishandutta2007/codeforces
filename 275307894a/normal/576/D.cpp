#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 150
#define K 50
#define mod 998244353
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,D[N+5],Ans=2e9,x;
struct Ques{int x,y,z;}S[N+5]; I bool cmp(Ques x,Ques y){return x.z<y.z;} 
struct matrix {
	bitset<N+5> F1[N+5],F2[N+5];I void Get(int x,int y){F1[x][y]=F2[y][x]=1;}
	matrix operator *(const matrix &B)const{
		matrix C;RI i,j;for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) C.F1[i][j]=C.F2[j][i]=(F1[i]&B.F2[j]).any();
		}return C;
	}
}Bas,ToT,Pus;queue<int> Q;
struct yyy{int to,z;}tmp;struct ljb{int head,h[N+5];yyy f[N+5];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);for(i=1;i<=m;i++) scanf("%d%d%d",&S[i].x,&S[i].y,&S[i].z);sort(S+1,S+m+1,cmp);for(i=1;i<=n;i++) ToT.Get(i,i);
	for(i=1;i<=m&&S[i].z<Ans;i++){
		x=S[i].z-S[i-1].z;Pus=Bas;while(x) x&1&&(ToT=ToT*Pus,0),x>>=1,Pus=Pus*Pus;Bas.Get(S[i].x,S[i].y);s.add(S[i].y,S[i].x);Me(D,0x3f);D[n]=0;Q.push(n);
		while(!Q.empty()) for(x=Q.front(),Q.pop(),j=s.h[x];j;j=tmp.z) tmp=s.f[j],D[tmp.to]>D[x]+1&&(Q.push(tmp.to),D[tmp.to]=D[x]+1);for(j=1;j<=n;j++) ToT.F1[1][j]&&D[j]<=n&&(Ans=min(Ans,D[j]+S[i].z));
	}if(Ans==2e9) puts("Impossible");else printf("%d\n" ,Ans);
}