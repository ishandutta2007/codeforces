#include<cstdio>
#include<set>
using namespace std;
const int MAXN = 300100;
set<int> alert[MAXN];
int data[MAXN];
int ans = 0;

int main()
{
	int N, Q;
	scanf("%d%d",&N,&Q);
	int cleartp = 0;
	int nowtp = 0;
	for(int i=0; i<Q; i++)
	{
		int t, x;
		scanf("%d", &t);
		scanf("%d", &x);
		if(t==1)
		{
			data[nowtp] = x;
			alert[x].insert(nowtp);
			nowtp++;
			ans++;
		}
		if(t==2)
		{
			ans -= alert[x].size();
			alert[x].clear();
		}
		if(t==3)
		{
			while(cleartp<x)
			{
				auto it = alert[data[cleartp]].find(cleartp);
				//printf("%d %d\n",data[cleartp],cleartp);
				if(it != alert[data[cleartp]].end())
				{
					alert[data[cleartp]].erase(it);
					ans --;
				}
				
				++cleartp;
			}
		}
		printf("%d\n", ans);
	}
}