/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
const lli MOD = 1000000007L-1;
const lli SZ = 6L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    lli a[10];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .


lli add(lli a, lli b)
{
	lli res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

lli mult(lli a, lli b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}

struct matrix
{
	lli arr[SZ][SZ];

	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}

	void makeiden()
	{
		reset();
		for(lli i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const
	{
		matrix res;
		for(lli i=0;i<SZ;i++)
		{
			for(lli j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const
	{
		matrix res;
		for(lli i=0;i<SZ;i++)
		{
			for(lli j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(lli k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

lli G=5;

matrix power(matrix a, lli b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

lli po(lli a,lli n=mod-2)
{
    if(n==0)
        return 1;
    if(n&1)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

lli solve(lli a, lli b, lli m) {
    lli n = (lli) sqrt (m + .0) + 1;

    lli an = 1;
    for (lli i = 0; i < n; ++i)
        an = (an * a) % m;

    map<lli, lli> vals;
    for (lli p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (lli q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            lli ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n>>a[1]>>a[2]>>a[3]>>k;
    x=solve(G,k,mod)%MOD;

    dbg(G,x,po(G,x));
    repA(i,1,3)
        a[i]=solve(G,a[i],mod)%MOD;

    a[4]=solve(G,po(k,2),mod)%MOD;
    a[5]=solve(G,po(k,mod-4),mod)%MOD;
    dbg(a[1],a[2],a[3],a[4],a[5]);

    matrix ans;
    ans.reset();
    ans.arr[1][1]=ans.arr[1][2]=ans.arr[1][3]=1;
    ans.arr[1][4]=(2*x)%MOD;//2;
    ans.arr[1][5]=MOD+(-4*x)%MOD;//-4;
    ans.arr[2][1]=ans.arr[3][2]=1;
    ans.arr[4][4]=ans.arr[4][5]=1;
    ans.arr[5][5]=1;

    ans=power(ans,n-3);
    cnt+=(ans.arr[1][1]*a[3])%MOD;
    cnt+=(ans.arr[1][2]*a[2])%MOD;
    cnt+=(ans.arr[1][3]*a[1])%MOD;
    cnt+=(ans.arr[1][4]*3)%MOD;
    cnt+=(ans.arr[1][5])%MOD;
    cnt%=MOD;

    cnt=po(G,cnt);
    cout<<cnt<<endl;

}   aryanc403();
    return 0;
}