#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
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
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int a[1005][1005];
int pre[1005][1005];
int table[11][1005][11][1005];
int query(int x1, int x2, int y1, int y2) {
	x1--;
	x2--;
	y1--;
	y2--;
	int lenx=x2-x1+1;
	int kx=31-__builtin_clz(lenx);
	int leny=y2-y1+1;
	int ky=31-__builtin_clz(leny);
	trace(kx,ky,lenx,leny);
	int min_R1=max(table[kx][x1][ky][y1],table[kx][x1][ky][y2+1-(1<<ky)]);
	int min_R2=max(table[kx][x2+1-(1<<kx)][ky][y1],table[kx][x2+1-(1<<kx)][ky][y2+1-(1<<ky)]);
	return max(min_R1,min_R2);
}
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n)
		fr(j,1,m)
		{
			cin>>a[i][j];
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	int sum=0;
	int lm=32-__builtin_clz(m);
	for(int i=n; i>0; i--)
		for(int j=m; j>0; j--) {
			if(a[i][j]+a[i-1][j-1]-a[i-1][j]-a[i][j-1]) {
				int mi=min(min(pre[i+1][j+1],pre[i+1][j]),pre[i][j+1]);
				pre[i][j]=mi+1;
			}
		}
	for(int ir=0; ir<n; ir++) {
		for(int ic=0; ic<m; ic++)
			table[0][ir][0][ic]=pre[ir+1][ic+1];
		for(int jc=1; jc<=lm; jc++)
			for(int ic=0; ic+(1<<(jc-1))<=m; ic++)
				table[0][ir][jc][ic]=max(table[0][ir][jc-1][ic],table[0][ir][jc-1][ic+(1<<(jc-1))]);
	}
	int ln=32-__builtin_clz(n);
	for(int jr=1; jr<=ln; jr++)
		for(int ir=0; ir+(1<<(jr-1))<=n; ir++)
			for(int jc=0; jc<=lm; jc++)
				for(int ic=0; ic<m; ic++)
					table[jr][ir][jc][ic]=max(table[jr-1][ir][jc][ic],table[jr-1][ir+(1<<(jr-1))][jc][ic]);
	int q;
	cin>>q;
	while(q--) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int lo=0,hi=min(x2-x1+1,y2-y1+1),mid=(lo+hi+1)/2;
		while(lo<hi) {
			if(query(x1,x2-mid+1,y1,y2-mid+1)>=mid) {
				lo=mid;
			} else
				hi=mid-1;
			mid=(lo+hi+1)/2;
		}
		cout<<mid<<endl;
	}

}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t)
	{
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}