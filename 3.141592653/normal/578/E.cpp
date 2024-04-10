#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int X,Y,n;
char str[1111111];
#include<vector>
using std::vector;
vector<int>v[1111111];
int s[2],tot=0;
int stk[2][1111111];
void ins(int o,int p)
{
	if(!s[!o])stk[!o][++s[!o]]=++tot;
	v[stk[!o][s[!o]]].push_back(p),stk[o][++s[o]]=stk[!o][s[!o]--];
}
vector<int>&merge(vector<int>&x,vector<int>&y)
{
	if(!x.size())return y;
	if(!y.size())return x;
	if(str[x.back()]^str[y[0]])
	{
		for(auto t:y)x.push_back(t);
		return x;
	}else if(str[y.back()]^str[x[0]])
	{
		for(auto t:x)y.push_back(t);
		return y;
	}else
	{
		if(x.back()>y.back())
			y.push_back(x.back()),x.pop_back();
		else x.push_back(y.back()),y.pop_back();
		return merge(x,y);
	}
}
int main()
{
	scanf("%s",str+1),n=strlen(str+1);
	register int i;
	for(i=1;i<=n;i++)ins(str[i]=='L',i);
	printf("%d\n",tot-1);
	vector<int>&p=v[1];
	for(i=2;i<=tot;i++)
		p=merge(p,v[i]);
	for(auto t:p)printf("%d ",t);puts("");
}
/*
Just go for it.
*/