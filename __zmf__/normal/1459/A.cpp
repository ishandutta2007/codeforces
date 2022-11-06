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
char a[10009],b[10009];
int a1,b1;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		a1=0,b1=0;
		n=read();
		cin>>a;cin>>b;
		for(int i=0;i<n;i++)
		{
			if(a[i]>b[i])a1++;
			else if(a[i]<b[i])b1++;
		}
		if(a1>b1)cout<<"RED"<<endl;
		else if(a1<b1)cout<<"BLUE"<<endl;
		else cout<<"EQUAL"<<endl;
	}
	return 0;
}