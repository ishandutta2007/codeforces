#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((1ULL))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

uint64 cache[64][64];
uint64 multiply(uint64 a,uint64 b);
int is_cached[64][64];

uint64 multiply_powers_of_2(int pa,int pb)
{
	if (is_cached[pa][pb]) return cache[pa][pb];
	uint64& ret=cache[pa][pb];
	is_cached[pa][pb]=1;
	if (pa==0 || pb==0) return ret=twoL(pa+pb);
	int pn=1;
	for (;pn*2<=max(pa,pb);pn*=2);
	if (pa>=pn && pb>=pn)
		return ret=multiply(twoL(pn)*3/2,multiply_powers_of_2(pa-pn,pb-pn));
    else if (pa>=pn)
        return ret=(multiply_powers_of_2(pa-pn,pb)<<pn);
	else
        return ret=(multiply_powers_of_2(pa,pb-pn)<<pn);
}
uint64 multiply(uint64 a,uint64 b)
{
	uint64 ans=0;
	REP(i,64) if (containL(a,i))
		REP(j,64) if (containL(b,j))
			ans^=multiply_powers_of_2(i,j);
	return ans;
}
uint64 fast_power(uint64 p,uint64 e);

const uint64 M=-1;
const int LENGTH=10000;

struct Solver
{
	int m;
	uint64 seed;
	uint64 big_step;
	unordered_map<uint64,int> idx;

	int log(uint64 x)
	{
		uint64 y=fast_power(x,M/m);
		int ret=0;
		while (1)
		{
			if (idx.count(y)) return ((ret+idx[y])%m+m)%m;
			y=multiply(y,big_step);
			ret-=LENGTH;
		}
	}
	void init(int _m)
	{
		m=_m;
		seed=fast_power(M,M/m);
		big_step=fast_power(seed,LENGTH);
		uint64 p=1;
		REP(i,LENGTH)
		{
			if (idx.count(p)) break;
			idx[p]=i;
			p=multiply(p,seed);
		}
	}
};

vector<int> mods;
map<int,Solver> solvers;

void prepare()
{
	for (uint64 n=M,p=2;n>1;)
	{
		for (;n%p==0;n/=p) mods.push_back(p);
		++p;
		if (p>n/p) p=n;
	}
	for (int x:mods) solvers[x].init(x);

	memset(is_cached,0,sizeof(is_cached));
	REP(i,64) REP(j,64) multiply_powers_of_2(i,j);
	assert(multiply(4,4)==6);
	assert(multiply(8,8)==13);
	assert(multiply(32,64)==141);
	assert(multiply(5,6)==8);
}

uint64 fast_power(uint64 p,uint64 e)
{
	uint64 r=1;
	for (;e>0;e/=2)
	{
		if (e&1) r=multiply(r,p);
		p=multiply(p,p);
	}
	return r;
}

VI solve(uint64 n)
{
	VI ret;
	for (int m:mods) ret.push_back(solvers[m].log(n));
	return ret;
}

int64 MUL_AND_MOD(int64 a,int64 b,int64 m)
{
	a%=m; b%=m;
	if (a>b) return MUL_AND_MOD(b,a,m);
	if (a==0) return 0;
	int64 r=MUL_AND_MOD(a>>1,b,m);
	r=(r+r>=m?r+r-m:r+r);
	if (a&1) r=(r>=m-b?r+b-m:r+b);
	return r;
}
int64 inverse(int64 x,int64 m)
{
	x%=m;
	return (x<=1)?x:(m-MUL_AND_MOD(m/x,inverse(m%x,m),m));
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	prepare();
	for (cin>>testcase;testcase>0;testcase--)
	{
		uint64 x,y;
		cin>>x>>y;
		VI lx=solve(x);
		VI ly=solve(y);
		int ok=1;
		REP(i,SIZE(mods))
			if (lx[i]==0)
			{
				if (ly[i]!=0) { ok=0; break; }
			}
			else
			{
				ly[i]=MUL_AND_MOD(ly[i],inverse(lx[i],mods[i]),mods[i]);
			}
		if (ok)
		{
			uint64 m=1;
			uint64 d=0;
			REP(i,SIZE(mods))
			{
				uint64 d2=ly[i];
				uint64 m2=mods[i];
				int64 t=inverse(m,m2);
				int64 x=(MUL_AND_MOD(d2,t,m2)-MUL_AND_MOD(d,t,m2)+m2)%m2;
				d+=(uint64)x*m;
				m*=m2;
			}
			cout<<d<<endl;
			// cout<<fast_power(x,d)<<" v.s. "<<y<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}