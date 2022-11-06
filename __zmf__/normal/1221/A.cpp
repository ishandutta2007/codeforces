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
int taxi,n,a[109],cnt;
int pown[20];
int main()
{
	taxi=read();
	pown[0]=1;
	for(int i=1;i<=11;i++)pown[i]=pown[i-1]*2;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();cnt=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=0;i<=11;i++)
		{
			cnt=cnt/2;
			for(int j=1;j<=n;j++)
				if(a[j]==pown[i])cnt++;
		}
		if(cnt>=1)puts("YES");
		else puts("NO");
	}
	return 0;
}