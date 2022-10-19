#include<bits/stdc++.h>
using namespace std;
int Test_num,l,t;
char s[300002];
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
		scanf("%s",s),l=strlen(s),t=-1;
		for(int i=0;i<l;++i)if(s[i]!='a'){t=l-i;break;}
		if(~t)
		{
			puts("YES");
			for(int j=0;j<t;++j)printf("%c",s[j]);
			putchar('a');
			for(int j=t;j<l;++j)printf("%c",s[j]);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}