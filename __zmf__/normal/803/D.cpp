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
int k,n,a[1000009],now,sum,maxn;
char ch;
inline bool check(int x)
{
//	cout<<x<<endl;
	int now=1,pp=k,qq=x;
	while(now<=n)
	{
		if(qq>=a[now])qq-=a[now];
		else if(pp>1)pp--,qq=x-a[now];
		else return 0;
		//if(x==7)cout<<now<<" "<<pp<<" "<<qq<<endl;
		now++;
	}
	return 1;
}
int main()
{
	k=read();
	ch=getchar();
	while((ch<'a'||ch>'z')&&((ch<'A')||(ch>'Z'))&&ch!='-'&&ch!=' ')
		ch=getchar();
	while(ch)
	{
		if(ch>='a'&&ch<='z')now++;
		else if(ch>='A'&&ch<='Z')now++;
		else if(ch=='-'||ch==' ')now++,a[++n]=now,now=0;
		else break;
		ch=getchar();
	}
	if(now!=0)a[++n]=now;
//	cout<<"qwq"<<endl;
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)sum+=a[i],maxn=max(maxn,a[i]);
	int l=maxn,r=sum;
	while(l<r)
	{
		int mid=(l+r)/2;	
		if(!check(mid))l=mid+1;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}