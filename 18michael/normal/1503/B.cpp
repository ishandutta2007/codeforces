#include<bits/stdc++.h>
using namespace std;
int n,c,ac,bc,laax,laay,labx,laby,ok;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int a[102][102]={};
typedef pair<int,int> P;
queue<P> qa,qb,q;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void solve(int t,int x)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(!a[i][j])
				q.push(P(i,j));
	for(;;)
	{
		if(c!=3)c=3;else if(x==1)c=2;else c=1;
		cout<<c<<" "<<q.front().first<<" "<<q.front().second<<endl<<endl,q.pop(),fflush(stdout);
		if(!(--t))return ;
		cin>>c;
	}
}
int main()
{
	cin>>n,ac=1,bc=2,laax=1,laay=1,labx=1,laby=2;
	for(int T=n*n;T;--T)
	{
		cin>>c,ok=0;
		if(c==ac)
		{
			while(laax<=n)
			{
				if(!a[laax][laay])
				{
					cout<<bc<<" "<<laax<<" "<<laay<<endl<<endl,fflush(stdout),a[laax][laay]=bc,ok=1;
					break;
				}
				laay+=2;if(laay>n)++laax,laay=((laax&1)? 1:2);
			}
			if(ok)continue;
			solve(T,bc);
			break;
		}
		while(labx<=n)
		{
			if(!a[labx][laby])
			{
				cout<<ac<<" "<<labx<<" "<<laby<<endl<<endl,fflush(stdout),a[labx][laby]=ac,ok=1;
				break;
			}
			laby+=2;if(laby>n)++labx,laby=((labx&1)? 2:1);
		}
		if(ok)continue;
		solve(T,ac);
		break;
	}
	return 0;
}