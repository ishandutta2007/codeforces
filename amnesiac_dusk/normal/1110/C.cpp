/*
 * 	Meet me on the battlefield
 * 		Even on the darkest night
 * 			I will be your sword and shield,
 * 				Your camouflage and you will be mine
 * 	Echoes of the shots ring out
 * 		We may be the first to fall
 * 			Everything could stay the same
 * 				Or we could change it all
 */
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
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int aaa[25]={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
void solve()
{
	int q;
	cin>>q;
	while(q--) {
		int a;
		cin>>a;
		if((a&(a+1))==0) {
			int nb=0;
			while(a>0) {
				nb++;
				a/=2;
			}
			cout<<aaa[nb-2]<<endl;
			continue;
		}
		int te=1;
		while(a>te) {
			a|=te;
			te*=2;
		}
		cout<<a<<endl;
	}
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