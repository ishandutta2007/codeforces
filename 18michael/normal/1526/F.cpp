#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,x,Test_num;
int p[100002];
vector<int> vec[100002];
inline int query(int a,int b,int c)
{
	printf("? %d %d %d\n",a,b,c),fflush(stdout),scanf("%d",&x);
	return x;
}
inline void solve()
{
	for(scanf("%d",&n);;)
	{
		a=rand()%n+1;
		do b=rand()%n+1;while(b==a);
		do c=rand()%n+1;while(c==a || c==b);
		if(query(a,b,c)<=(n-4)/6)break;
	}
	for(int i=1;i<=n;++i)vec[i].clear();
	for(int i=1;i<=n;++i)if(a!=i & b!=i)vec[query(a,b,i)].push_back(i);
	for(int i=n;;--i)
		if(vec[i].size())
		{
			if(vec[i-1].size()>1 && (query(vec[i][0],a,vec[i-1][0])>query(vec[i][0],a,vec[i-1][1])))vec[i-1][0]=vec[i-1][1];
			a=vec[i][0],b=vec[i-1][0];
			break;
		}
	p[a]=1,p[b]=2;
	for(int i=1;i<=n;++i)if(a!=i && b!=i)p[i]=query(a,b,i)+2;
	if(p[1]>p[2])for(int i=1;i<=n;++i)p[i]=n-p[i]+1;
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d%c",p[i],i==n? '\n':' ');
	fflush(stdout),scanf("%d",&x);
}
int main()
{
	for(srand(time(NULL)),scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}