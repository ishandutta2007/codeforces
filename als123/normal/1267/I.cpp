#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N=205;
int T,n;
int a[N],b[N],nn,c[N];
string ss;
bool cmp (int x,int y)
{
	cout<<"?"<<" "<<x<<" "<<y<<"\n";
	cin>>ss;
	if (ss[0]=='<') return false;
	return true;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		nn=0;
		cin>>n;n*=2;
		for (int u=1;u<=n;u+=2)
		{
			if (cmp(u,u+1)==false)	{a[++nn]=u+1;b[nn]=u;}
			else {a[++nn]=u;b[nn]=u+1;}
		}
		for (int u=1;u<=nn;u++)
		for (int i=u+1;i<=nn;i++) if (cmp(b[u],b[i])==false)
		swap(b[u],b[i]);
		int t;
		if (b[1]&1) t=b[1]+1;
		else t=b[1]-1; 
		//printf("%d %d\n",t,b[1]);
		for (int u=1;u<=nn;u++)
		{
			if (a[u]==t) continue;
			for (int i=u+1;i<=nn;i++) 
			{
				if (a[i]==t) continue;
				if (cmp(a[u],a[i])==false)
				swap(a[u],a[i]);
			}
		}
	//	printf("YES:%d\n",a[nn]);
		int now=nn,now1=nn;
		for (int u=1;u<=nn;u++)
		{
			if (a[now]==t) now--;
			if (cmp(a[now],b[now1])==false) now--;
			else now1--;
		}
		cout<<"!"<<"\n";
	}
	return 0;
}