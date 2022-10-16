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
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=998244352;
typedef vector<int> vi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NN = 101;
class matrix{
public:
ll mat[NN][NN];
int r, c;
matrix(){
fr(i, 0, NN - 1)
fr(j, 0, NN - 1)
mat[i][j] = 0;
}
void setsize(int _r, int _c){ r = _r, c = _c; }
inline matrix operator * (const matrix &a){
assert(c == a.r);
matrix temp;
temp.setsize(r, a.c);
fr(i, 0, r - 1)
fr(j, 0, a.c - 1){
fr(k, 0, a.r - 1){
temp.mat[i][j] += (mat[i][k] * a.mat[k][j]) % mod;
if(temp.mat[i][j] >= mod)
temp.mat[i][j] -= mod;
}
}
return temp;
}
inline matrix operator + (const matrix &a){
assert(r == a.r && c == a.c);
matrix temp;
temp.setsize(r, c);
fr(i, 0, r - 1)
fr(j, 0, c - 1){
temp.mat[i][j] = mat[i][j] + a.mat[i][j] ;
if(temp.mat[i][j] >= mod)
	temp.mat[i][j] -= mod;
	}
	return temp;
	}
	inline matrix operator - (const matrix &a){
	assert(r == a.r && c == a.c);
	matrix temp;
	temp.setsize(r, c);
	fr(i, 0, r - 1)
	fr(j, 0, c - 1){
	temp.mat[i][j] = mat[i][j] - a.mat[i][j];
	if(temp.mat[i][j] < 0)
	temp.mat[i][j] += mod;
	}
	return temp;
	}
	inline void operator = (const matrix &a){
	fr(i, 0, r - 1)
	fr(j, 0, c - 1)
	mat[i][j] = a.mat[i][j];
	r = a.r, c = a.c;
	}
};
	matrix pow(matrix a,ll k){
	assert(a.r == a.c);
	matrix ans;
	fr(i, 0, a.r - 1)
	ans.mat[i][i] = 1;
	ans.r = a.r;
	ans.c = a.r;
	while(k){
	if(k & 1)
	ans = ans * a;
	a = a * a;
	k >>= 1;
	}
	return ans;
	}
int solve (int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    int an = 1;
    for (int i=0; i<n; ++i)
        an = (an * a) % m;

    map<int,int> vals;
    for (int i=1, cur=an; i<=n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }

    for (int i=0, cur=b; i<=n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}
ll powm(ll a, ll b, ll m){
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
int b[205];
int a[3000000];
int dd, xd, yd;
void egcd(int A, int B) {
if(B == 0) { dd = A; xd = 1; yd = 0; }
else {
egcd(B, A % B);
int temp = xd; xd = yd; yd = temp - (A / B) * yd;
}}
int inv(int a,int m){
if(__gcd(a,m)!=1)
	return -1;
egcd(a, m); return (xd % m + m) % m; }
void solve()
{
	int k;
	cin>>k;
	for(int i=1; i<=k; i++)
		cin>>b[i];
	for(int i=1; i<k; i++)
		a[i]=0;
	a[k]=1;
	int n,m;
	cin>>n>>m;
	for(int i=k+1; i<2*k; i++)
		for(int j=1; j<=k; j++)
			a[i]=(a[i]+b[j]*a[i-j])%mod;
	if(m==1)
	{
		cout<<1<<endl;
		return;
	}
	ll hola=solve(3,m,998244353);
	ll hol;
	if(hola==-1) {
		cout<<hola;
		return;
	}
	else if(n<2*k) {
		hol=a[n];
	}
	else {
		matrix ma;
		ma.setsize(k, k);
		for(int i=0; i<k; i++)
			ma.mat[0][i]=b[i+1];
		for(int i=1; i<k; i++)
			ma.mat[i][i-1]=1;
		matrix ho=pow(ma,n-k);
		hol=ho.mat[0][0];
	}
	ll telo=__gcd(hola,hol);
	hola/=telo;
	hol/=telo;
	if(inv(hol,mod)==-1)
	{
		cout<<-1<<endl;
		return;
	}
	ll temp=(hola*inv(hol,mod))%mod;
	if(temp==-1)
		cout<<-1<<endl;
	else
		cout<<powm(3,temp,998244353);
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