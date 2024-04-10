/*
 * 	Just close your eyes
 * 		The sun is going down
 * 			You'll be alright...
 * 				No one can hurt you now
 * 					Come, morning light...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
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
const int mod=998244353;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[5005];
int pgcd[5005];
bool np[32005];
vector<int> ps;
set<int> lul;
void solve() {
	int n,m,te;
	for(int i=2; i<=32000; i++)
		if(!np[i])
		{
			ps.pb(i);
			for(int j=i*i; j<=32000; j+=i)
				np[j]=1;
		}
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=m; i++)
		cin>>te,lul.insert(te);
	for(int i=1; i<=n; i++)
		pgcd[i]=gcd(pgcd[i-1],a[i]);
	int lol=1;
	for(int i=n; i>0; i--)
	{
		int tem=pgcd[i]/lol;
		int score=0;
		for(int j:ps)
			while(tem%j==0)
			{
				if(lul.count(j))
					score--;
				else
					score++;
				tem/=j;
			}
		if(tem>1)
			if(lul.count(tem))
				score--;
			else
				score++;
		if(score<=0)
			lol=pgcd[i];
		a[i]/=lol;
	}
	int score=0;
	for(int i=1; i<=n; i++)
	{
		int tem=a[i];
		for(int j:ps)
			while(tem%j==0)
			{
				if(lul.count(j))
					score--;
				else
					score++;
				tem/=j;
			}
		if(tem>1)
			if(lul.count(tem))
				score--;
			else
				score++;
	}
	cout<<score<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
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