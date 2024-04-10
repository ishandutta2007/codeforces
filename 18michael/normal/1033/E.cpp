#include<bits/stdc++.h>
using namespace std;
int n,edge_t=0;
int rt[602],la[602],col[602];
vector<int> vec[602],Vec[2];
vector<int> vec1,vec2,vec3,vec4;
struct aaa
{
	int to,nx;
}edge[1202];
inline vector<int> merge(vector<int> a,vector<int> b)
{
	for(int i=0;i<b.size();++i)a.push_back(b[i]);
	return a;
}
inline int query(vector<int> vec)
{
	if(vec.size()<=1)return 0;
	int x;printf("? %d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
	return fflush(stdout),scanf("%d",&x),x;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int c)
{
	Vec[((col[x]=c)+1)>>1].push_back(x);
	for(int i=la[x],v;i;i=edge[i].nx)if(!col[v=edge[i].to])dfs(v,-c);
}
inline void dfs1(int x,int f,int y)
{
	if(x==y)return (void)(vec1.push_back(x));
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs1(v,x,y);
			if(vec1.size())return (void)(vec1.push_back(x));
		}
}
int main()
{
	srand(time(NULL)),scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)
	{
		if(rt[i])continue;
		rt[i]=i,vec[i].push_back(i);
		QAQ:vec1.clear();
		for(int j=1;j<=n;++j)if(!rt[j])vec1.push_back(j);
		if(!vec1.size())break;
		for(x=query(vec[i]);vec1.size()>1;)
		{
			vec2.clear(),vec3.clear();
			for(int j=0;j<vec1.size();++j)
			{
				if(j&1)vec2.push_back(vec1[j]);
				else vec3.push_back(vec1[j]);
			}
			if(x+query(vec2)<query(merge(vec[i],vec2)))vec1=vec2;
			else vec1=vec3;
		}
		if(x==query(merge(vec[i],vec1)))continue;
		for(vec4=vec[i];vec4.size()>1;)
		{
			vec2.clear(),vec3.clear();
			for(int j=0;j<vec4.size();++j)
			{
				if(j&1)vec2.push_back(vec4[j]);
				else vec3.push_back(vec4[j]);
			}
			if(query(merge(vec1,vec2))>query(vec2))vec4=vec2;
			else vec4=vec3;
		}
		add_edge(vec1[0],vec4[0]),rt[vec1[0]]=i,vec[i].push_back(vec1[0]);
		goto QAQ;
	}
	for(int i=1;i<=n;++i)if(rt[i]==i)dfs(i,1);
	if(query(Vec[1]))swap(Vec[0],Vec[1]);
	else if(!query(Vec[0]))
	{
		if(!Vec[0].size())swap(Vec[0],Vec[1]);
		printf("Y %d\n",Vec[0].size());
		for(int i=0;i<Vec[0].size();++i)printf("%d ",Vec[0][i]);
		return 0&fflush(stdout);
	}
	for(;Vec[0].size()>2;)
	{
		vec1.clear();
		for(int i=0;i<Vec[0].size();++i)if(rand()&1)vec1.push_back(Vec[0][i]);
		if(query(vec1))Vec[0]=vec1;
	}
	vec1.clear(),dfs1(Vec[0][0],0,Vec[0][1]),printf("N %d\n",vec1.size());
	for(int i=0;i<vec1.size();++i)printf("%d ",vec1[i]);
	return 0&fflush(stdout);
}