#include<bits/stdc++.h>
using namespace std;
long long a,b,T,de[100001],fl,q,w;
string s;
bitset<3005> l[3005];
vector<long long> qu[3001];
int main()
{
	scanf("%lld",&T);
	for(int ii=1;ii<=T;ii++)
	{
		scanf("%lld%lld",&a,&b);
		for(int i=1;i<=a;i++) de[i]=0,qu[i].clear(),l[i].reset();
		for(int i=1;i<=b;i++)
		{
			scanf("%lld%lld",&q,&w);
			qu[q].push_back(w);
			qu[w].push_back(q);
			de[q]++,de[w]++;
		}
		fl=1;
		for(int i=1;i<=a;i++) if(de[i]%2!=0) fl=0;
		if(fl)
		{
			printf("1\n");
			for(int i=1;i<=a;i++) printf("1 ");
			printf("\n");
			continue;
		}
		for(int i=1;i<=a;i++)
		{
			if(de[i]&1)
			{
				for(int j=0;j<qu[i].size();j++) l[i][qu[i][j]]=1;
				l[i][i]=1;l[i][a+1]=1;
			}
			else
			{
				for(int j=0;j<qu[i].size();j++) l[i][qu[i][j]]=1;
				l[i][a+1]=0;
			}
		}
		for(int i=1;i<=a;i++)
		{
			long long ff=0;
			for(int j=i;j<=a;j++)
			{
				if(l[j][i])
				{
					ff=j;
					break;
				}
			}
			swap(l[ff],l[i]);
			for(int j=1;j<=a;j++)
			{
				long long tt=l[j][i];
				if(tt==0||i==j) continue;
				l[j]^=l[i];
			}
		}
		printf("2\n");
		for(int i=1;i<=a;i++)
		{
			if(l[i][a+1])
			{
				printf("2 ");
			}
			else printf("1 ");
		}
		printf("\n");
	}
	return 0;
}