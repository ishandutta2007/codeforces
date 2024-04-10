#include<cstdio>
#include<vector>
using namespace std;
int n,m,ok,las,Test_num;
int ans[100002],cnt[100002];
vector<int> v;
vector<int> vec[100002];
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&m),v.clear(),las=1;
		for(int i=1,k,x;i<=m;++i)
		{
			scanf("%d",&k),vec[i].clear();
			for(int j=1;j<=k;++j)scanf("%d",&x),vec[i].push_back(x);
		}
		for(int i=1;i<=m;++i)
		{
			ok=0;
			for(int j=0;j<vec[i].size();++j)
				if(cnt[vec[i][j]]+1<=(m+1)/2)
				{
					if(!cnt[vec[i][j]])v.push_back(vec[i][j]);
					ans[i]=vec[i][j],++cnt[vec[i][j]],ok=1;break;
				}
			if(ok)continue;
			ans[i]=vec[i][0];
			for(;las<i;++las)
				if(ans[las]==vec[i][0] && vec[las].size()>1)
				{
					if(!cnt[vec[las][1]])v.push_back(vec[las][1]);
					ans[las]=vec[las][1],++cnt[vec[las][1]],ok=1;
					break;
				}
			if(!ok){puts("NO"),ok=-1;break;}
		}
		if(~ok)
		{
			puts("YES");
			for(int i=1;i<=m;++i)printf("%d%c",ans[i],i==m? '\n':' ');
		}
		for(int i=0;i<v.size();++i)cnt[v[i]]=0;
	}
	return 0;
}