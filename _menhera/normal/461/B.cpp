#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
int parent[101010];
int color[101010];
vector<int> conn[101010];
int N;
int pow(int a,int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	int p=pow(a,b/2);
	int res=1LL*p*p%MOD;
	if(b&1) res=1LL*res*a%MOD;
	return res;
}
int modinv(int a)
{
	return pow(a,MOD-2);
}
pair<int,int> dfs(int a)
{
	int prod=1;
	vector<pair<int, int> > V;
	for(int x:conn[a])
	{
		V.push_back(dfs(x));
	}
	int u1=0;
	int u0=0;
	for(auto a:V)
		prod=(1LL*prod*((a.first+a.second)%MOD))%MOD;
	u0=prod;
	for(auto a:V)
		u1=(((1LL*prod*modinv((a.first+a.second)%MOD))%MOD*a.first)%MOD+u1)%MOD;
	if(color[a]) return make_pair(u0,0);
	else return make_pair(u1,u0);
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++) scanf("%d",parent+i);
	for(int i=0;i<N;i++) scanf("%d",color+i);
	for(int i=1;i<N;i++) conn[parent[i]].push_back(i);
	printf("%d",dfs(0).first);
	return 0;
}