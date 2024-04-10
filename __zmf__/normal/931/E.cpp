//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=5009;
int n,ans,res,cnt;
char a[N];
int b[N],now[N],tot,tot2,qwq[N];
int vis[N];
vector<int> p[N];
int main()
{
	cin>>a;n=strlen(a);
	for(int i=0;i<n;i++)b[i]=a[i]-'a',p[b[i]].push_back(i);
	for(int i=0;i<26;i++)
	{
		tot=0;
		for(int j=0;j<p[i].size();j++)now[++tot]=p[i][j];
		res=0;
		for(int j=1;j<n;j++)
		{
			cnt=0;
			for(int k=1;k<=tot;k++)
			{
				if(!vis[b[(now[k]+j)%n]])cnt++,vis[b[(now[k]+j)%n]]++;
				else if(vis[b[(now[k]+j)%n]]==1)cnt--,vis[b[(now[k]+j)%n]]++;
				else vis[b[(now[k]+j)%n]]++;
			}
			res=max(res,cnt);
			for(int k=1;k<=tot;k++)
			{
				vis[b[(now[k]+j)%n]]--;
			}
		}
		ans+=res;
	}
	printf("%.12lf",(double)ans*1.000000000/(double)n*1.000000000);
	return 0;
}