#include<cstdio>
#include<vector>
#include<stack>
#define MAXN 100100
using namespace std;
vector<int> disj[MAXN];
vector<int> invdisj[MAXN];
int color[MAXN];
vector<int> colors[MAXN];
bool check[MAXN];
bool revcheck[MAXN];
int tp=1;
int N,M;
stack<int> st;
void dfs(int a)
{
	if(check[a]) return;
	check[a]=true;
	for(int i=0;i<disj[a].size();i++)
		dfs(disj[a][i]);
	st.push(a);
}
void colordfs(int now,int colornow)
{
	if(color[now]) return;
	color[now]=colornow;
	colors[colornow].push_back(now);
	for(int i=0;i<disj[now].size();i++)
		colordfs(disj[now][i],colornow);
	for(int i=0;i<invdisj[now].size();i++)
		colordfs(invdisj[now][i],colornow);
	return;
}
int main()
{
	scanf("%d%d",&N,&M);
	//puts("Wtf");
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		disj[x].push_back(y);
		invdisj[y].push_back(x);
	}
	for(int i=0;i<N;i++)
		if(!color[i]) colordfs(i,tp++);
	int cnt=0;
	for(int i=1;i<tp;i++)
	{
		cnt+=colors[i].size()-1;
		for(int j=0;j<colors[i].size();j++)
			dfs(colors[i][j]);
		while(!st.empty())
		{
			int x=st.top();
			st.pop();
			revcheck[x]=true;
			for(int i=0;i<invdisj[x].size();i++)
			{
				if(!revcheck[invdisj[x][i]])
				{
					cnt++;
					goto fuck;
				}
			}
		}
		fuck:
		while(!st.empty()) st.pop();
	}
	//int cnt=0;
	printf("%d",cnt);
	return 0;
}