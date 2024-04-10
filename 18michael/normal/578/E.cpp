#include<bits/stdc++.h>
using namespace std;
int n,t=0,o;
char ch[100002];
set<int> s[2];
set<int>::iterator it;
vector<int> vec[100002];
vector<int> vec2[2][2];
inline void print(int x)
{
	for(int i=0;i<vec[x].size();++i)printf("%d ",vec[x][i]);
}
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;++i)s[ch[i]=(ch[i]=='L')].insert(i);
	for(;s[0].size() || s[1].size();++t)
	{
		if(!s[0].size())o=1;
		else if(!s[1].size())o=0;
		else o=(*s[0].begin()>*s[1].begin());
		for(;;vec[t].push_back(*it),s[o].erase(it),o^=1)
		{
			if(vec[t].size())it=s[o].lower_bound(vec[t].back());
			else it=s[o].begin();
			if(it==s[o].end())break;
		}
		vec2[ch[vec[t][0]]][ch[vec[t].back()]].push_back(t);
	}
	printf("%d\n",t-1),o=(vec2[0][0].size()<vec2[1][1].size());
	if(vec2[0][0].size() || vec2[1][1].size())
	{
		for(int i=0;i<vec2[o][o].size();++i)
		{
			if(!i)for(int j=0;j<vec2[o][o^1].size();++j)print(vec2[o][o^1][j]);
			print(vec2[o][o][i]);
			if(!i)for(int j=0;j<vec2[o^1][o].size();++j)print(vec2[o^1][o][j]);
			if(i==vec2[o^1][o^1].size())break;
			print(vec2[o^1][o^1][i]);
		}
		return 0;
	}
	if(!vec2[0][1].size())
	{
		for(int i=0;i<vec2[1][0].size();++i)print(vec2[1][0][i]);
		return 0;
	}
	if(!vec2[1][0].size())
	{
		for(int i=0;i<vec2[0][1].size();++i)print(vec2[0][1][i]);
		return 0;
	}
	o=ch[1],vec[vec2[o^1][o][0]].push_back(vec[vec2[o][o^1][0]].back()),vec[vec2[o][o^1][0]].pop_back();
	for(int i=1;i<vec2[o][o^1].size();++i)print(vec2[o][o^1][i]);
	print(vec2[o][o^1][0]);
	for(int i=1;i<vec2[o^1][o].size();++i)print(vec2[o^1][o][i]);
	print(vec2[o^1][o][0]);
	return 0;
}