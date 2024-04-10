#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;
pii le[200005],ri[200005];
int dx[128],dy[128];

bool check(int x,int y,int d)
{
	if(((x+y)%2+2)%2!=d%2)
		return 0;
	if(abs(x)+abs(y)>d)
		return 0;
	return 1;
}

int main()
{jizz
	int n,x,y,l,r;
	dx['U']=0,dy['U']=1;
	dx['D']=0,dy['D']=-1;
	dx['L']=-1,dy['L']=0;
	dx['R']=1,dy['R']=0;
	cin >> n >> s >> x >> y,l=1,r=n;
	if(!check(x,y,n))
		return cout << "-1\n",0;
	le[0]=MP(0,0),ri[n+1]=MP(x,y);
	for(int i=1;i<=n;++i)
		le[i]=MP(le[i-1].F+dx[s[i-1]],le[i-1].S+dy[s[i-1]]);
	if(le[n]==MP(x,y))
		return cout << "0\n",0;
	for(int i=n;i>0;--i)
		ri[i]=MP(ri[i+1].F-dx[s[i-1]],ri[i+1].S-dy[s[i-1]]);
	while(l<r)
	{
		int m=l+r>>1,flag=0;
		for(int i=m;i<=n&&!flag;++i)
			if(check(ri[i+1].F-le[i-m].F,ri[i+1].S-le[i-m].S,m)) flag=1;
		if(flag) r=m;
		else l=m+1;
	}
	cout << l << "\n";
}