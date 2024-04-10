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
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string a[6];
int cost[6];


void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<string> lul={"RGB","RBG","GBR","GRB","BRG","BGR"};
	for(int i=0; i<n; i++) {
		for(int j=0; j<6; j++) {
			a[j]+=lul[j][i%3];
			if(lul[j][i%3]!=s[i])
				cost[j]++;
		}
	}
	int mm=0;
	for(int i=0; i<6; i++) {
		if(cost[mm]>cost[i])
			mm=i;
	}
	cout<<cost[mm]<<endl;
	cout<<a[mm];
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