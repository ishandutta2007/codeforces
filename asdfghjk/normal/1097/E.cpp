#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N=100005;
int t,n,a[N],mx[N],f[N],b[N],cnt,id[N],i,j,k,num[N],Num[N],ans,nxt[N],w[N];
vector<int> vct[N];
set<int> st;
set<int>::iterator ddq;
bool vis[N];
void update(int x,int y)
{
	while(x<=n)
	{
		mx[x]=max(mx[x],y);
		x+=x&-x;
	}
}
int work(int x)
{
	int rtn=0;
	while(x)
	{
		rtn=max(rtn,mx[x]);
		x-=x&-x;
	}
	return rtn;
}
void dzx()
{
	int i,j,k;
	st.clear();
	for(i=n;i>=1;--i)
	{
		ddq=st.lower_bound(a[i]);
		if(ddq==st.begin())
		{
			nxt[a[i]]=0;
			st.insert(a[i]);
		}
		else
		{
			ddq--;
			nxt[a[i]]=*ddq;
			st.erase(ddq);
			st.insert(a[i]);
		}
	}
	for(i=1;i<=n;++i)
		vis[i]=false;
	for(i=n;i>=1;--i)
		if(!vis[i])
		{
			++ans;
			vct[ans].clear();
			for(j=i,k=0;j;j=nxt[j])
				++k;
			vct[ans].push_back(k);
			for(j=i;j;j=nxt[j])
			{
				vct[ans].push_back(num[j]);
				vis[j]=true;
			}
		}
}
int main()
{
	scanf("%d",&t);
	w[1]=1;
	for(i=2;i<=100000;++i)
		if(1ll*(1+w[i-1]+1)*(w[i-1]+1)/2==i+1)
			w[i]=w[i-1]+1;
		else
			w[i]=w[i-1];
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			num[i]=i;
		}
		ans=0;
		while(n)
		{
			for(i=0;i<=n;++i)
				mx[i]=0;
			for(i=1,j=k=0;i<=n;++i)
			{
				f[i]=work(a[i])+1;
				update(a[i],f[i]);
				if(f[i]>f[j])
					j=i;
			}
			if(f[j]<w[n])
			{
				dzx();
				break;
			}
			++ans;
			vct[ans].clear();
			cnt=0;
			while(j)
			{
				for(i=j-1;i;--i)
					if(a[i]<=a[j]&&f[i]+1==f[j])
						break;
				b[++cnt]=a[j];
				a[j]=0;
				j=i;
			}
			vct[ans].push_back(cnt);
			for(i=cnt;i>=1;--i)
				vct[ans].push_back(num[b[i]]);
			cnt=0;
			for(i=1;i<=n;++i)
				if(a[i])
					b[++cnt]=a[i];
			sort(b+1,b+1+cnt);
			for(i=1;i<=cnt;++i)
			{
				id[b[i]]=i;
				Num[i]=num[b[i]];
			}
			for(i=1;i<=cnt;++i)
				num[i]=Num[i];
			cnt=0;
			for(i=1;i<=n;++i)
				if(a[i])
					b[++cnt]=id[a[i]];
			n=cnt;
			for(i=1;i<=n;++i)
				a[i]=b[i];
		}
		printf("%d\n",ans);
		for(i=1;i<=ans;++i)
		{
			for(j=0;j<vct[i].size();++j)
				printf("%d ",vct[i][j]);
			puts("");
		}
	}
	return 0;
}