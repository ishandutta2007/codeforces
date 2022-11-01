#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)2010)


ll n,m,q,l[N][N],r[N][N],minil[N],minir[N];
pair <ll,ll> qu[N];
string s[N];
char c[N];

void update(ll x)
{
	r[x][m-1]=(s[x][m-1]=='.');
	for(int i=m-2;i>=0;i--)r[x][i]=(s[x][i]=='.'?r[x][i+1]+1:0);
	l[x][0]=(s[x][0]=='.');
	for(int i=1;i<m;i++)l[x][i]=(s[x][i]=='.'?l[x][i-1]+1:0);
}

bool check(ll y,ll k)
{
	if(k>n)return 0;
	multiset <ll> sl,sr;
	for(int i=0;i<k;i++)sl.insert(l[i][y]),sr.insert(r[i][y]);
	if((*sl.begin())+(*sr.begin())>k)return 1;
	for(int i=k;i<n;i++)
	{
		sl.erase(sl.find(l[i-k][y]));sr.erase(sr.find(r[i-k][y]));
		sl.insert(l[i][y]);sr.insert(r[i][y]);
		if((*sl.begin())+(*sr.begin())>k)return 1;
	}
	return 0;
}

bool check2(ll x,ll y,ll k)
{
	minil[x]=l[x][y];minir[x]=r[x][y];
	for(int i=x+1;i<n;i++)minil[i]=min(minil[i-1],l[i][y]),minir[i]=min(minir[i-1],r[i][y]);
	for(int i=x-1;i>=0;i--)minil[i]=min(minil[i+1],l[i][y]),minir[i]=min(minir[i+1],r[i][y]);
	for(int i=0;i<n-k+1;i++)
	{
		int j=i+k-1;
		if(x<i || j<x)continue;
		if(min(minil[i],minil[j])+min(minir[i],minir[j])>k)return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++)scanf(" %s",&c),s[i]=c;
	for(int i=0;i<q;i++)scanf("%d%d",&qu[i].first,&qu[i].second),qu[i].first--,qu[i].second--,s[qu[i].first][qu[i].second]='X';
	for(int i=0;i<n;i++)update(i);
	ll now=0;
	for(int i=0;i<m;i++)while(check(i,now+1))now++;
	stack <ll> ans;
	for(int i=q-1;i>=0;i--)
	{
		ans.push(now);
		s[qu[i].first][qu[i].second]='.';update(qu[i].first);
		while(check2(qu[i].first,qu[i].second,now+1))now++;
	}
	while(ans.size())printf("%d\n",ans.top()),ans.pop();
	return 0;
}