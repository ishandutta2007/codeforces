#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)501*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,x1,y1,up=-1,down=-1,lft=-1,rght=-1;
ll up_lft=-1,up_rght=-1,down_lft=-1,down_rght=-1;
pair <ll,ll> a[N];
char c[N];

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//cin>>n>>x1>>y1;
	scanf("%d%d%d",&n,&x1,&y1);
	for(int i=0;i<n;i++)
	{
		scanf(" %c %d %d",&c[i],&a[i].first,&a[i].second);
		if(a[i].first==x1 && a[i].second>y1 && (up==-1 || a[up].second>a[i].second))up=i;
		if(a[i].first==x1 && a[i].second<y1 && (down==-1 || a[down].second<a[i].second))down=i;
		if(a[i].second==y1 && a[i].first<x1 && (lft==-1 || a[lft].first<a[i].first))lft=i;
		if(a[i].second==y1 && a[i].first>x1 && (rght==-1 || a[rght].first>a[i].first))rght=i;
		if(a[i].first-x1==a[i].second-y1 && a[i].first>x1 && (up_rght==-1 || a[up_rght].first>a[i].first))up_rght=i;
		if(a[i].first-x1==a[i].second-y1 && a[i].first<x1 && (down_lft==-1 || a[down_lft].first<a[i].first))down_lft=i;
		if(a[i].first-x1==y1-a[i].second && a[i].first>x1 && (down_rght==-1 || a[down_rght].first>a[i].first))down_rght=i;
		if(a[i].first-x1==y1-a[i].second && a[i].first<x1 && (up_lft==-1 || a[up_lft].first<a[i].first))up_lft=i;
	}
	if((up==-1 || c[up]=='B')
	 && (down==-1 || c[down]=='B') && (lft==-1 || c[lft]=='B') && (rght==-1 || c[rght]=='B')
	  && (down_rght==-1 || c[down_rght]=='R') && (down_lft==-1 || c[down_lft]=='R')
	   && (up_lft==-1 || c[up_lft]=='R') && (up_rght==-1 || c[up_rght]=='R'))printf("NO");
	else printf("YES");
	return 0;
}