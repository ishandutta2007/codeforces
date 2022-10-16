#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


const int N=55;
int dp[N][N][N][4];
vi sg[4];
int knap[4][N][N*N];
int fact[N];
int inpe[N];
int answ[N][N][N*N];
struct base{
    f80 x,y;
    base(){x=y=0;}
    base(f80 _x, f80 _y){x = _x,y = _y;}
    base(f80 _x){x = _x, y = 0;}
    void operator = (f80 _x){x = _x,y = 0;}
    f80 real(){return x;}
    f80 imag(){return y;}
    base operator + (const base& b){return base(x+b.x,y+b.y);}
    void operator += (const base& b){x+=b.x,y+=b.y;}
    base operator * (const base& b){return base(x*b.x - y*b.y,x*b.y+y*b.x);}
    void operator *= (const base& b){f80 p = x*b.x - y*b.y, q = x*b.y+y*b.x; x = p, y = q;}
    void operator /= (f80 k){x/=k,y/=k;}
    base operator - (const base& b){return base(x - b.x,y - b.y);}
    void operator -= (const base& b){x -= b.x, y -= b.y;}
    base conj(){ return base(x, -y);}
    base operator / (f80 k) { return base(x / k, y / k);}
    void Print(){ cerr << x <<  " + " << y << "i\n";}
};
double PI = 2.0*acosl(0.0);
const int MAXN = 14;
const int maxn = (1<<MAXN);
base W[maxn],invW[maxn], P1[maxn], Q1[maxn];
void precompute_powers(){
    for(int i = 0;i<maxn/2;i++){
        double ang = (2*PI*i)/maxn;
        f80 _cos = cos(ang), _sin = sin(ang);
        W[i] = base(_cos,_sin);
        invW[i] = base(_cos,-_sin);
    }
}
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            int ind = 0,add = maxn/len;
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = (a[i+j+len/2] * (invert?invW[ind]:W[ind]));
                a[i+j] = (u + v);
                a[i+j+len/2] = (u - v);
                ind += add;
            }
        }
    }
    if (invert) for (int i=0; i<n; ++i) a[i] /= n;
}

// 4 FFTs in total for a precise convolution
void mul_big_mod(vector<ll> &a, vector<ll> & b, ll mod){
    int n1 = a.size(),n2 = b.size();
    int final_size = a.size() + b.size() - 1;
    int n = 1;
    while(n < final_size) n <<= 1;
    vector<base> P(n), Q(n);
    int SQRTMOD = (int)sqrt(mod) + 10;
    for(int i = 0;i < n1;i++) P[i] = base(a[i] % SQRTMOD, a[i] / SQRTMOD);
    for(int i = 0;i < n2;i++) Q[i] = base(b[i] % SQRTMOD, b[i] / SQRTMOD);
    fft(P, 0);
    fft(Q, 0);
    base A1, A2, B1, B2, X, Y;
    for(int i = 0; i < n; i++){
        X = P[i];
        Y = P[(n - i) % n].conj();
        A1 = (X + Y) * base(0.5, 0);
        A2 = (X - Y) * base(0, -0.5);
        X = Q[i];
        Y = Q[(n - i) % n].conj();
        B1 = (X + Y) * base(0.5, 0);
        B2 = (X - Y) * base(0, -0.5);
        P1[i] = A1 * B1 + A2 * B2 * base(0, 1);
        Q1[i] = A1 * B2 + A2 * B1;
    }
    for(int i = 0; i < n; i++) P[i] = P1[i], Q[i] = Q1[i];
    fft(P, 1);
    fft(Q, 1);
    a.resize(final_size);
    for(int i = 0; i < final_size; i++){
        ll x = (ll)(P[i].real() + 0.5);
        ll y = (ll)(P[i].imag() + 0.5) % mod;
        ll z = (ll)(Q[i].real() + 0.5);
        a[i] = (x + ((y * SQRTMOD + z) % mod) * SQRTMOD) % mod;
    }
}

void solve() {
	precompute_powers();
	fact[0]=1;
	for(int i=1; i<N; i++)
		fact[i]=(fact[i-1]*i)%mod;
	dp[0][0][0][0]=1;
	for(int i=0; i<=50; i++)
		for(int j=0; j<=50; j++)
			for(int k=0; k<=50; k++) {
				for(int l=0; l<=3; l++)
					if(l!=1) {
						dp[i+1][j][k][1]+=dp[i][j][k][l];
						dp[i+1][j][k][1]%=mod;
					}
				for(int l=0; l<=3; l++)
					if(l!=2) {
						dp[i][j+1][k][2]+=dp[i][j][k][l];
						dp[i][j+1][k][2]%=mod;
					}
				for(int l=0; l<=3; l++)
					if(l!=3) {
						dp[i][j][k+1][3]+=dp[i][j][k][l];
						dp[i][j][k+1][3]%=mod;
					}
			}
	int n,t;
	cin>>n>>t;
	fr(i,1,n) {
		int ti,gi;
		cin>>ti>>gi;
		sg[gi].pb(ti);
	}
	for(int j=1; j<=3; j++) {
		knap[j][0][0]=1;
		for(int i:sg[j]) {
			for(int l=sz(sg[j])-1; l>=0; l--)
				for(int k=t-i; k>=0; k--) {
					knap[j][l+1][k+i]+=knap[j][l][k];
					knap[j][l+1][k+i]%=mod;
				}
		}
	}
	for(int i=1; i<=3; i++)
		for(int j=0; j<=sz(sg[i]); j++)
			for(int k=0; k<=t; k++)
				knap[i][j][k]=(knap[i][j][k]*fact[j])%mod;
	int ans=0;
	if(sz(sg[1])>sz(sg[3])) {
		swap(sg[1],sg[3]);
		swap(knap[1],knap[3]);
	}
	if(sz(sg[2])>sz(sg[3])) {
		swap(sg[2],sg[3]);
		swap(knap[2],knap[3]);
	}
	vector<ll> ho1(t+1),ho2(t+1),res;
	for(int i=0; i<=sz(sg[1]); i++) {
		for(int j=0; j<=sz(sg[2]); j++) {
			ho1.resize(t+1);
			for(int k=0; k<=t; k++) {
				ho1[k]=knap[1][i][k];
				ho2[k]=knap[2][j][k];
			}
			mul_big_mod(ho1, ho2, mod);
			for(int k=0; k<=t; k++)
				answ[i][j][k]=ho1[k];
		}
	}
	for(int i=0; i<=sz(sg[1]); i++) {
		for(int j=0; j<=sz(sg[2]); j++) {
			for(int k=0; k<=sz(sg[3]); k++) {
				for(int l=0; l<=t; l++) {
					int o=t-l;
					int te=dp[i][j][k][0]+dp[i][j][k][1]+dp[i][j][k][2]+dp[i][j][k][3];
					te=(te*answ[i][j][l])%mod;
					ans=(ans+te*knap[3][k][o])%mod;
				}
			}
		}
	}
	cout<<ans<<endl;

}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}