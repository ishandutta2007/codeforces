#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int len,t=0;
int la[200002];
char ch[200002];
queue<int> q0,q1;
vector<int> vec[200002];
int main()
{
	scanf("%s",ch+1),len=strlen(ch+1);
	for(int i=1;i<=len;++i)
	{
		if(ch[i]=='0')
		{
			if(!q1.empty())la[i]=q1.front(),q1.pop(),q0.push(i);
			else la[i]=0,q0.push(i);
		}
		else
		{
			if(!q0.empty())la[i]=q0.front(),q0.pop(),q1.push(i);
			else return 0&puts("-1");
		}
	}
	if(!q1.empty())return 0&puts("-1");
	for(int i=1;i<=len;++i)
	{
		if(!la[i])la[i]=(++t);
		else la[i]=la[la[i]];
		vec[la[i]].push_back(i);
	}
	printf("%d\n",t);
	for(int i=1;i<=t;++i)
	{
		printf("%d ",vec[i].size());
		for(int j=0;j<vec[i].size();++j)
			printf("%d%c",vec[i][j],j==vec[i].size()-1? '\n':' ');
	}
	return 0;
}