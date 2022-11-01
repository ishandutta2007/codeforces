#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

template<typename ModWrapper>
class Modular
{
public:
	using base_type = typename decay<decltype(ModWrapper::value)>::type;

	base_type n;

	Modular(long long d = 0) { n = (d >= 0 ? d % mod() : (d % mod() + mod()) % mod()); }

	static base_type mod() { return ModWrapper::value; }
	base_type val() const { return n; }

	Modular operator-() const { return build(n == 0 ? 0 : mod() - n); }
	Modular& operator+=(Modular a) { n = (n >= mod() - a.n ? n - mod() + a.n : n + a.n); return *this; }
	Modular& operator-=(Modular a) { n = (n >= a.n) ? n - a.n : n - a.n + mod(); return *this; }
	Modular& operator*=(Modular a) { *this = *this * a; return *this; }
	Modular& operator/=(Modular a) { *this = *this / a; return *this; }

	static Modular build(base_type n) { Modular r; r.n = n; return r; }

	friend Modular inverse(Modular n) { return build(inverse_internal(n.n)); }
	friend bool operator==(Modular a, Modular b) { return a.n == b.n; }
	friend bool operator!=(Modular a, Modular b) { return a.n != b.n; }
	friend Modular operator+(Modular a, Modular b) { return build(a.n >= mod() - b.n ? a.n - mod() + b.n : a.n + b.n); }
	friend Modular operator-(Modular a, Modular b) { return build(a.n >= b.n ? a.n - b.n : a.n - b.n + mod()); }
	friend Modular operator*(Modular a, Modular b) { return build(static_cast<base_type>(static_cast<long long>(a.n)* b.n% mod())); }
	friend Modular operator/(Modular a, Modular b) { return a * inverse(b); }
	friend Modular pow(Modular p, long long e)
	{
		if (e <= 0) return Modular(1);
		Modular r = Modular(1);
		while (1) { if (e & 1) r *= p; e /= 2; if (e) p = p * p; else break; }
		return r;
	}

	friend istream& operator>>(istream& stream, Modular& a) { stream >> a.n; return stream; }
	friend ostream& operator<<(ostream& stream, const Modular& a) { stream << a.n; return stream; }

private:
	static constexpr int INVERSE_CACHE_SIZE = (1 << 18);
	static base_type inverse_cache[INVERSE_CACHE_SIZE];
	static base_type inverse_cache_mod_value;
	static base_type inverse_internal(base_type n)
	{
		if (inverse_cache_mod_value != mod())
		{
			inverse_cache_mod_value = mod();
			inverse_cache[0] = 0;
			inverse_cache[1] = 1;
			for (int n = 2; n < INVERSE_CACHE_SIZE; ++n) inverse_cache[n] = (mod() - (base_type)((long long)inverse_cache[mod() % n] * (mod() / n) % mod()));
		}
		return n < INVERSE_CACHE_SIZE ? inverse_cache[n] : inverse_internal_large(n);
	}
	static base_type inverse_internal_large(base_type n)
	{
		return n < INVERSE_CACHE_SIZE ? inverse_cache[n] : mod() - (base_type)((long long)inverse_internal_large(mod() % n) * (mod() / n) % mod());
	}
};
template<typename ModWrapper> typename decay<decltype(ModWrapper::value)>::type Modular<ModWrapper>::inverse_cache[INVERSE_CACHE_SIZE];
template<typename ModWrapper> typename decay<decltype(ModWrapper::value)>::type Modular<ModWrapper>::inverse_cache_mod_value = -1;

#define MOD (1000000007)

using ModType = int;
struct ModWrapper {
	static ModType value;
};
ModType ModWrapper::value = MOD;
ModType& mod_value = ModWrapper::value;

using Int = Modular<ModWrapper>;



Int solve(int n)
{
	int m,L;
	cin>>m;
	cin>>L;
	VI x(n),y(n),c(n);
	REP(i,n) { cin>>x[i]>>y[i]>>c[i]; --c[i]; }
	set<int> sx(ALL(x)),sy(ALL(y));	
	sx.insert(L);
	sy.insert(L);
	VI lx(ALL(sx)),ly(ALL(sy));
	map<int,int> mx,my;	
	REP(i,SIZE(lx)) mx[lx[i]]=i;
	REP(i,SIZE(ly)) my[ly[i]]=i;
	int cx=SIZE(lx)-1;
	int cy=SIZE(ly)-1;
	REP(i,n) x[i]=mx[x[i]],y[i]=my[y[i]];
	auto prevL=[&](const VI& l,int idx) -> Int { return l[idx]-(idx==0?-1:l[idx-1]); };
	auto nextL=[&](const VI& l,int idx) -> Int { return l[idx+1]-l[idx]; };
	vector<VI> gx(cx);
	REP(i,n) gx[x[i]].push_back(i);
	vector<multiset<int>> gc(m);
	Int ret=0;
	REP(x1,cx)
	{
		REP(i,m) gc[i].clear();
		REP(i,n) if (x[i]>=x1) gc[c[i]].insert(y[i]);
		map<int,int> pts;
		pts[-1]=0;
		pts[L]=L+1;
		Int sum=0;
		auto eval=[&](ipair a,ipair b) -> Int {
			return (Int)(a.second)*(Int)(b.first-a.first);
		};
		auto add=[&](int s_idx,int val_idx) {
			int s=(s_idx==0?0:ly[s_idx-1]+1);
			if (s>=L) return;
			int val=ly[val_idx];
			if ((--pts.upper_bound(s))->second>=val) return;
			while (1)
			{
				auto it=pts.lower_bound(s);
				if (it->second>val) break;
				auto it1=it; --it1;
				auto it2=it; ++it2;
				sum-=eval(*it1,*it);
				sum-=eval(*it,*it2);
				sum+=eval(*it1,*it2);
				pts.erase(it);
			}
			{
				auto it2=pts.upper_bound(s);
				auto it1=it2; --it1;
				sum-=eval(*it1,*it2);
				sum+=eval(*it1,MP(s,val));
				sum+=eval(MP(s,val),*it2);
				pts[s]=val;
			}
		};
		REP(i,m) 
		{
			VI a(ALL(gc[i]));
			if (a.empty())
				add(0,cy);
			else
			{
				add(0,a[0]);
				add(a.back()+1,cy);
				REP(i,SIZE(a)-1) add(a[i]+1,a[i+1]);
			}
		}
		for (int x2=cx-1;x2>=x1;x2--)
		{
			ret+=((Int)L*(int)L-sum)*prevL(lx,x1)*nextL(lx,x2);
			if (x2>x1)
				for (int idx:gx[x2])
				{
					int y0=y[idx];
					int c0=c[idx];
					gc[c0].erase(gc[c0].find(y0));
					auto it=gc[c0].lower_bound(y0);
					if (it!=gc[c0].end() && *it==y0) continue;
					int next=(it==gc[c0].end()?cy:*it);
					int prev=-1;
					if (it!=gc[c0].begin()) { --it; prev=*it; }
					add(prev+1,next);
				}
		}
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		Int ret=solve(n);
		printf("%d\n",ret.n);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}