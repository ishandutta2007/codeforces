#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
char name[110][110];
bool connexion[42][42];
int indeg[42];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s",name+i);
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			int tp;
			for(tp=0;name[i][tp]&&name[j][tp];tp++)
			{
				if(name[i][tp]!=name[j][tp])
				{
					connexion[name[i][tp]-'a'][name[j][tp]-'a']=true;
					break;
				}
			}
			if(name[i][tp] && !name[j][tp])
			{
				puts("Impossible");
				return 0;
			}
		}
	priority_queue<int> dod;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(connexion[i][j]) indeg[j]++;
	for(int i=0;i<26;i++) if(!indeg[i]) dod.push(i);
	char ans[150];
	int ptr=0;
	while(!dod.empty())
	{
		int tmp=dod.top();
		dod.pop();
		ans[ptr++]=tmp+'a';
		for(int i=0;i<26;i++)
			if(connexion[tmp][i])
			{
				connexion[tmp][i]=false;
				indeg[i]--;
				if(!indeg[i])
					dod.push(i);
			}
	}
	ans[ptr]=0;
	if(ptr==26) puts(ans);
	else puts("Impossible");
	return 0;
}