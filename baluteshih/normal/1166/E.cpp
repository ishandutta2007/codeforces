#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bitset<10005> bit[55],tmp;

int main()
{jizz
	int n,m,t,x;
	cin >> m >> n;
	for(int i=0;i<m;++i)
	{
		cin >> t;
		while(t--)
			cin >> x,bit[i][x]=1;
	}
	for(int i=0;i<m;++i)
	{
		tmp=~bit[i];
		for(int j=0;j<m;++j)
			if((tmp|bit[j])==tmp)
				return cout << "impossible\n",0;
	}
	cout << "possible\n";
}