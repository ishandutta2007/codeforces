#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
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
#define int long long
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
// const int mod=998244353;
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


vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int tr11[2000005],tr2[2000005];
int n;
void update(int p, int val, int val2) {
	for(p+=n+1; p>0; p>>=1) {
		tr11[p]+=val;
		tr2[p]+=val2;
	}
}
pii qur(int l, int r=n+1) {
	int ff=0,ss=0;
	for(l+=n+1,r+=n+1; l<r; l>>=1,r>>=1) {
		if(l&1) {
			ff+=tr11[l];
			ss+=tr2[l++];
		}
		if(r&1) {
			ff+=tr11[--r];
			ss+=tr2[r];
		}
	}
	return {ff,ss};
}
int pola[1000005],polb[1000005];
void solve() {
	int m;
	cin>>m>>n;
	string a,b,s;
	cin>>a>>b>>s;
	auto az=z_function(s+a);
	reverse(all(b));
	reverse(all(s));
	auto bz=z_function(s+b);
	az.erase(az.begin(),az.begin()+n);
	bz.erase(bz.begin(),bz.begin()+n);
	for(int &i:az)
		i=min(i,n-1);
	for(int &i:bz)
		i=min(i,n-1);
	for(int i=0; i<m; i++)
		pola[az[i]]++;
	rep(i,0,m)
		polb[bz[i]]++;
	int ans=0;
	for(int i=n; i>0; i--) {
		pola[i-1]+=pola[i];
		polb[i-1]+=polb[i];
	}
	rep(i,1,n)
		ans+=pola[i]*polb[n-i];
	trace(ans);
	reverse(all(bz));
	trace(bz);
	trace(az);
	for(int i=n-1; i<m; i++) {
		update(bz[i],bz[i],1);
	}
	for(int i=0; i+n<=m; i++) {
		auto pol=qur(n-az[i]);
		ans-=pol.fi-(n-az[i]-1)*pol.se;
		trace(pol,ans,pol.fi-(n-az[i]-1)*pol.se,n-az[i]-1);
		update(bz[i+n-1],-bz[i+n-1],-1);
	}
	trace(ans);
	memset(tr11,0,sizeof(tr11));
	memset(tr2,0,sizeof(tr2));
	for(int i=0; i<m; i++) {
		auto pol=qur(n-az[i]);
		ans-=pol.fi-(n-az[i]-1)*pol.se;
		update(bz[i],bz[i],1);
	}
	trace(ans);
	cout<<ans<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}