#include<cstdio>
#include<vector>
using namespace std;
int as=1e9,n,m;
int calc(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int vl;
	scanf("%d",&vl);
	if(as>vl)as=vl;
	return vl;
}
vector<int> reduce(vector<int> s1,vector<int> s2)
{
	if(s2.size()<=s1.size())return s2;
	vector<int> as;
	vector<int> ls;ls.resize(s1.size());
	ls[0]=calc(s1[0],s2[0]);
	for(int i=0;i<s2.size();i++)
	{
		int su=as.size();
		if(!su)as.push_back(s2[i]);
		else
		{
			int v1=ls[su-1],v2=calc(s1[su-1],s2[i]);
			if(v1>=v2)as.pop_back(),ls[su-1]=v2,i--;
			else if(su<s1.size())as.push_back(s2[i]),ls[su]=calc(s1[su],as[su]);
		}
	}
	return as;
}
vector<int> smawk(vector<int> s1,vector<int> s2)
{
	if(s1.size()==1)
	{
		int mn=1e9,fr=0;
		for(int j=0;j<s2.size();j++)
		{
			int vl=calc(s1[0],s2[j]);
			if(vl<mn)mn=vl,fr=s2[j];
		}
		return {fr};
	}
	s2=reduce(s1,s2);
	vector<int> s3;for(int i=1;i<s1.size();i+=2)s3.push_back(s1[i]);
	vector<int> as1=smawk(s3,s2);
	vector<int> as2;
	int lb=0;
	for(int i=0;i<s1.size();i++)
	{
		if(i&1)as2.push_back(as1[i>>1]);
		else
		{
			int rb=lb;
			if(i+1>=s1.size())rb=s2.size()-1;
			else while(as1[i>>1]>s2[rb])rb++;
			int mn=1e9,fr=0;
			for(int j=lb;j<=rb;j++)
			{
				int vl=calc(s1[i],s2[j]);
				if(vl<mn)mn=vl,fr=s2[j];
			}
			as2.push_back(fr);lb=rb;
		}
	}
	return as2;
}
int main()
{
	scanf("%d%d",&n,&m);
	vector<int> s1,s2;
	for(int i=1;i<=n;i++)s1.push_back(i);
	for(int i=1;i<=m;i++)s2.push_back(i);
	smawk(s1,s2);
	printf("! %d\n",as);
}