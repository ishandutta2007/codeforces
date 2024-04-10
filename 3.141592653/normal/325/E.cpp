#include<bits/stdc++.h>
int n;
bool v[111111];
std::vector<int>w;
void dfs(int x)
{
	if(v[x])return;
	v[x]=1;
	dfs((x<<1)%n),dfs((x<<1|1)%n);
	w.push_back(x);
}
int main()
{
	scanf("%d",&n);
	if(n&1)return puts("-1"),0;
	dfs(0);
	for(;w.size();)printf("%d ",w.back()),w.pop_back();
	puts("0");
}