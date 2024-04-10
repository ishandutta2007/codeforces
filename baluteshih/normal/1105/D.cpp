#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll mp[1005][1005],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},n,m;
ll speed[10],cnt[10];

struct mode
{
	ll p,d,x,y,turn;
	mode(ll p,ll d,ll x,ll y):p(p),d(d),x(x),y(y){
		if(d==0) turn=-1;
		else turn=(d-1)/speed[p];
	}
	bool operator<(const mode&a)const{
		if(turn!=a.turn) return turn>a.turn;
		if(p!=a.p) return p>a.p;
		return d>a.d;
	}
};

priority_queue<mode> q;

bool check(ll x,ll y)
{
	return !(x<1||y<1||x>n||y>m||mp[x][y]!=0);
}

int main()
{jizz
	ll p;
	char c;
	cin >> n >> m >> p;
	for(int i=1;i<=p;++i)
		cin >> speed[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin >> c;
			if(c=='.') mp[i][j]=0;
			else if(c=='#') mp[i][j]=-1;
			else q.push(mode(c-'0',0,i,j));
		}
	while(!q.empty())
	{
		auto t=q.top();
		q.pop();
		if(mp[t.x][t.y]) continue;
		mp[t.x][t.y]=t.p;
		for(int i=0;i<4;++i)
			if(check(t.x+dx[i],t.y+dy[i]))
				q.push(mode(t.p,t.d+1,t.x+dx[i],t.y+dy[i]));
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mp[i][j]>0)
				++cnt[mp[i][j]];
	for(int i=1;i<=p;++i)
		cout << cnt[i] << " \n"[i==p];
}