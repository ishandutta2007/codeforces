#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct mode
{
	string a,b,c,d;
}ans[100005];

string s;
vector<vector<vector<string>>> v(1000005,vector<vector<string>>(5,vector<string>()));
char alph[5]={'a','e','i','o','u'};
int krr[256],cans[100005],all[100005];

int main()
{jizz
	int n,ls,cnt,mx=0,l,r;
	cin >> n,l=0,r=n/2;
	MEM(krr,-1);
	for(int i=0;i<5;++i)
		krr[alph[i]]=i;
	while(n--)
	{
		cin >> s,cnt=0;
		for(auto c:s)
			if(~krr[c])
				ls=krr[c],++cnt;
		v[cnt][ls].pb(s),mx=max(mx,cnt);
	}
	for(int i=1;i<=mx;++i)
		for(auto &t:v[i])
			cans[i]+=t.size()/2,all[i]+=t.size();
	while(l<r)
	{
		int m=(l+r)/2+1,ff=0,ss=0;
		for(int i=1;i<=mx;++i)
		{
			if(ss+cans[i]<m)
				ss+=cans[i],ff+=(all[i]-cans[i]*2)/2;
			else
				ff+=(all[i]-(m-ss)*2)/2,ss=m;
		}
		if(ff<m||ss<m) r=m-1;
		else l=m;
	}
	cout << l << "\n";
	int ff=0,ss=0;
	for(int i=1;i<=mx;++i)
	{
		for(auto &t:v[i])
		{
			while(t.size()>=2&&ss<l)
			{
				ans[ss].b=t.back();
				t.pop_back();
				ans[ss].d=t.back();
				t.pop_back();	
				++ss;
			}
			while(t.size())
			{
				if(ff&1) ans[ff>>1].c=t.back();
				else ans[ff>>1].a=t.back();
				t.pop_back();
				++ff;
			}
		}
		if(ff&1) --ff;
	}
	for(int i=0;i<l;++i)
		cout << ans[i].a << " " << ans[i].b << "\n" << ans[i].c << " " << ans[i].d << "\n";
}