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
	uniform_int_distribution<int> uid(0,lim);
	return uid(rang);
}
int a[200005];
vector<int> ld,ld2,res;
vector<pii> segs,segs2;
vi reduce(vector<int> ld) {
	ld.clear();
	return ld2;
}
bool check(int i) {
	int te=(1<<30)-1-i;
	for(int ii:ld) {
		if(te<(ii^te)) {
			te^=ii;
		}
	}
	if(te+1==(1<<30))
		return 0;
	return 1;
}
void solve()
{
	int n;
	cin>>n;
	int xorian=0;
	fr(i,1,n) {
		cin>>a[i];
		xorian^=a[i];
	}
	if(xorian==0) {
		cout<<-1<<endl;
		return;
	}
	segs.pb({1,n});
	ld.pb(xorian);
	bool notdone=1;
	while(notdone) {
		notdone=0;
		for(int ii=0; ii<segs.size(); ii++) {
			auto &temp=segs[ii];
			int xo=0;
			for(int i=temp.fi; i<temp.se&&(!notdone); i++) {
				xo^=a[i];
				if(check(xo)) {
					ld.pb(xo);
					for(int j=29; j>=0; j--){
						for(int i:ld) {
							if(i&(1<<j)) {
								ld2.pb(i);
								for(int &k:ld) {
									if(k&(1<<j))
										k^=i;
								}
								break;
							}
						}
					}
					ld2.swap(ld);
					ld2.clear();
					for(int j=0; j<ii; j++)
						segs2.pb(segs[j]);
					segs2.pb({temp.fi,i});
					segs2.pb({i+1,temp.se});
					for(int j=ii+1; j<segs.size(); j++)
						segs2.pb(segs[j]);
					segs.swap(segs2);
					segs2.clear();
					notdone=1;
				}
			}
			//if(notdone)
			//	break;
		}
	}
	cout<<ld.size()<<endl;
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