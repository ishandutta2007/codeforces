//test
#include<bits/stdc++.h>
using namespace std;
bitset<1005>b[1005];
bitset<1005>mp[1005];
int vist[1005],f[1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			b[i][x]=1;
		}
	}
	int flag=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		bitset<1005>bb=b[i]&b[j];
		if(bb.count()!=2)continue;
		int l1=bb._Find_first();
		int l2=bb._Find_next(l1);
		vist[l1]=vist[l2]=1;
		mp[l1][l2]=mp[l2][l1]=1;
		flag++;
	}
	if(!flag)vist[1]=1;
	flag=0;
	for(int i=1;i<=n;i++)if(!vist[i])
	{
		int s=INT_MAX,w;
		for(int j=1;j<=n;j++)if(b[j][i]==1&&s>b[j].count())
		{
			s=b[j].count();
			w=j;
		}
		int s1=INT_MIN,s2=INT_MAX,ww;
		for(int j=1;j<=n;j++)if(b[w][j]==1&&vist[j])
		{
			bitset<1005> bb=mp[j]&b[w];
			int tt=bb.count(),t2=mp[j].count();
			if(s1<tt)
			{
				s1=tt;
				s2=t2;
				ww=j;
			}else if(s1==tt&&s2>t2)
			{
				s2=t2;
				ww=j;
			}
		}
		int w2=0;
		for(int j=1;j<=n;j++)if(b[w][j]==1&&vist[j])
		{
			bitset<1005> bb=mp[j]&b[w];
			int tt=bb.count(),t2=mp[j].count();
			if(s1==tt&&s2==t2&&j!=ww)
			{
				w2=j;
				break;
			}
		}
		if(!w2)cout<<i<<" "<<ww<<endl,f[i]=ww;
		else
		{
			int flag=1;
			for(int j=1;j<=n;j++)if(f[j]==ww||f[j]==w2)
			{
				if(b[w][j]&&f[j]==ww||!b[w][j]&&f[j]==w2)
				{
					cout<<i<<" "<<ww<<endl;
					f[i]=ww;
				}else
				{
					cout<<i<<" "<<w2<<endl;
					f[i]=w2;
				}
				flag=0;
				break;
			}
			if(flag)
			{
				cout<<i<<" "<<ww<<endl;
				f[i]=ww;
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		if(mp[i][j])cout<<i<<" "<<j<<endl;
	return 0;
}