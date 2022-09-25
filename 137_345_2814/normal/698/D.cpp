#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 1050
#define K 8
int v[N],as,n,k,us[K],is,tp[N],inq[N],is1[N];
vector<int> q[K][N];
queue<int> s1;
struct point{long long x,y;}s[K],t[N];
point operator +(point a,point b){return (point){a.x+b.x,a.y+b.y};}
point operator -(point a,point b){return (point){a.x-b.x,a.y-b.y};}
long long cross(point x,point y){return x.x*y.y-x.y*y.x;}
long long pt(point x,point y){return x.x*y.x+x.y*y.y;}
void dfs(int ls,queue<int> s1)
{
	if(!s1.size()){is=1;return;}
	if(is)return;
	if(s1.size()>ls)return;
	if(!ls){is=1;return;}
	int s2=s1.front();s1.pop();inq[s2]=0;
	is1[s2]=1;
	for(int i=1;i<=k;i++)if(!us[i])
	{
		queue<int> s3=s1,md1;
		int sz=q[i][s2].size();
		for(int j=0;j<sz;j++)if(!inq[q[i][s2][j]]&&!is1[q[i][s2][j]])s3.push(q[i][s2][j]),md1.push(q[i][s2][j]),inq[q[i][s2][j]]=1;
		us[i]=1;tp[k-ls+1]=i;
		dfs(ls-1,s3);
		while(!md1.empty())inq[md1.front()]=0,md1.pop();
		us[i]=0;
	}
	inq[s2]=1;is1[s2]=0;
}
int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=k;i++)scanf("%lld%lld",&s[i].x,&s[i].y);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&t[i].x,&t[i].y);
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	if(j!=k)
	if(cross(t[j]-s[i],t[k]-s[i])==0&&pt(s[i]-t[j],t[k]-t[j])<0)q[i][k].push_back(j);
	for(int i=1;i<=n;i++)
	{
		while(!s1.empty())s1.pop();
		s1.push(i);inq[i]=1;
		is=0;
		dfs(k,s1);inq[i]=0;
		if(is)as++;
	}
	printf("%d\n",as);
}