//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,ans=1e9+7,x,y,z,cnt[200],pos;
char a[200009],pp[7],qq[7],rr[7];
signed main()
{
	n=read();cin>>a;
	pp[1]='R',pp[2]='R',pp[3]='G',pp[4]='G',pp[5]='B',pp[6]='B';
	qq[1]='G',qq[2]='B',qq[3]='R',qq[4]='B',qq[5]='R',qq[6]='G';
	rr[1]='B',rr[2]='G',rr[3]='B',rr[4]='R',rr[5]='G',rr[6]='R';
	for(int i=1;i<=6;i++)
	{
		int now=0;
		for(int j=0;j<n;j++)
		{
			if(j%3==0&&a[j]!=pp[i])now++;
			if(j%3==1&&a[j]!=qq[i])now++;
			if(j%3==2&&a[j]!=rr[i])now++;
		}
		if(now<ans)pos=i,ans=now;
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)putchar(pp[pos]);
		if(i%3==1)putchar(qq[pos]);
		if(i%3==2)putchar(rr[pos]);
	}
	return 0;
}