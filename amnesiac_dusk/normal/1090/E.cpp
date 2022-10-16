/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int grid[8][8][8][8];
pii parent[8][8][8][8];
vector<pii> gra[8][8];
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
inline bool valid(int i, int j)
{
	return (i>=0&&i<8)&&(j>=0)&&j<8;
}
bool vis[8][8][8][8];
bool done[64];
bool cmp(pii a, pii b)
{
	if(grid[a.fi][a.se]!=grid[b.fi][b.se])
		return grid[a.fi][a.se]>grid[b.fi][b.se];
	if(a.fi!=b.fi)
		return a.fi>b.fi;
	return a.se>b.se;
}
string lolo(pii lul)
{
	int i=lul.fi,j=lul.se;
	string str="";
	str+=((char)(i+'a'));
	str+=((char)(j+'1'));
	return str;
}
queue<pair<pii,pii>> movesexecution;
bool curgrid[8][8];
void solve()
{
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			for(int k=0; k<8; k++)
				if(valid(i+dx[k],j+dy[k]))
					gra[i][j].push_back({i+dx[k],j+dy[k]});
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
		{
			queue<pii> curr,next;
			curr.push({i,j});
			vis[i][j][i][j]=1;
			int num=1;
			while(curr.size())
			{
				while(curr.size())
				{
					auto te=curr.front();
					curr.pop();
					for(auto ho:gra[te.first][te.second])
						if(!vis[i][j][ho.fi][ho.se])
						{
							vis[i][j][ho.fi][ho.se]=1;
							grid[i][j][ho.fi][ho.se]=num;
							parent[i][j][ho.fi][ho.se]=te;
							next.push({ho.fi,ho.se});
						}
				}
				curr=next;
				while(next.size())
					next.pop();
				num++;
			}
	}
	int k;
	cin>>k;
	vector<pii> tola;
	string lol;
	for(int i=0; i<k; i++)
	{
		cin>>lol;
		tola.pb({lol[0]-'a',lol[1]-'1'});
		curgrid[lol[0]-'a'][lol[1]-'1']=1;
	}
	int moves=0;
	int kk=k;
	for(int j=0; j<8&&k>0; j++)
		for(int i=0; i<8&&k>0; i++,k--)
		{
			int mi=-1;
			for(int l=0; l<kk; l++)
			{
				if(!done[l])
				{
					if(mi==-1)
						mi=l;
					if(grid[i][j][tola[l].fi][tola[l].se]<grid[i][j][tola[mi].fi][tola[mi].se])
						mi=l;
				}
			}
			done[mi]=1;
			while(grid[i][j][tola[mi].fi][tola[mi].se])
			{
				moves++;
				pii tempola=tola[mi];
				tola[mi]=parent[i][j][tola[mi].fi][tola[mi].se];
				pii lola=tola[mi];
				movesexecution.push({tempola,lola});
			}
		}
	cout<<moves<<endl;
	while(movesexecution.size())
	{
		auto lols=movesexecution.front();
		movesexecution.pop();
		if(curgrid[lols.fi.fi][lols.fi.se]&&(!curgrid[lols.se.fi][lols.se.se]))
		{
			curgrid[lols.fi.fi][lols.fi.se]=0;
			curgrid[lols.se.fi][lols.se.se]=1;
			cout<<lolo(lols.fi)<<"-"<<lolo(lols.se)<<endl;
		}
		else
		{
			movesexecution.push(lols);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
//#ifdef rd
//	clk=clock()-clk;
//	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
//#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}