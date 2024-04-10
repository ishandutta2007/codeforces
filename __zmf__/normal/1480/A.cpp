#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n;
char a[59];
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		cin>>a;
		n=strlen(a);
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
			{
				if(a[i]=='a')a[i]='b';
				else a[i]='a';
			}
			else 
			{
				if(a[i]=='z')a[i]='y';
				else a[i]='z';
			}
		}
		cout<<a<<endl;
	}
	return 0;
}