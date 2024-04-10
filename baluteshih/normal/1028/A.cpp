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

string mp[200];

int main()
{jizz
	int n,m,x=-1,y=-1,ex,ey;
	cin >> n >> m;
	for(int i=0;i<n;++i)
		cin >> mp[i];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			if(mp[i][j]=='B') 
			{
				x=i,y=j;
				break;
			}
		if(~x) break;
	}
	for(ex=x;ex<n&&mp[ex][y]=='B';++ex);
	for(ey=y;ey<m&&mp[x][ey]=='B';++ey);
	cout << x+(ex-x)/2+1 << " " << y+(ey-y)/2+1 << "\n";
}