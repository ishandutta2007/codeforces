#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> place[101];
char ans[105];

int main()
{jizz
	int n,x,cnt=0,ncnt=0,tmp=-1;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> x,place[x].pb(i);
	for(int i=1;i<=100;++i)
		if(place[i].size()==1) ++cnt,ans[place[i][0]]=cnt&1?'A':'B';
		else if(place[i].size()>1)
		{
			++ncnt;
			if(!~tmp) tmp=i;
			else if(place[tmp].size()<place[i].size()) tmp=i;
		}
	if(cnt&1)
	{
		if(ncnt==0)
			return cout << "NO\n",0;
		if(place[tmp].size()==2)
			return cout << "NO\n",0;
		ans[place[tmp][0]]='B';
		for(int j=1;j<place[tmp].size();++j)
			ans[place[tmp][j]]='A';
		for(int i=1;i<=100;++i)
			if(place[i].size()>1 && i!=tmp)
				for(auto j:place[i])
					ans[j]='A';
	}
	else
	{
		for(int i=1;i<=100;++i)
			if(place[i].size()>1)
				for(auto j:place[i])
					ans[j]='A';
	}
	ans[n]=0;
	cout << "YES\n" << ans << "\n";
}