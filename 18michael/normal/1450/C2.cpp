#include<bits/stdc++.h>
using namespace std;
int n,t,Test_num;
int O[3],X[3];
char s[302][302];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),t=0;
		for(int i=0;i<3;++i)O[i]=X[i]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=n;++j)
			{
				if(s[i][j]=='O')++O[(i+j)%3];
				else if(s[i][j]=='X')++X[(i+j)%3];
			}
		}
		if(O[1]+X[2]<O[t]+X[t+1])t=1;
		if(O[2]+X[0]<O[t]+X[t+1])t=2;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if((i+j)%3==t && s[i][j]=='O')s[i][j]='X';
				else if((i+j)%3==(t+1)%3 && s[i][j]=='X')s[i][j]='O';
				printf("%c",s[i][j]);
			}
			puts("");
		}
	}
	return 0;
}