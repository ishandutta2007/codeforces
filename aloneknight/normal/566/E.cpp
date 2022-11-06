#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=1005;
int n,tg[N];
bitset<N>t,a[N],b[N],c[N];
int main()
{
	n=rd();
	rep(i,1,n){int k=rd();rep(j,1,k)b[i][rd()]=1;}
	rep(i,1,n)rep(j,i+1,n)
	{
		t=b[i]&b[j];
		if(t.count()==2)
		{
			int x=t._Find_first();t[x]=0;
			int y=t._Find_first();t[y]=0;
			a[x][y]=a[y][x]=1;
		}
	}
	t.reset();
	rep(i,1,n)if(a[i].count())tg[i]=-1,t[i]=1;
	rep(i,1,n)a[i][i]=1;
	rep(i,1,n)rep(j,i+1,n)if(a[i][j])printf("%d %d\n",i,j);
	if(t.count()==0){rep(i,2,n)printf("%d %d\n",1,i);return 0;}
	if(t.count()==2)
	{
		rep(x,1,n)rep(y,x+1,n)if(a[x][y])
		{
			bool ff=0;
			rep(i,1,n)if(b[i].count()!=n)
			{
				rep(j,1,n)if(b[i][j])
				{
					if(tg[j]==1)break;
					if(tg[j]!=-1){printf("%d %d\n",ff?y:x,j);tg[j]=1;}
				}
				ff=1;
			}
		}
		return 0;
	}
	rep(i,1,n)
	{
		c[i]=b[i]&t;int ff=1;
		rep(j,1,n)
		{
			if(b[i]==b[j]){if(j<i){ff=0;break;}}
			else if((b[i]&b[j])==b[j]){ff=0;break;}
		}
		if(ff)
		{
			rep(j,1,n)if(c[i]==a[j])
			{
				rep(k,1,n)if(b[i][k]&&!tg[k]){printf("%d %d\n",j,k);tg[k]=1;}
				break;
			}
		}
	}
	return 0;
}