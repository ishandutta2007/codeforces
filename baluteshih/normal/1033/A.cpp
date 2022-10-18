#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int used[1005][1005],n,dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};
queue<pii> q;

bool check(int x,int y)
{
	return !(x<=0||y<=0||x>n||y>n||used[x][y]);
}

int main()
{jizz
	int ax,ay,bx,by,cx,cy;
	cin >> n >> bx >> by >> ax >> ay >> cx >> cy,used[bx][by]=1;
	for(int i=1;i<n;++i)
		for(int j=0;j<8;++j)
			if(check(bx+i*dx[j],by+i*dy[j])) used[bx+i*dx[j]][by+i*dy[j]]=1;
	q.push(MP(ax,ay)),used[ax][ay]=1;
	while(!q.empty())
	{
		auto tmp=q.front();
		q.pop();
		if(tmp.F==cx&&tmp.S==cy)
			return cout << "YES\n",0;
		for(int i=0;i<8;++i)
			if(check(tmp.F+dx[i],tmp.S+dy[i]))
				q.push(MP(tmp.F+dx[i],tmp.S+dy[i])),used[tmp.F+dx[i]][tmp.S+dy[i]]=1;
	}
	cout << "NO\n";
}