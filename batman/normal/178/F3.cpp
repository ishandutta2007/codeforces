#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)5010)

ll n,k;
string s[N];

vector <ll> solve(ll xl=0,ll xr=n,ll p=0)
{
	vector <ll> now(1);
	while(xl<xr && (ll)s[xl].size()<=p)xl++,now.push_back(0);
	for(int i=xl+1,lst=xl;i<=xr;i++)
	{
		if(i!=xr && s[i-1][p]==s[i][p])continue;
		vector <ll> ex=solve(lst,i,p+1);
		vector <ll> now2((ll)now.size()+(ll)ex.size()-1);
		for(int j=0;j<ex.size();j++)
			for(int j2=j;j2<(ll)now.size()+j;j2++)
				now2[j2]=max(now2[j2],now[j2-j]+ex[j]+j*(j-1)/2);
		now=now2;
		lst=i;
	}
	return now;
}

char cc[512];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf(" %s",&cc),s[i]=cc;
	sort(s,s+n);
	cout<<solve()[k];
	return 0;
}