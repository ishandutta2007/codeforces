#include<cstdio>
int n,m,vec_t,Test_num;
int dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};
int vec[10002][6];
char s[102][102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void Rev(int x,int y,int z)
{
	s[x][y]^=1,s[x+dx[z]][y]^=1,s[x][y+dy[z]]^=1;
	++vec_t,vec[vec_t][0]=x,vec[vec_t][1]=y,vec[vec_t][2]=x+dx[z],vec[vec_t][3]=y,vec[vec_t][4]=x,vec[vec_t][5]=y+dy[z];
}
inline void Work(int sx,int sy,int ex,int ey)
{
	for(int i=sx;i<ex;i+=2)
	{
		if(s[i][sy]=='1')Rev(i,sy-1,3);
		if(s[i+1][sy]=='1')Rev(i+1,sy-1,1);
	}
	for(int i=sy;i<ey;i+=2)
	{
		if(s[sx][i]=='1')Rev(sx-1,i,3);
		if(s[sx][i+1]=='1')Rev(sx-1,i+1,2);
	}
}
inline void Solve(int x,int y)
{
	if(s[x][y]=='0' && s[x][y+1]=='0' && s[x+1][y]=='0' && s[x+1][y+1]=='1')Rev(x,y+1,2),Rev(x+1,y,1),Rev(x+1,y+1,0);
	else if(s[x][y]=='0' && s[x][y+1]=='0' && s[x+1][y]=='1' && s[x+1][y+1]=='0')Rev(x,y,3),Rev(x+1,y,1),Rev(x+1,y+1,0);
	else if(s[x][y]=='0' && s[x][y+1]=='0' && s[x+1][y]=='1' && s[x+1][y+1]=='1')Rev(x,y,3),Rev(x,y+1,2);
	else if(s[x][y]=='0' && s[x][y+1]=='1' && s[x+1][y]=='0' && s[x+1][y+1]=='0')Rev(x,y,3),Rev(x,y+1,2),Rev(x+1,y+1,0);
	else if(s[x][y]=='0' && s[x][y+1]=='1' && s[x+1][y]=='0' && s[x+1][y+1]=='1')Rev(x,y,3),Rev(x+1,y,1);
	else if(s[x][y]=='0' && s[x][y+1]=='1' && s[x+1][y]=='1' && s[x+1][y+1]=='0')Rev(x,y+1,2),Rev(x+1,y,1);
	else if(s[x][y]=='0' && s[x][y+1]=='1' && s[x+1][y]=='1' && s[x+1][y+1]=='1')Rev(x+1,y+1,0);
	else if(s[x][y]=='1' && s[x][y+1]=='0' && s[x+1][y]=='0' && s[x+1][y+1]=='0')Rev(x,y,3),Rev(x,y+1,2),Rev(x+1,y,1);
	else if(s[x][y]=='1' && s[x][y+1]=='0' && s[x+1][y]=='0' && s[x+1][y+1]=='1')Rev(x,y,3),Rev(x+1,y+1,0);
	else if(s[x][y]=='1' && s[x][y+1]=='0' && s[x+1][y]=='1' && s[x+1][y+1]=='0')Rev(x,y+1,2),Rev(x+1,y+1,0);
	else if(s[x][y]=='1' && s[x][y+1]=='0' && s[x+1][y]=='1' && s[x+1][y+1]=='1')Rev(x+1,y,1);
	else if(s[x][y]=='1' && s[x][y+1]=='1' && s[x+1][y]=='0' && s[x+1][y+1]=='0')Rev(x+1,y,1),Rev(x+1,y+1,0);
	else if(s[x][y]=='1' && s[x][y+1]=='1' && s[x+1][y]=='0' && s[x+1][y+1]=='1')Rev(x,y+1,2);
	else if(s[x][y]=='1' && s[x][y+1]=='1' && s[x+1][y]=='1' && s[x+1][y+1]=='0')Rev(x,y,3);
	else if(s[x][y]=='1' && s[x][y+1]=='1' && s[x+1][y]=='1' && s[x+1][y+1]=='1')Rev(x,y,3),Rev(x,y+1,2),Rev(x+1,y,1),Rev(x+1,y+1,0);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),vec_t=0;
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		if((n&1) && !(m&1))Work(n,1,n,m);
		else if((m&1) && !(n&1))Work(1,m,n,m);
		else if((n&1) && (m&1))
		{
			if(s[n][m]=='1')Rev(n,m,0);
			Work(n,1,n,m-1),Work(1,m,n-1,m);
		}
		for(int i=1;i<n;i+=2)
			for(int j=1;j<m;j+=2)
				Solve(i,j);
		printf("%d\n",vec_t);
		for(int i=1;i<=vec_t;++i)printf("%d %d %d %d %d %d\n",vec[i][0],vec[i][1],vec[i][2],vec[i][3],vec[i][4],vec[i][5]);
	}
	return 0;
}