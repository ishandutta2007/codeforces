#include<bits/stdc++.h>
using namespace std;
long long a,b,c,T,d[1000001],v[1000001],o,h[500001],u[1000001],cn,ans,an,fl,di[1001][1001],ri[1001],le[1001],mn[1001],mn1[1001],mnn[1001][1001],mnn1[1001][1001],cnn,vv[100001];
string s;
struct p
{
	long long q,w,id;
}l[1000001];
void add(long long qq,long long ww)
{
	l[++o].q=ww;
	l[o].w=h[qq];
	h[qq]=o;
}
bool cmp(p qq,p ww)
{
	return qq.q<ww.q;
}
int main()
{
	T=1;
//	scanf("%lld",&T);
	for(int ii=1;ii<=T;ii++)
	{
		scanf("%lld%lld",&a,&b);
		for(int i=1;i<=b;i++)
		{
			scanf("%lld%lld",&l[i].q,&l[i].w);l[i].id=i;
		}
		sort(l+1,l+b+1,cmp);
		for(int i=1;i<=b;i++) u[i]=l[i].q;
		for(int i=1;i<=a;i++)
		{
			scanf("%lld",&d[i]);
		}
		memset(mn,0x3f3f3f3f3f3f,sizeof(mn));
		memset(mn1,0x3f3f3f3f3f3f,sizeof(mn1));
		memset(mnn,0x3f3f3f3f3f3f,sizeof(mnn));
		memset(mnn1,0x3f3f3f3f3f3f,sizeof(mnn1));
		for(int i=2;i<=b;i++)
		{
			long long tt=0;
			for(int j=l[i-1].q;j<=l[i].q;j++)
			{
				tt+=d[j];
				mn[i]=min(mn[i],tt);
			}
			tt=0;
			for(int j=l[i].q;j>=l[i-1].q;j--)
			{
				tt+=d[j];
				mn1[i]=min(mn1[i],tt);
			}
		}
		for(int i=1;i<=a;i++)
		{
			long long tt=0;
			for(int j=i;j<=a;j++)
			{
				tt+=d[j];
				mnn[i][j]=min(mnn[i][j-1],tt);
			}
		}
		for(int i=1;i<=a;i++)
		{
			long long tt=0;
			for(int j=i;j>=1;j--)
			{
				tt+=d[j];
				mnn1[j][i]=min(mnn1[j+1][i],tt);
			}
		}
		for(int i=1;i<=b;i++)
		{
			long long tt=l[i].w,fl=1;
			for(int j=l[i].q;j<=a;j++)
			{
				tt+=d[j];
				if(tt<0)
				{
					fl=0;
					ri[i]=j-1;break;
				}
				di[i][j]=tt;
			}tt=l[i].w;fl=1;
			for(int j=l[i].q;j>=1;j--)
			{
				tt+=d[j];
				if(tt<0)
				{
					fl=0;
					ri[i]=j+1;break;
				}
				di[i][j]=tt;
			}
			if(fl) ri[i]=1;
		}
		for(int i=1;i<=a;i++)
		{
			cnn=0;
			long long tt=lower_bound(u+1,u+b+1,i)-u;
			bool fl=1;
			long long gg=0,la=i;
			for(int j=tt;j<=b;j++)
			{
				if(j==b)
				{
					if(mnn1[la][l[j].q]+l[j].w>=0)
					{
						v[++cnn]=b;
					}
					else fl=0;
					break;
				}
				if(mnn1[la][l[j].q]>=0)
				{
					continue;
				}
				else
				{
					if(mnn1[la][l[j].q]+l[j].w>=0)
					{
						v[++cnn]=j;
						la=l[j].q;
					}
				}
			}
			if(!fl) continue;
			la=i-1;
//			cout<<13243;
			for(int j=tt-1;j>=1;j--)
			{
				if(j==1)
				{
//					cout<<la<<" "<<mnn[1][la]<<" "<<l[j].w<<"\n";
					if(mnn[l[j].q][la]+l[j].w>=0)
					{
						v[++cnn]=1;
					}
					else fl=0;
					break;
				}
				if(mnn[l[j].q][la]>=0)
				{
					continue;
				}
				else
				{
//					cout<<mnn[l[j].q][la]<<" "<<l[j].w<<"\n";
					if(mnn[l[j].q][la]+l[j].w>=0)
					{
						v[++cnn]=j;
						la=l[j].q;
					}
				}
			}
			if(!fl) continue;
			printf("%d\n",i);
			for(int i=1;i<=cnn;i++)
			{
				vv[v[i]]=1;
				printf("%lld ",l[v[i]].id);
			}
			for(int i=1;i<=b;i++)
			{
				if(!vv[i]) printf("%d ",l[i].id);
			}
			return 0;
		}
		printf("-1");
	}
	return 0;
}