#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
#define forn(i, x, y) for(int i = x; i <= y; i++)
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

string a[1000005];
vi pre[1000005];
vi pre2[1000005];
int n,m;
bool boolor=0;
bool solve(int mid) {
	int prod=(2*mid+1)*(2*mid+1);
	fr(i,0,n) {
		pre2[i].assign(m+2, 0);
	}
	fr(i,1,n) {
		fr(j,1,m) {
			if(i-mid>0&&j-mid>0&&i+mid<=n&&j+mid<=m)
				if(pre[i+mid][j+mid]+pre[i-mid-1][j-mid-1]-pre[i-mid-1][j+mid]-pre[i+mid][j-mid-1]==prod) {
					pre2[i][j]=1;
				}
		}
	}
	if(boolor)
		return 1;
	fr(i,1,n)
		fr(j,1,m)
			pre2[i][j]+=pre2[i][j-1];
	fr(i,1,n)
		fr(j,1,m)
			pre2[i][j]+=pre2[i-1][j];
	fr(i,1,n)
		fr(j,1,m)
			if(a[i][j]=='X') {
				if(pre2[min(n,i+mid)][min(m,j+mid)]+pre2[max(0,i-mid-1)][max(0,j-mid-1)]-pre2[max(0,i-mid-1)][min(m,j+mid)]-pre2[min(n,i+mid)][max(0,j-mid-1)]==0)
					return 0;
			}
	return 1;
}
void solve() {
	cin>>n>>m;
	a[0]=string(m+2,'.');
	a[n+1]=string(m+2,'.');
	fr(i,0,n+1)
		pre[i].resize(m+2,0);
	fr(i,1,n) {
		cin>>a[i];
		a[i]='.'+a[i]+'.';
	}
	fr(i,0,n+1)
		fr(j,1,m+1) {
			pre[i][j]=pre[i][j-1]+(a[i][j]=='X');
	}
	fr(i,1,n+1)
		fr(j,1,m+1)
			pre[i][j]+=pre[i-1][j];
	int lo=0,hi=min(n,m)+1,mid=(lo+hi+1)/2;
	while(lo<hi) {
		if(solve(mid)) {
			lo=mid;
		} else
			hi=mid-1;
		mid=(lo+hi+1)/2;
	}
	boolor=1;
	solve(mid);
	cout<<mid<<endl;
	fr(i,1,n) {
		fr(j,1,m) {
			if(pre2[i][j])
				cout<<'X';
			else
				cout<<'.';
		}
		cout<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(7);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(f80)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}