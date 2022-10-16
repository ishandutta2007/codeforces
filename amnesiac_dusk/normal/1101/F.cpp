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
#define double long double
//typedef long double f80;
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
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
struct tru {
	int start,finish,consum,refu;
};
vector<tru> trucks;
int a[405];
int te[4];
bool check(int num, int val) {
	auto &truck=trucks[num];
	int fuel=val,rfuel=0;
	for(int i=truck.start+1; i<=truck.finish; i++) {
		if(val<truck.consum*(a[i]-a[i-1]))
			return 0;
		if(fuel<truck.consum*(a[i]-a[i-1])) {
			fuel=val;
			rfuel++;
		}
		fuel-=truck.consum*(a[i]-a[i-1]);
	}
	if(rfuel<=truck.refu)
		return 1;
	return 0;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>a[i];
	}
	fr(i,1,m) {
		fr(j,0,3) {
			cin>>te[j];
		}
		trucks.pb({te[0],te[1],te[2],te[3]});
	}
	random_shuffle(all(trucks),rng);
	int curv=1;
	for(int i=0; i<trucks.size(); i++) {
		if(!check(i,curv)) {
			int l=curv+1,r=infl,m=(l+r)/2;
			while(l<r) {
				if(check(i,m))
					r=m;
				else
					l=m+1;
				m=(l+r)/2;
			}
			curv=m;
		}
	}
	cout<<curv<<endl;
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