#include<bits/stdc++.h>
using namespace std;
int n,m,p,Test_num;
bool ok;
int rt[300002];
bool u[300002];
vector<int> vec[300002];
queue<int> q;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),ok=1;
		for(int i=1;i<=n;++i)vec[i].clear(),u[i]=0,rt[i]=i;
		for(int i=1,x,y;i<=m;++i)read(x),read(y),vec[x].push_back(y),vec[y].push_back(x),getroot(x),getroot(y),rt[rt[x]]=rt[y];
		for(int i=1;i<=n;++i)
		{
			getroot(i);
			if(rt[i]!=rt[1])
			{
				ok=0;
				break;
			}
		}
		if(!ok)
		{
			puts("NO");
			continue;
		}
		for(int i=0;i<vec[1].size();++i)u[vec[1][i]]=1,q.push(vec[1][i]);
		vec[0].clear(),u[1]=1,vec[0].push_back(1);
		while(!q.empty())
		{
			p=q.front(),q.pop();
			for(int i=0;i<vec[p].size();++i)
				if(!u[vec[p][i]])
				{
					u[vec[p][i]]=1,vec[0].push_back(vec[p][i]);
					for(int j=0;j<vec[vec[p][i]].size();++j)
						if(!u[vec[vec[p][i]][j]])
							u[vec[vec[p][i]][j]]=1,q.push(vec[vec[p][i]][j]);
				}
		}
		printf("YES\n%d\n",vec[0].size());
		for(int i=0;i<vec[0].size();++i)printf("%d%c",vec[0][i],i+1==vec[0].size()? '\n':' ');
	}
	return 0;
}