/*
 * 	Yet I'm feeling like
 * 		There is no better place than right by your side
 * 			I had a little taste
 * 				And I'll only spoil the party anyway
 * 					'Cause all the girls are looking fine
 * 						But you're the only one on my mind
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
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1e9+7;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int to[100005];
int nb[100005],ju[100005],la[100005];
int bs=300;
int bnum[100005];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>to[i],to[i]+=i;
	for(int i=1; i<=n; i++)
		bnum[i]=i/300+1;
	for(int i=n; i>0; i--) {
		if(to[i]>n||bnum[i]!=bnum[to[i]]) {
			nb[i]=to[i];
			la[i]=i;
			ju[i]=1;
		} else {
			nb[i]=nb[to[i]];
			la[i]=la[to[i]];
			ju[i]=ju[to[i]]+1;
		}
	}
	int t,a,b;
	while(m--) {
		cin>>t;
		if(t) {
			cin>>a;
			int ans=0,ans2=a;
			while(a<=n) {
				ans+=ju[a];
				ans2=la[a];
				a=nb[a];
			}
			cout<<ans2<<" "<<ans<<endl;
		}
		else {
			cin>>a>>b;
			to[a]=a+b;
			for(int i=a; bnum[i]==bnum[a]; i--) {
				if(to[i]>n||bnum[i]!=bnum[to[i]]) {
					nb[i]=to[i];
					la[i]=i;
					ju[i]=1;
				} else {
					nb[i]=nb[to[i]];
					la[i]=la[to[i]];
					ju[i]=ju[to[i]]+1;
				}
			}
		}
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