#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=500005;
const int MOD=1e9+7;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int n;
vector<int> vec[N];
int du[N];
char ss[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=n;u++) vec[u].clear(),du[u]=0;
		for (int u=1;u<n;u++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			du[x]++;du[y]++;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		scanf("%s",ss+1);int len=strlen(ss+1);
			if (n<3)	{printf("Draw\n");continue;}
		for (int u=1;u<=len;u++)
		{
			if (ss[u]=='W')	{n++;vec[u].push_back(n);vec[n].clear();vec[n].push_back(u);du[n]=3;du[u]++;}
		}
		bool tf=false;
		int o=0;
		for (int u=1;u<=n;u++)
		{
			if (du[u]>=4)	{tf=true;break;}
			else if (du[u]==3)
			{
				int cnt=0;
				int siz=vec[u].size();
				for (int i=0;i<siz;i++)
				{
					int y=vec[u][i];
					cnt=cnt+(du[y]>=2);
				}
				if (cnt>=2) {tf=true;break;}
				o++;
			}
		}
		if (o==2&&(n&1)) tf=true;
		if (tf) printf("White\n");
		else printf("Draw\n");
	}
	return 0;
}