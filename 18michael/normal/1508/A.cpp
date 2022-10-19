#include<bits/stdc++.h>
using namespace std;
int n,n2,t,Test_num;
int cnt[3][2];
char s[3][200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int check(int x,int y)
{
	if(min(cnt[x][0],cnt[y][0])>=n)return 0;
	if(min(cnt[x][1],cnt[y][1])>=n)return 1;
	return -1;
}
inline void print(int x,int y,int z)
{
	int t1=1,t2=1,w=z,t=0;
	while(t1<=n2 && t2<=n2)
	{
		if(s[x][t1]==s[y][t2])printf("%c",s[x][t1]),++t1,++t2;
		else if(s[x][t1]-'0'!=z)printf("%c",s[x][t1]),++t1;
		else printf("%c",s[y][t2]),++t2;
	}
	while(t1<=n2)printf("%c",s[x][t1]),++t1;
	while(t2<=n2)printf("%c",s[y][t2]),++t2;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),n2=(n<<1),scanf("%s",s[0]+1),scanf("%s",s[1]+1),scanf("%s",s[2]+1);
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<2;++j)cnt[i][j]=0;
			for(int j=1;j<=n2;++j)cnt[i][0]+=(s[i][j]=='0'),cnt[i][1]+=(s[i][j]=='1');
		}
		if(~(t=check(0,1)))print(0,1,t);
		else if(~(t=check(1,2)))print(1,2,t);
		else if(~(t=check(2,0)))print(2,0,t);
		puts("");
	}
	return 0;
}