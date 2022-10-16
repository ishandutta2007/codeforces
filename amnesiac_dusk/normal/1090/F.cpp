/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
//#ifndef rd
//#define endl '\n'
//#endif
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

int invertor[5][5]={{3, 4, -1, -4, -1}, {-1, 8, -1, -4, -1}, {-1, -4, 11, -4, -1}, {-1, -4, -1, 8, -1}, {-1, -4, -1, 4, 3}};
int a[1001];
//int lul[12]={0,1,0,2,1,3,5,7,8,10,12,14};
int offset;
int query(int i, int j, int k)
{
	i+=offset;
	j+=offset;
	k+=offset;
//	return max(max(lul[i],lul[j]),lul[k])+min(min(lul[i],lul[j]),lul[k]);
	cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
	int te;
	cin>>te;
	return te;
}
int qres[6];
int temp[6];
vector<pii> tola;
void calculate()
{
	for(int i=1; i<=5; i++)
			qres[i]=0;
	for(int i=1; i<=5; i++)
			temp[i]=0;
	for(int i=1; i<=5; i++)
		for(int j=i+1; j<=5; j++)
			for(int k=j+1; k<=5; k++)
			{
				int te=query(i,j,k);
				qres[i]+=te;
				qres[j]+=te;
				qres[k]+=te;
			}
	tola.clear();
	tola.pb({-1,-1});
	for(int i=1; i<=5; i++)
		tola.pb({qres[i],i});
	sort(all(tola));
	for(int i=1; i<=5; i++)
		for(int j=1; j<=5; j++)
			temp[i]+=invertor[i-1][j-1]*tola[j].fi;
	for(int i=1; i<=5; i++)
		a[offset+tola[i].se]=temp[i]/12;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=0; i+5<=n; i+=5) {
		offset=i;
		calculate();
	}
	offset=n-5;
	calculate();
	cout<<"! ";
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
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