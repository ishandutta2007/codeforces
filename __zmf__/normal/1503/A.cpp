//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,cnt,pp,a[200009],b[200009],cnt1,cnt2; 
char s[200009];
inline int check()
{
	int now=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]==0)now++;
		else now--;
		if(now<0)return 0;
	}
	return 1;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		cnt=0;cnt1=0,cnt2=0;
		n=read();pp=n/2;
		cin>>s;
		for(int i=0;i<n;i++)
			if(s[i]=='0')cnt++;
		if(cnt%2==1)
		{
			puts("NO");
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				cnt1++;
				if(cnt1<=(n-cnt)/2)a[i]=b[i]=0;//0 (
				else a[i]=b[i]=1;
			}
			else
			{
				cnt2++;
				if(cnt2%2==1)a[i]=0,b[i]=1;
				else a[i]=1,b[i]=0;
			}
		}
	//	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	//	cout<<endl;
	//	for(int i=0;i<n;i++)cout<<b[i]<<" ";
		if(!check())puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<n;i++)
				if(a[i]==0)putchar('(');
				else putchar(')');
			puts("");
			for(int i=0;i<n;i++)
				if(b[i]==0)putchar('(');
				else putchar(')');
			puts("");
		}
	}
	return 0;
}