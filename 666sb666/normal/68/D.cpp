#include<cstdio>
#include<map>
using namespace std;
map<int,long long> mp;
int h,q;
char s[10];
int main()
{
	scanf("%d%d",&h,&q);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='a')
		{
			int x,y;scanf("%d%d",&x,&y);
			while(x)mp[x]+=y,x/=2;
		}
		if(s[0]=='d')
		{
			long long tmp=0,now=0;
			int x=1;
			for(int i=1;i<=h;i++)
			{
				tmp+=max(now,mp[x]-min(mp[2*x],mp[2*x+1]))*(1<<(h-i));
				now=max(now,mp[x]-max(mp[2*x],mp[2*x+1]));
				if(mp[2*x]>mp[2*x+1])x=2*x;else x=2*x+1;
			}
			tmp+=max(mp[x],now);
			printf("%.10lf\n",(double)tmp/(1<<h));
		}
	}
	return 0;
}