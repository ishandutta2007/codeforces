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
int n,m,k,a[200009],now,pos;
signed main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	pos=n;now=k;
	while(pos>0)
	{
		if(a[pos]<=now)now-=a[pos],pos--;
		else if(m>1)m--,now=k,now-=a[pos],pos--;
		else break;
	//	cout<<now<<" "<<m<<" "<<pos<<endl;
	}
	cout<<n-pos<<endl;
	return 0;
}