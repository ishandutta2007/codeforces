#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;
ll c=0;
char str1[MAXN],str2[MAXN];
int a[MAXN],b[MAXN];
int d[MAXN];

int cnt,resx[MAXN],rest[MAXN];
void print()
{
	cout<<c<<endl;
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",resx[i],rest[i]);
}
void work(int x,int t)
{
	a[x]+=t;a[x+1]+=t;
	resx[++cnt]=x;rest[cnt]=t;
	if(cnt==100000){print();exit(0);}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	scanf("%d%s%s",&n,str1+1,str2+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=str1[i]-'0',b[i]=str2[i]-'0';
		d[i]=b[i]-a[i]-d[i-1];
		c+=abs(d[i]);
	}
	if(d[n])return 0*printf("-1\n");
	for(int i=1;i<n;i++)
	{
		while(a[i]<b[i])
		{
			if(a[i+1]<9)work(i,1);
			else
			{
				int pos=0,f=-1;
				for(int j=i+1;j<n;f=-f,j++)
				{
					if((f<0 && !a[j+1]) || (f>0 && a[j+1]==9))continue;
					pos=j;break;
				}
				for(int j=pos;j>=i;j--,f=-f)
					work(j,f);
			}
		}
		while(a[i]>b[i])
		{
			if(a[i+1]>0)work(i,-1);
			else
			{
				int pos=0,f=1;
				for(int j=i+1;j<n;f=-f,j++)
				{
					if((f<0 && !a[j+1]) || (f>0 && a[j+1]==9))continue;
					pos=j;break;
				}
				for(int j=pos;j>=i;j--,f=-f)
					work(j,f);
			}
		}
	}
	print();
	return 0;
}