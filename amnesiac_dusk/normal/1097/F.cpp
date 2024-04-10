/*
 * 	I believe if I knew where I was going I'd lose my way
 * 	I believe that the words that he told you are not your grave
 * 	I know that we are not the weight of all our memories
 * 	I believe in the things that I am afraid to say
 *
 * 	I believe that today it's okay to be not okay
*/
#pragma GCC optimize("Ofast,unroll-loops")
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
typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
#define dpr(x) cout<<#x<<": "<<x<<endl
typedef vector<int> vi;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim)
{
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}

const int lol=7005;
bitset<lol> a[100005];
bitset<lol> b[lol];
bitset<lol> c,temp;
vector<int> facs[lol];
bool square[7005];
void solve()
{
	int n,q,type,x,y,z,v;
	cin>>n>>q;
	for(int i=2; i*i<lol; i++)
		for(int j=i*i; j<lol; j+=i*i)
			square[j]=1;
	for(int i=1; i<lol; i++)
		for(int j=i; j<lol; j+=i) {
			if(square[j/i]==0)
				b[i][j]=1;
			facs[j].pb(i);
		}
	for(int i=1; i<=q; i++) {
		cin>>type;
		if(type==1) {
			cin>>x>>v;
			a[x].reset();
			for(int j:facs[v])
				a[x][j]=1;
		}
		if(type==2) {
			cin>>x>>y>>z;
			temp=a[y];
			temp^=a[z];
			swap(a[x],temp);
		}
		if(type==3) {
			cin>>x>>y>>z;
			temp=a[y];
			temp&=a[z];
			swap(a[x],temp);
		}
		if(type==4) {
			cin>>x>>v;
			c=a[x];
			c&=b[v];
			putchar('0'+(c.count()&1));
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}