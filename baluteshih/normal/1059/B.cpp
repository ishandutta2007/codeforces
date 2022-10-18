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

string s[1000];
int n,m;
int dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1};

bool check(int x,int y)
{
	return !(x<0 || y<0 || x>=n || y>=m || s[x][y]=='.');
}

bool BC(int x,int y)
{
	if(x<0 || y<0 || x>=n || y>=m) return 0;
	for(int i=0;i<8;++i)
		if(!check(x+dx[i],y+dy[i])) return 0;
	return 1;
}

int main()
{jizz
	int flag;
	cin >> n >> m;
	for(int i=0;i<n;++i)
		cin >> s[i];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(s[i][j]=='#')
			{
				flag=0;
				for(int k=0;k<8;++k)
					flag|=BC(i+dx[k],j+dy[k]);
				if(!flag)
					return cout << "NO\n",0;
			}
	cout << "YES\n";
}