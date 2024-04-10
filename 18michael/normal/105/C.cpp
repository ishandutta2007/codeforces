#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,num,sum=0,T=1;LL res,tmp;
int lim[100002],t_t[3]={},t1_t[3]={},from[100002],id1[100002],id2[100002],id3[100002],id4[100002],ans[3];
LL pre[100002];bool vis[100002];
string c;
string s[100002],s1[100002];
map<string,int> mp;
vector<string> vec[3];
struct aaa
{
	int val,id;
}t[3][100002],t1[3][100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val>b.val? 1:0;
}
inline void solve(int x)
{
	sort(t1[x]+1,t1[x]+t1_t[x]+1,cmp),res=-1;
	for(int i=1;i<=t1_t[x];++i)pre[i]=pre[i-1]+t1[x][i].val;
	for(int i=1;i<=t_t[x];++i)if((tmp=pre[min(lim[t[x][i].id],t1_t[x])]+t[x][i].val)>res)res=tmp,ans[x]=i;
	for(int i=min(lim[t[x][ans[x]].id],t1_t[x]);i;--i)vec[x].push_back(s1[t1[x][i].id]),vis[t1[x][i].id]=1;
}
inline void print(int x)
{
	while(T<=m && vec[x].size()<lim[t[x][ans[x]].id]){while(T<=m && vis[T])++T;if(T<=m)vec[x].push_back(s1[T]),vis[T]=1;}
	cout<<s[t[x][ans[x]].id]<<" "<<vec[x].size();
	for(int i=0;i<vec[x].size();++i)cout<<" "<<vec[x][i];
	puts("");
}
inline void solve1(int x)
{
	res=-1;for(int i=1;i<=t_t[x];++i)if(t[x][i].val>res)res=t[x][i].val,num=i;
	cout<<s[t[x][num].id]<<" "<<lim[t[x][num].id];
	for(int i=1;i<=m;++i)if(id1[from[i]]==x && id2[from[i]]==num)cout<<" "<<s1[i];
	puts("");
}
int main()
{
	read(n);
	for(int i=1,x,y,z;i<=n;++i)
	{
		cin>>s[i]>>c,read(x),read(y),read(z),read(lim[i]),sum+=lim[i],mp[s[i]]=i;
		if(c[0]=='w')t[id1[i]=0][id2[i]=(++t_t[0])]=(aaa){x,i};
		else if(c[0]=='a')t[id1[i]=1][id2[i]=(++t_t[1])]=(aaa){y,i};
		else t[id1[i]=2][id2[i]=(++t_t[2])]=(aaa){z,i};
	}
	read(m);
	for(int i=1,x;i<=m;++i)
	{
		cin>>s1[i]>>c,read(x),vis[i]=0;
		if(c[0]=='g')t1[id3[i]=0][id4[i]=(++t1_t[0])]=(aaa){x,i};
		else if(c[0]=='s')t1[id3[i]=1][id4[i]=(++t1_t[1])]=(aaa){x,i};
		else t1[id3[i]=2][id4[i]=(++t1_t[2])]=(aaa){x,i};
		cin>>c,from[i]=mp[c];
	}
	if(sum>m)solve(0),solve(1),solve(2),print(0),print(1),print(2);
	else
	{
		for(int i=1;i<=m;++i)if(id3[i]==id1[from[i]])t[id1[from[i]]][id2[from[i]]].val+=t1[id3[i]][id4[i]].val;
		solve1(0),solve1(1),solve1(2);
	}
	return 0;
}