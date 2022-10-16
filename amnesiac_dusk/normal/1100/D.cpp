/*
 * RD
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
//#ifndef rd
//#define endl '\n'
//#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//12367769,266916112,123798211
ll powm(ll a, ll b, ll m);

int rooks[667][2];
int po[1000][1000];
int quer=0;
int query(int i, int j)
{
	quer++;
	assert(quer<=2000);
	cout<<i<<" "<<j<<endl;
	int k,x,y;
	cin>>k>>x>>y;
	if(k==-1&&x==-1&&y==-1)
		exit(0);
	if(k==0&&x==0&&y==0)
		assert(0);
	po[rooks[k][0]][rooks[k][1]]=0;
	rooks[k][0]=x;
	rooks[k][1]=y;
	po[rooks[k][0]][rooks[k][1]]=1;
}
map<pii,int> hol;
void solve()
{
	int x,y,u,v;
	cin>>x>>y;
	for(int i=1; i<=666; i++)
	{
		cin>>u>>v;
		po[u][v]=1;
		rooks[i][0]=u;
		rooks[i][1]=v;
	}
	while(x>500)
	{
		query(x-1,y);
		x--;
	}
	while(x<=499)
	{
		query(x+1,y);
		x++;
	}
	while(y>500)
	{
		query(x,y-1);
		y--;
	}
	while(y<=499)
	{
		query(x,y+1);
		y++;
	}
	int t1=0,t2=0,t3=0,t4=0;
	for(int i=1; i<=666; i++)
	{
		if(!(rooks[i][0]<499&&rooks[i][1]<499))
			t1++;
		if(!(rooks[i][0]>499&&rooks[i][1]<499))
			t2++;
		if(!(rooks[i][0]<499&&rooks[i][1]>499))
			t3++;
		if(!(rooks[i][0]>499&&rooks[i][1]>499))
			t4++;
	}
	int mx=-1,my=-1;
	if(t1>499)
		mx=1,my=1;
	else if(t2>499)
		mx=-1,my=1;
	else if(t3>499)
		mx=1,my=-1;
	else if(t4>499)
		mx=-1,my=-1;
	else
		assert(0);
	while(!po[x+mx][y+my])
	{
		query(x+mx,y+my);
		x+=mx;
		y+=my;
	}
	if(po[x+mx][y+my])
		query(x+mx,y);
	assert(0);
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
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