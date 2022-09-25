#include<cstdio>
#include<queue>
using namespace std;
#define N 678901
int n,k,is[N],t[N],ti;
char s[N];
queue<int> tp,tp2;
int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)if(s[i]==s[i==1?n:i-1])is[i]=is[i==1?n:i-1]=(s[i]=='B'?1:2),tp.push(i),tp.push(i==1?n:i-1);
	for(int i=1;i<=k;i++)
	{
		if(tp.empty())break;
		ti++;
		while(!tp.empty())
		{
			int s1=tp.front();tp.pop();
			int lb=s1==1?n:s1-1,rb=s1==n?1:s1+1;
			if(!is[lb]){is[lb]=is[s1];t[lb]=ti;tp2.push(lb);}
			else if(t[lb]==ti)
			{
				if((is[s1]==1&&((s[lb]=='B'&&ti%2==1)||(s[lb]=='W'&&ti%2==0)))||(is[s1]==0&&((s[lb]=='B'&&ti%2==0)||(s[lb]=='W'&&ti%2==1))))is[lb]=is[s1];
			}
			if(!is[rb]){is[rb]=is[s1];t[rb]=ti;tp2.push(rb);}
			else if(t[rb]==ti)
			{
				if((is[s1]==1&&((s[rb]=='B'&&ti%2==1)||(s[rb]=='W'&&ti%2==0)))||(is[s1]==0&&((s[rb]=='B'&&ti%2==0)||(s[rb]=='W'&&ti%2==1))))is[rb]=is[s1];
			}
		}
		while(!tp2.empty())tp.push(tp2.front()),tp2.pop();
	}
	for(int i=1;i<=n;i++)
	if(is[i])printf("%c",is[i]==1?'B':'W');
	else printf("%c",((s[i]=='B')^(k&1))?'B':'W');
}