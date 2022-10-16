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

int dp[105][105][105][2];
int a[105];
string s;
int recur(int l, int r, int num, int type) {
	if(l>r) {
		return a[num];
	}
	if(~dp[l][r][num][type])
		return dp[l][r][num][type];
	int mm=0;
	if(num>0) {
		mm=a[num]+max(recur(l,r,0,0),recur(l,r,0,1));
	}
	for(int k=l; k<=r; k++) {
		if(s[k]!=s[l]) {
			break;
		}
		mm=max(recur(k+1,r,num,type)+a[k-l+1],mm);
	}
	for(int k=r; k>=l; k--) {
		if(s[k]!=s[r]) {
			break;
		}
		mm=max(recur(l,k-1,num,type)+a[r-k+1],mm);
	}
	for(int k=l; k<r; k++) {
		mm=max(recur(l,k,0,1-type)+recur(k+1,r,num,type),mm);
		mm=max(recur(l,k,num,type)+recur(k+1,r,0,1-type),mm);
	}
	if(s[l]==type)
		mm=max(mm,recur(l+1,r,num+1,type));
	if(s[r]==type)
		mm=max(mm,recur(l,r-1,num+1,type));
	return dp[l][r][num][type]=mm;
}
void solve() {
	int n;
	cin>>n>>s;
	s='0'+s;
	for(int i=1; i<=n; i++)
		s[i]-='0';
	fr(i,1,n)
		cin>>a[i];
	fr(i,0,n)
		fr(j,0,n)
			fr(k,0,n)
				fr(l,0,1)
					dp[i][j][k][l]=-1;
	cout<<max(recur(1,n,0,0),recur(1,n,0,1))<<endl;
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