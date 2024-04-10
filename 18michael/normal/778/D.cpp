#include<cstdio>
int n,m,ok;
struct aaa
{
	int vec_t;
	int vec[1000002][2];
	char ch[52][52];
}A,B;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(aaa A)
{
	if(!(n&1))
	{
		for(int i=1;i<=n;i+=2)
			for(int j=1;j<=m;++j)
				if(A.ch[i][j]!='U' || A.ch[i+1][j]!='D')
					return 0;
		return 1;
	}
	else
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;j+=2)
				if(A.ch[i][j]!='L' || A.ch[i][j+1]!='R')
					return 0;
		return 1;
	}
}
inline void solve(aaa &A)
{
	while(!check(A))
	{
		ok=0;
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j)
			{
				if(!ok)
				{
					if(A.ch[i][j]=='L' && A.ch[i][j+1]=='R' && A.ch[i+1][j]=='L' && A.ch[i+1][j+1]=='R')ok=1;
					else if(A.ch[i][j]=='U' && A.ch[i][j+1]=='U' && A.ch[i+1][j]=='D' && A.ch[i+1][j+1]=='D')ok=-1;
				}
				if(ok==1 && A.ch[i][j]=='L' && A.ch[i][j+1]=='R' && A.ch[i+1][j]=='L' && A.ch[i+1][j+1]=='R')++A.vec_t,A.vec[A.vec_t][0]=i,A.vec[A.vec_t][1]=j,A.ch[i][j]=A.ch[i][j+1]='U',A.ch[i+1][j]=A.ch[i+1][j+1]='D';
				else if(ok==-1 && A.ch[i][j]=='U' && A.ch[i][j+1]=='U' && A.ch[i+1][j]=='D' && A.ch[i+1][j+1]=='D')++A.vec_t,A.vec[A.vec_t][0]=i,A.vec[A.vec_t][1]=j,A.ch[i][j]=A.ch[i+1][j]='L',A.ch[i][j+1]=A.ch[i+1][j+1]='R';
			}
	}
}
int main()
{
	read(n),read(m),A.vec_t=B.vec_t=0;
	for(int i=1;i<=n;++i)scanf("%s",A.ch[i]+1);
	for(int i=1;i<=n;++i)scanf("%s",B.ch[i]+1);
	solve(A),solve(B),printf("%d\n",A.vec_t+B.vec_t);
	for(int i=1;i<=A.vec_t;++i)printf("%d %d\n",A.vec[i][0],A.vec[i][1]);
	for(int i=B.vec_t;i;--i)printf("%d %d\n",B.vec[i][0],B.vec[i][1]);
	return 0;
}