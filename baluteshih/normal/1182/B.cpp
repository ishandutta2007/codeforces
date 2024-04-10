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

string mp[505];

int main()
{jizz
	int n,m,r,rc,cc,c,cnt,XD;
	cin >> n >> m;
	for(int i=0;i<n;++i)
		cin >> mp[i];
	cnt=0;
	for(int i=0;i<n;++i)
	{
		int tmp=0;
		for(int j=0;j<m;++j)
			if(mp[i][j]=='*') ++tmp;
		if(tmp>1)
			++cnt,r=i,rc=tmp;
	}
	if(cnt!=1)
		return cout << "NO\n",0;
	cnt=0;
	for(int i=0;i<m;++i)
	{
		int tmp=0;
		for(int j=0;j<n;++j)
			if(mp[j][i]=='*') ++tmp;
		if(tmp>1)
			++cnt,c=i,cc=tmp;
	}
	if(cnt!=1||mp[r][c]!='*')
		return cout << "NO\n",0;
	cnt=XD=0;
	for(int i=c;i<m;++i)
		if(mp[r][i]!='*') cnt=1;
		else if(cnt)
			return cout << "NO\n",0;
		else mp[r][i]='.',++XD;
	if(XD<=1)
		return cout << "NO\n",0;
	mp[r][c]='*',cnt=XD=0;
	for(int i=r;i<n;++i)
		if(mp[i][c]!='*') cnt=1;
		else if(cnt)
			return cout << "NO\n",0;
		else mp[i][c]='.',++XD;
	if(XD<=1)
		return cout << "NO\n",0;
	mp[r][c]='*',cnt=XD=0;
	for(int i=r;i>=0;--i)
		if(mp[i][c]!='*') cnt=1;
		else if(cnt)
			return cout << "NO\n",0;
		else mp[i][c]='.',++XD;
	if(XD<=1)
		return cout << "NO\n",0;
	mp[r][c]='*',cnt=XD=0;
	for(int i=c;i>=0;--i)
		if(mp[r][i]!='*') cnt=1;
		else if(cnt)
			return cout << "NO\n",0;
		else mp[r][i]='.',++XD;
	if(XD<=1)
		return cout << "NO\n",0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(mp[i][j]=='*')
				return cout << "NO\n",0;
	cout << "YES\n";
}