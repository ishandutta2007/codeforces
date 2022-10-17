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

const int N=300005;
int a[N],b[N],prea[N],preb[N],preia[N],preib[N];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i];
		prea[i]=prea[i-1]+a[i];
		preia[i]=preia[i-1]+a[i]*i;
	}
	fr(i,1,n) {
		cin>>b[i];
		preb[i]=preb[i-1]+b[i];
		preib[i]=preib[i-1]+b[i]*i;
	}
	int ans=0,sum=0;
	ans=max(ans,preia[n]-prea[n]+2*n*preb[n]-preib[n]);
	for(int i=1; i<=n; i++) {
		if(i&1) {
			sum+=a[i]*(2*i-2)+b[i]*(2*i-1);
			ans=max(ans,sum+preib[n]-preib[i]+(preb[n]-preb[i])*(i-1)
					+(prea[n]-prea[i])*(2*n+i)-preia[n]+preia[i]);
		} else {
			sum+=b[i]*(2*i-2)+a[i]*(2*i-1);
			ans=max(ans,sum+preia[n]-preia[i]+(prea[n]-prea[i])*(i-1)
					+(preb[n]-preb[i])*(2*n+i)-preib[n]+preib[i]);
		}
	}
	cout<<ans<<endl;
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