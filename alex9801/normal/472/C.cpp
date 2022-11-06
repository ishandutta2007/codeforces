#include <stdio.h>
#include <string>
#include <map>

#define mp(a,b) std::make_pair(a,b)

typedef std::map<std::string,std::pair<int,int> > S;

S s;
std::string ori;
int num[100000][2];
int res[100000];
char tmp[51];

int main()
{
	int n,c=0,p,t,i;
	S::iterator it;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",tmp);
		ori=tmp;
		s[ori]=mp(i,0);
		scanf("%s",tmp);
		ori=tmp;
		s[ori]=mp(i,1);
	}
	for(i=0;i<n;i++)
		scanf("%d",&res[i]);
	it=s.begin();
	while(it!=s.end())
	{
		num[(*it).second.first][(*it).second.second]=c++;
		it++;
	}
	for(i=0;i<n;i++)
	{
		if(num[i][0]>num[i][1])
		{
			t=num[i][0];
			num[i][0]=num[i][1];
			num[i][1]=t;
		}
	}
	p=num[res[0]-1][0];
	for(i=1;i<n;i++)
	{
		if(num[res[i]-1][0]>p)
			p=num[res[i]-1][0];
		else if(num[res[i]-1][1]>p)
			p=num[res[i]-1][1];
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}