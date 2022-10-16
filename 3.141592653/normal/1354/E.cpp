#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,m;
#include<vector>
std::vector<int>v[111111],X[111111],Y[111111];
int rcc;
int col[111111];
bool dfs(int x,int c=1)
{
	col[x]=c;
	if(c==1)X[rcc].push_back(x);
	else Y[rcc].push_back(x);
	for(auto tp:v[x])
	{
		if(col[tp]){if(col[tp]!=-c)return 0;}
		else if(!dfs(tp,-c))return 0;
	}return 1;
}
bool valid[5555][5555];
void ins(int pos,int x,int y)
{
	register int i;
	for(i=n;i>=x;i--)
		valid[pos][i]|=valid[pos-1][i-x];
	for(i=n;i>=y;i--)
		valid[pos][i]|=valid[pos-1][i-y];
}
int n1,n2,n3;
int label[111111];
void labelize()
{
	int tp=n;
	register int i;
	int rm=n2;
	for(i=rcc;i;i--)
	{
		if(X[i].size()<=rm)
		{
			if(valid[i-1][rm-X[i].size()])
			{
				for(auto v:X[i])
					label[v]=2;
				rm-=X[i].size();
				goto T; 
			}
		}
		if(Y[i].size()<=rm)
		{
			if(valid[i-1][rm-Y[i].size()])
			{
				for(auto v:Y[i])
					label[v]=2;
				rm-=Y[i].size();
				goto T; 
			}
		}T:;
	}for(i=1;i<=n;i++)
		if(!label[i])
		{
			if(n1)label[i]=1,n1--;
			else label[i]=3;
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&n1,&n2,&n3);
	register int i;
	valid[0][0]=1;
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}for(i=1;i<=n;i++)
		if(!col[i])
		{
			rcc++;
			if(!dfs(i))return puts("NO"),0;
		}
	for(i=1;i<=rcc;i++)
		ins(i,X[i].size(),Y[i].size());
	if(!valid[rcc][n2])
		return puts("NO"),0;
	puts("YES");
	labelize(); 
	for(i=1;i<=n;i++)printf("%d",label[i]);puts("");
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/